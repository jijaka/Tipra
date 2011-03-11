#pragma once
#ifndef _TPR_DAEMON_THREAD_INFO_
#define _TPR_DAEMON_THREAD_INFO_

#include <Windows.h>

class TPR_Daemon_ThreadInfo
{
	HANDLE m_hPrinter;
    HANDLE m_hEventStopRequested;
    HANDLE m_hEventThreadDone;

public:
	TPR_Daemon_ThreadInfo()
	{
		m_hPrinter            = INVALID_HANDLE_VALUE;
        m_hEventStopRequested = INVALID_HANDLE_VALUE;
        m_hEventThreadDone    = INVALID_HANDLE_VALUE;
	}
	
	//================================================================

    HANDLE GetPrinter( void ) const
    {
        return m_hPrinter;
    }

    HANDLE GetStopRequestedEvent( void ) const
    {
        return m_hEventStopRequested;
    }

    HANDLE GetThreadDoneEvent( void ) const
    {
        return m_hEventThreadDone;
    }

	//================================================================

    void SetPrinter( const HANDLE hPrinter )
    {
        m_hPrinter = hPrinter;
    }

    void SetStopRequestedEvent( LPCSTR strStopEventName )
	{
        m_hEventStopRequested = OpenEvent ( EVENT_ALL_ACCESS , false, strStopEventName);
    }

    void SetThreadDoneEvent( LPCSTR strDoneEventName )
    {
        m_hEventThreadDone = OpenEvent ( EVENT_ALL_ACCESS , false, strDoneEventName);
    }
};

#endif //_TPR_DAEMON_THREAD_INFO_
