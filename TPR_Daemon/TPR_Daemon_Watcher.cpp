#include "TPR_Daemon_Watcher.h"

TPR_Daemon_Watcher::TPR_Daemon_Watcher(LPCTSTR strPrinter)
{
	m_strPrinter = strPrinter;

	m_hEventStopRequested = CreateEvent ( NULL , false , false , L"StopRequested" );
	m_hEventThreadDone = CreateEvent ( NULL , true , false , L"ThreadDone" );
}

DWORD WINAPI ThreadFunc(LPVOID lpParam) 
{
    TPR_Daemon_Watcher *pWatcher = (TPR_Daemon_Watcher *) lpParam;
    
    return pWatcher->ThreadFunc();
}

void TPR_Daemon_Watcher::Watch()
{
	DWORD dwThreadID;
	HANDLE hPrinter;

	ResetEvent(m_hEventStopRequested);
    ResetEvent(m_hEventThreadDone);
	
	OpenPrinter((LPTSTR) m_strPrinter, &hPrinter, NULL);

	m_ThreadInfo.SetPrinter(hPrinter);

	m_hThread = CreateThread(
            NULL,
            0,
            ::ThreadFunc,
            this,
            0,
            &dwThreadID); 
}

DWORD TPR_Daemon_Watcher::ThreadFunc( void )
{
	m_ThreadInfo.SetStopRequestedEvent("StopRequested");
	m_ThreadInfo.SetThreadDoneEvent("ThreadDone");

	PPRINTER_NOTIFY_INFO pNotification = NULL;

	WORD JobFields[] = 
    {
        JOB_NOTIFY_FIELD_PRINTER_NAME,
        JOB_NOTIFY_FIELD_MACHINE_NAME,
        JOB_NOTIFY_FIELD_PORT_NAME,
        JOB_NOTIFY_FIELD_USER_NAME,
        JOB_NOTIFY_FIELD_NOTIFY_NAME,
        JOB_NOTIFY_FIELD_DATATYPE,
        JOB_NOTIFY_FIELD_PRINT_PROCESSOR,
        JOB_NOTIFY_FIELD_PARAMETERS,
        JOB_NOTIFY_FIELD_DRIVER_NAME,
        JOB_NOTIFY_FIELD_DEVMODE,
        JOB_NOTIFY_FIELD_STATUS,
        JOB_NOTIFY_FIELD_STATUS_STRING,
        JOB_NOTIFY_FIELD_DOCUMENT,
        JOB_NOTIFY_FIELD_PRIORITY,
        JOB_NOTIFY_FIELD_POSITION,
        JOB_NOTIFY_FIELD_SUBMITTED,
        JOB_NOTIFY_FIELD_START_TIME,
        JOB_NOTIFY_FIELD_UNTIL_TIME,
        JOB_NOTIFY_FIELD_TIME,
        JOB_NOTIFY_FIELD_TOTAL_PAGES,
        JOB_NOTIFY_FIELD_PAGES_PRINTED,
        JOB_NOTIFY_FIELD_TOTAL_BYTES,
        JOB_NOTIFY_FIELD_BYTES_PRINTED
    };
	PRINTER_NOTIFY_OPTIONS_TYPE	Notifications[1] =					
    {
        {
            JOB_NOTIFY_TYPE,
            0,
            0,
            0,
            sizeof(JobFields) / sizeof(JobFields[0]),
            JobFields
        },
    };
	PRINTER_NOTIFY_OPTIONS NotificationOptions = 
    {
        2,
        PRINTER_NOTIFY_OPTIONS_REFRESH,
        sizeof(Notifications) / sizeof(Notifications[0]),
        Notifications
    };

    // get a handle to a printer change notification object.
    HANDLE hChange = FindFirstPrinterChangeNotification(m_ThreadInfo.GetPrinter(),
                                                        PRINTER_CHANGE_ALL,
                                                        0, 
                                                        &NotificationOptions);

    DWORD dwChange;
    HANDLE aHandles[2];
    aHandles[0] = hChange;
    aHandles[1] = m_ThreadInfo.GetStopRequestedEvent();

    while (hChange != INVALID_HANDLE_VALUE)
    {
        // sleep until a printer change notification wakes this thread or the
        // event becomes set indicating it's time for the thread to end.
        WaitForMultipleObjects(2, aHandles, FALSE, INFINITE);

        if (WaitForSingleObject(hChange, 0U) == WAIT_OBJECT_0)
        {
            FindNextPrinterChangeNotification(hChange, &dwChange, &NotificationOptions, (LPVOID *) &pNotification);

			if (pNotification != NULL)
            {
			    // if a notification overflow occurred,
			    if (pNotification->Flags & PRINTER_NOTIFY_INFO_DISCARDED)
			    {
				    DWORD dwOldFlags = NotificationOptions.Flags;
				    
				    // we must refresh to continue
				    NotificationOptions.Flags = PRINTER_NOTIFY_OPTIONS_REFRESH;

				    FreePrinterNotifyInfo(pNotification);

				    FindNextPrinterChangeNotification(hChange, &dwChange, &NotificationOptions, (LPVOID *) &pNotification);

				    NotificationOptions.Flags = dwOldFlags;
			    }

                // iterate through each notification
                for (DWORD x = 0; x < pNotification->Count; x++)
                {
                    assert(pNotification->aData[x].Type == JOB_NOTIFY_TYPE);

                    TPR_Daemon_JobInfo *pJobInfo = NULL;
					std::map<int, TPR_Daemon_JobInfo*>::iterator it = m_mapJobInfo.find(pNotification->aData[x].Id);

					if (m_mapJobInfo.find(pNotification->aData[x].Id) == m_mapJobInfo.end() )
                    //if ( m_mapJobInfo[pNotification->aData[x].Id] == NULL )
                    {
                        pJobInfo = new TPR_Daemon_JobInfo(pNotification->aData[x].Id);
                        m_mapJobInfo[pNotification->aData[x].Id] = pJobInfo;
                    } else {
						pJobInfo = m_mapJobInfo.find(pNotification->aData[x].Id)->second;
					}

                    assert(pJobInfo != NULL);
                    pJobInfo->UpdateInfo(&pNotification->aData[x]);

					
                    // TODO: Here must be data processing!!!
					printf("Sexy data process\n"); //!!!
                }
            }

			FreePrinterNotifyInfo(pNotification);
			pNotification = NULL;
        }
        else if (WaitForSingleObject(m_ThreadInfo.GetStopRequestedEvent(), 0U) == WAIT_OBJECT_0)
        {
			FindClosePrinterChangeNotification(hChange);
            hChange = INVALID_HANDLE_VALUE;
        }
    }

    // signal the event to let the primary thread know that this thread is done
    SetEvent(m_ThreadInfo.GetThreadDoneEvent());

    return 0;
}


void TPR_Daemon_Watcher::Stop()
{
	SetEvent(m_hEventStopRequested);
	WaitForSingleObject(m_hEventThreadDone, 8000U);

	if (m_ThreadInfo.GetPrinter() != INVALID_HANDLE_VALUE)
       ClosePrinter(m_ThreadInfo.GetPrinter());
}