#pragma once
#ifndef _TPR_DAEMON_WATCHER_
#define _TPR_DAEMON_WATCHER_

#include <Windows.h>
#include <assert.h>
#include "TPR_Daemon_ThreadInfo.h"
#include "TPR_Daemon_JobInfo.h"

class TPR_Daemon_Watcher
{
public:
	TPR_Daemon_Watcher(LPCTSTR strPrinter);
	
	//================================================================
	
	DWORD ThreadFunc( void );

	//================================================================

	void Watch();
	void Stop();

private:
	LPCTSTR m_strPrinter;

	HANDLE m_hEventStopRequested;
	HANDLE m_hEventThreadDone;
	HANDLE m_hThread;
	TPR_Daemon_ThreadInfo m_ThreadInfo;

	std::map<int, TPR_Daemon_JobInfo*> m_mapJobInfo;
};

#endif //_TPR_DAEMON_WATCHER_