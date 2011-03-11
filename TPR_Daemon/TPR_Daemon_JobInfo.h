#pragma once
#ifndef _TPR_DAEMON_JOB_INFO_
#define _TPR_DAEMON_JOB_INFO_

#include <Windows.h>
#include <map>
#include <string>

typedef std::basic_string<TCHAR> tstring;

class TPR_Daemon_JobInfo
{
public:
	TPR_Daemon_JobInfo( const int nJobId );

	//=================================================================

    int GetJobId( void ) const;
    std::string GetUser( void ) const;
    std::string GetMachine( void ) const;
    std::string GetPort( void ) const;
    std::string GetDocument( void ) const;
    SYSTEMTIME GetTimeSubmitted( void ) const;
    int GetTotalPages( void ) const;
    int GetPagesPrinted( void ) const;
    int GetTotalBytes( void ) const;
    int GetBytesPrinted( void ) const;
    std::string GetStatus( void ) const;

	//=================================================================
    
    void UpdateInfo( const PPRINTER_NOTIFY_INFO_DATA pNotifyData );

private:
	static std::map<int, std::string> m_mapJobStatus;    

    int m_nJobId;
	std::string m_strUser;
	std::string m_strMachine;
    std::string m_strPort;
    std::string m_strDocument;
    SYSTEMTIME m_timeSubmitted;
    int m_nTotalPages;
    int m_nPagesPrinted;
    int m_nTotalBytes;
    int m_nBytesPrinted;
    int m_nStatus;
};

#endif //_TPR_DAEMON_JOB_INFO_