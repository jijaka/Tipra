#pragma once
#ifndef _TPR_DAEMON_JOB_INFO_
#define _TPR_DAEMON_JOB_INFO_

#include <Windows.h>
#include <map>
#include <string>

class TPR_Daemon_JobInfo
{
public:
	TPR_Daemon_JobInfo( const int nJobId );

	//=================================================================

    int GetJobId( void ) const;
    LPCTSTR GetUser( void ) const;
    LPCTSTR GetMachine( void ) const;
    LPCTSTR GetPort( void ) const;
    LPCTSTR GetDocument( void ) const;
    SYSTEMTIME GetTimeSubmitted( void ) const;
    int GetTotalPages( void ) const;
    int GetPagesPrinted( void ) const;
    int GetTotalBytes( void ) const;
    int GetBytesPrinted( void ) const;
    LPCTSTR GetStatus( void ) const;

	//=================================================================
    
    void UpdateInfo( const PPRINTER_NOTIFY_INFO_DATA pNotifyData );

private:
	static std::map<int, LPCTSTR> m_mapJobStatus;    

    int m_nJobId;
	LPCTSTR m_strUser;
	LPCTSTR m_strMachine;
    LPCTSTR m_strPort;
    LPCTSTR m_strDocument;
    SYSTEMTIME m_timeSubmitted;
    int m_nTotalPages;
    int m_nPagesPrinted;
    int m_nTotalBytes;
    int m_nBytesPrinted;
    int m_nStatus;
};

#endif //_TPR_DAEMON_JOB_INFO_