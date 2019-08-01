/**********************************************************************
 * @�ر�����
 *     ���δ�����liuk����������ͨ������;����ȡ���ļ��Ŀ�����Ա
 * ���������޸ġ����Ӽ�ɾ���ļ����ݣ����뱣����������
 *     ������������ϵ���ߡ�
 * @�ر���������
 ********************************************************************/
/**
 * @file	: ThreadMutex.cpp
 * @brief	: ������ʵ���ļ�
 * @author	: liuk
 * @date	: 2016/12/23 20:53:06
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */
#include "ThreadMutex.h"
#ifdef linux
#include <sys/time.h>

#endif


CThreadMutex::CThreadMutex()
{
#ifdef WIN32
	InitializeCriticalSection(&m_hMutex);
#elif linux
    pthread_mutex_init(&m_hMutex, nullptr);
#endif // WIN32
}


CThreadMutex::~CThreadMutex()
{
#ifdef WIN32
	DeleteCriticalSection(&m_hMutex);
#elif linux
    pthread_mutex_destroy(&m_hMutex);
#endif // WIN32
}

E_WAIT_STATUS CThreadMutex::Acquire(uint32 nMilliseconds)
{
#ifdef WIN32
	EnterCriticalSection(&m_hMutex);
#elif linux
    if(nMilliseconds == INFINITE)
    {
        pthread_mutex_lock(&m_hMutex);
    }
    else
    {
        struct timeval tv;
        gettimeofday(&tv, nullptr);

        long nNanoSec = tv.tv_usec * 1000 + nMilliseconds * 1000000;
        struct timespec tm;
        tm.tv_sec = tv.tv_sec + nNanoSec / 1000000000;
        tm.tv_nsec = nNanoSec % 1000000000;

        if(0 != pthread_mutex_timedlock(&m_hMutex, &tm))
        {
            return E_WAIT_TIMEOUT;
        }
    }
#endif // WIN32
	return E_WAIT_SIGNAL;
}

void CThreadMutex::Release()
{
#ifdef WIN32
	LeaveCriticalSection(&m_hMutex);
#elif linux
    pthread_mutex_unlock(&m_hMutex);
#endif // WIN32
}
