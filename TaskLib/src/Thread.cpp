/**********************************************************************
 * @特别声明
 *     本段代码由liuk创建，所有通过正常途径获取此文件的开发人员
 * 均可任意修改、增加及删除文件内容，但请保留此声明。
 *     如有疑问请联系作者。
 * @特别声明结束
 ********************************************************************/

/**
 * @file	: Thread.cpp
 * @brief	: 线程实现
 * @author	: liuk
 * @date	: 2016/12/18 17:03:16
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */
#include "Thread.h"
#include <process.h>

typedef unsigned(__stdcall * StartRoutine)(void * param);

CThread::CThread():m_hThread(0)
#ifdef WIN32
, m_unThreadAddress(0)
#endif
, m_bRunning(false)
, m_bQuit(true)
, m_bPause(false)
{
#ifdef WIN32
	m_hThread = NULL;
	
#endif // WIN32
	
}


CThread::~CThread()
{
}

bool CThread::Active()
{
	m_bPause = false;
#ifdef WIN32
	if (!m_bRunning)
	{
		m_hThread = _beginthreadex(NULL, 0, (StartRoutine)CThread::StartRun, this, CREATE_SUSPENDED, &m_unThreadAddress);
	}
	
	return (ResumeThread((HANDLE)m_hThread) != -1);
#endif
}

bool CThread::Pause()
{
	m_bPause = true;
#ifdef WIN32
	return (SuspendThread((HANDLE)m_hThread) != -1);
#endif
}

void CThread::Quit()
{
	m_bQuit = true;
}

void CThread::Continue()
{
	if (m_bPause)
	{
		ResumeThread((HANDLE)m_hThread);
		m_bPause = false;
	}
}

void CThread::Signal()
{
	m_hEvent.Signal();
}

E_WAIT_STATUS CThread::Wait(unsigned int nMillisecond /*= INFINITE*/)
{
	return m_hEvent.Wait(nMillisecond);

}

void CThread::Terminate(unsigned int nExitCode)
{
#ifdef WIN32
	TerminateThread((HANDLE)m_hThread, nExitCode);
	m_bQuit = true;
	m_bRunning = false;
	m_bPause = false;
#endif // WIN32
}

bool CThread::IsPause() const
{
	return m_bPause;
}

bool CThread::IsQuit() const
{
	return m_bQuit;
}

bool CThread::IsRunning() const
{
	return m_bRunning;
}

unsigned __stdcall CThread::StartRun(CThread * thread_ptr)
{
	
	thread_ptr->m_bQuit = false;
	thread_ptr->m_bRunning = true;
	thread_ptr->run();
	thread_ptr->m_bRunning = false; 
	thread_ptr->Signal();
	return 0;
}
