/**********************************************************************
 * @特别声明
 *     本段代码由liuk创建，所有通过正常途径获取此文件的开发人员
 * 均可任意修改、增加及删除文件内容，但请保留此声明。
 *     如有疑问请联系作者。
 * @特别声明结束
 ********************************************************************/
/**
 * @file	: ThreadEvent.cpp
 * @brief	: 线程事件实现函数
 * @author	: liuk
 * @date	: 2016/12/24 10:48:52
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */
#include "ThreadEvent.h"

#ifdef linux
#include <sys/time.h>
#endif //linux

#ifdef WIN32
CThreadEvent::CThreadEvent(bool bInitEvent)
{
    m_hEvent = CreateEvent(nullptr, FALSE, bInitEvent ? TRUE : FALSE, nullptr);
}
#elif linux
CThreadEvent::CThreadEvent()
{
    pthread_cond_init(&m_hEvent, nullptr);
    pthread_mutex_init(&m_hMutex, nullptr);
}

#endif

CThreadEvent::~CThreadEvent()
{
#ifdef WIN32
	ResetEvent(m_hEvent);
#elif linux
    pthread_mutex_destroy(&m_hMutex);
    pthread_cond_destroy(&m_hEvent);
#endif // WIN32
}

E_WAIT_STATUS CThreadEvent::Wait(uint32 nMillisecond /*= INFINITE*/)
{
#ifdef WIN32
	return (E_WAIT_STATUS)WaitForSingleObject(m_hEvent, nMillisecond);
#elif linux
    pthread_mutex_lock(&m_hMutex);
    if(nMillisecond == INFINITE)
    {
        pthread_cond_wait(&m_hEvent, &m_hMutex);
    }
    else
    {
        struct timeval tv;
        gettimeofday(&tv, nullptr);

        long nNanoSec = tv.tv_usec * 1000 + nMillisecond * 1000000;
        struct timespec tm;
        tm.tv_sec = tv.tv_sec + nNanoSec / 1000000000;
        tm.tv_nsec = nNanoSec % 1000000000;

        if(0 != pthread_cond_timedwait(&m_hEvent, &m_hMutex, &tm))
        {
            pthread_mutex_unlock(&m_hMutex);
            return E_WAIT_TIMEOUT;
        }
    }
    pthread_mutex_unlock(&m_hMutex);
#endif // WIN32
    return E_WAIT_SIGNAL;
}

void CThreadEvent::Signal()
{
#ifdef WIN32
	SetEvent(m_hEvent);
#elif linux
    pthread_cond_signal(&m_hEvent);
#endif // WIN32
}

E_WAIT_STATUS CThreadEvent::Acquire(uint32 nMilliseconds)
{
	return Wait(nMilliseconds);
}

void CThreadEvent::Release()
{
	Signal();
}
