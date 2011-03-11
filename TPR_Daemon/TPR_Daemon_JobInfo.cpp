#include "TPR_Daemon_JobInfo.h"

TPR_Daemon_JobInfo::TPR_Daemon_JobInfo( const int nJobId )
{
	m_nJobId              = nJobId;       
    m_timeSubmitted.wHour = USHRT_MAX; // just some invalid value
    m_nTotalPages         = 0;
    m_nPagesPrinted       = 0;
    m_nTotalBytes         = 0;
    m_nBytesPrinted       = 0;

	if (m_mapJobStatus.empty())
    {
        m_mapJobStatus[JOB_STATUS_BLOCKED_DEVQ] = "The driver cannot print the job.";
        m_mapJobStatus[JOB_STATUS_COMPLETE] = "Job is sent to the printer, but the job may not be printed yet.";
        m_mapJobStatus[JOB_STATUS_DELETED] = "Job has been deleted.";
        m_mapJobStatus[JOB_STATUS_DELETING] = "Job is being deleted.";
        m_mapJobStatus[JOB_STATUS_ERROR] = "An error is associated with the job.";
        m_mapJobStatus[JOB_STATUS_OFFLINE] = "Printer is offline.";
        m_mapJobStatus[JOB_STATUS_PAPEROUT] = "Printer is out of paper.";
        m_mapJobStatus[JOB_STATUS_PAUSED] = "Job is paused.";
        m_mapJobStatus[JOB_STATUS_PRINTED] = "Job has printed.";
        m_mapJobStatus[JOB_STATUS_PRINTING] = "Job is printing.";
        m_mapJobStatus[JOB_STATUS_RESTART] = "Job has been restarted.";
        m_mapJobStatus[JOB_STATUS_SPOOLING] = "Job is spooling.";
        m_mapJobStatus[JOB_STATUS_USER_INTERVENTION] = "Printer has an error that requires the user to do something.";
    }
}

std::map<int, tstring> TPR_Daemon_JobInfo::m_mapJobStatus;

//=================================================================

void TPR_Daemon_JobInfo::UpdateInfo( const PPRINTER_NOTIFY_INFO_DATA pNotifyData )
{
    if (pNotifyData->Field == JOB_NOTIFY_FIELD_USER_NAME)
        m_strUser.assign( (LPCTSTR) pNotifyData->NotifyData.Data.pBuf );
	else if (pNotifyData->Field == JOB_NOTIFY_FIELD_MACHINE_NAME)
        m_strMachine.assign((LPCTSTR) pNotifyData->NotifyData.Data.pBuf );
    else if (pNotifyData->Field == JOB_NOTIFY_FIELD_PORT_NAME)
		m_strPort.assign( (LPCTSTR) pNotifyData->NotifyData.Data.pBuf );
    else if (pNotifyData->Field == JOB_NOTIFY_FIELD_DOCUMENT)
        m_strDocument.assign( (LPCTSTR) pNotifyData->NotifyData.Data.pBuf );
    else if (pNotifyData->Field == JOB_NOTIFY_FIELD_SUBMITTED)
        m_timeSubmitted = *((SYSTEMTIME *) pNotifyData->NotifyData.Data.pBuf);
    else if (pNotifyData->Field == JOB_NOTIFY_FIELD_PAGES_PRINTED)
        m_nPagesPrinted = pNotifyData->NotifyData.adwData[0];
    else if (pNotifyData->Field == JOB_NOTIFY_FIELD_TOTAL_PAGES)
        m_nTotalPages = pNotifyData->NotifyData.adwData[0];
    else if (pNotifyData->Field == JOB_NOTIFY_FIELD_BYTES_PRINTED)
        m_nBytesPrinted = pNotifyData->NotifyData.adwData[0];
    else if (pNotifyData->Field == JOB_NOTIFY_FIELD_TOTAL_BYTES)
        m_nTotalBytes = pNotifyData->NotifyData.adwData[0];
    else if (pNotifyData->Field == JOB_NOTIFY_FIELD_STATUS)
        m_nStatus = pNotifyData->NotifyData.adwData[0]; 
    else if (pNotifyData->Field == JOB_NOTIFY_FIELD_STATUS_STRING)
        ;
    else
		OutputDebugStringA("Unhandled job field");
}

//=================================================================

int TPR_Daemon_JobInfo::GetJobId( void ) const
{
    return m_nJobId;
}

std::string TPR_Daemon_JobInfo::GetUser( void ) const
{
	return m_strUser;
}

std::string TPR_Daemon_JobInfo::GetMachine( void ) const
{
    return m_strMachine;
}

std::string TPR_Daemon_JobInfo::GetPort( void ) const
{
    return m_strPort;
}

std::string TPR_Daemon_JobInfo::GetDocument( void ) const
{
    return m_strDocument;
}

SYSTEMTIME TPR_Daemon_JobInfo::GetTimeSubmitted( void ) const
{
    return m_timeSubmitted;
}

int TPR_Daemon_JobInfo::GetTotalPages( void ) const
{
    return m_nTotalPages;
}

int TPR_Daemon_JobInfo::GetPagesPrinted( void ) const
{
    return m_nPagesPrinted;
}

int TPR_Daemon_JobInfo::GetTotalBytes( void ) const
{                
    return m_nTotalBytes;
}

int TPR_Daemon_JobInfo::GetBytesPrinted( void ) const
{
    return m_nBytesPrinted;
}

std::string TPR_Daemon_JobInfo::GetStatus( void ) const
{
    return m_mapJobStatus[m_nStatus];
}
