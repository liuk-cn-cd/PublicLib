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
#include "ThreadPrivate.h"
#ifdef WIN32
#include <process.h>
typedef unsigned(__stdcall * StartRoutine)(void * param);
#elif linux
typedef void*(* StartRoutine)(void *);
#endif



CThread::CThread()
    : _data_(new CThreadPrivate)

{

	
}


CThread::~CThread()
{
    if(nullptr != _data_)
    {
        delete _data_;
        _data_ = nullptr;
    }
}

bool CThread::Active()
{
#ifdef WIN32
	_data_->m_bPause = false;
	if (!_data_->m_bRunning)
	{
        _data_->m_hThread = _beginthreadex(nullptr, 0, (StartRoutine)CThread::StartRun, this, CREATE_SUSPENDED, &_data_->m_unThreadAddress);
	}
	
    return (ResumeThread((HANDLE)_data_->m_hThread) != -1);
#elif linux
    if (!_data_->m_bRunning)
    {
        return (pthread_create(&_data_->m_hThread, nullptr, (StartRoutine)CThread::StartRun, this) == 0);
    }
#endif
}

#ifdef WIN32
bool CThread::Pause()
{
    _data_->m_bPause = true;

	return (SuspendThread((HANDLE)_data_->m_hThread) != -1);
}
#endif

void CThread::Quit()
{
    _data_->m_bQuit = true;
}
#ifdef WIN32
void CThread::Continue()
{

    if (_data_->m_bPause)
	{
        ResumeThread((HANDLE)_data_->m_hThread);
        _data_->m_bPause = false;
    }
}
#endif

void CThread::Signal()
{
    _data_->m_hEvent.Signal();
}

E_WAIT_STATUS CThread::Wait(uint32 nMillisecond /*= INFINITE*/)
{
    return _data_->m_hEvent.Wait(nMillisecond);

}

void CThread::Terminate(uint32 nExitCode)
{
#ifdef WIN32
    TerminateThread((HANDLE)_data_->m_hThread, nExitCode);
    _data_->m_bQuit = true;
    _data_->m_bRunning = false;
    _data_->m_bPause = false;
#elif linux
    pthread_cancel(_data_->m_hThread);
    _data_->m_bQuit = true;
    _data_->m_bRunning = false;
#endif // WIN32
}

#ifdef WIN32
bool CThread::IsPause() const
{
    return _data_->m_bPause;
}
#endif
bool CThread::IsQuit() const
{
    return _data_->m_bQuit;
}

bool CThread::IsRunning() const
{
    return _data_->m_bRunning;
}

#ifdef WIN32
unsigned __stdcall CThread::StartRun(CThread * thread_ptr)
{
	
    thread_ptr->_data_->m_bQuit = false;
    thread_ptr->_data_->m_bRunning = true;
    thread_ptr->run();
    thread_ptr->_data_->m_bRunning = false;
    thread_ptr->Signal();
	return 0;
}
#elif linux
void* CThread::StartRun(CThread *thread_ptr)
{
    int oldstate;
    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, &oldstate);
    thread_ptr->_data_->m_bQuit = false;
    thread_ptr->_data_->m_bRunning = true;
    thread_ptr->run();
    thread_ptr->_data_->m_bRunning = false;
    thread_ptr->Signal();
    thread_ptr->_data_->m_bQuit = true;
}
#endif
