#include "ThreadSemaphore.h"

#ifdef linux
#include <sys/time.h>
#endif

#ifdef WIN32
CThreadSemaphore::CThreadSemaphore(int nInitCount /*= 0*/, int nMaxCount /*= 1*/)
{
    m_hSemaphore = CreateSemaphore(nullptr, nInitCount, nMaxCount, nullptr);
}
#elif linux
CThreadSemaphore::CThreadSemaphore(uint32 nInitCount)
{
    sem_init(&m_hSemaphore, 0, nInitCount);
}
#endif



CThreadSemaphore::~CThreadSemaphore()
{
#ifdef WIN32
	CloseHandle(m_hSemaphore);
#elif linux
    sem_destroy(&m_hSemaphore);
#endif // WIN32
}

E_WAIT_STATUS CThreadSemaphore::Acquire(uint32 nMilliseconds)
{
#ifdef  WIN32
	return E_WAIT_STATUS(WaitForSingleObject(m_hSemaphore, nMilliseconds));
#elif linux
    if(nMilliseconds == INFINITE)
    {
        sem_wait(&m_hSemaphore);
    }
    else
    {
        struct timeval tv;
        gettimeofday(&tv, nullptr);

        long nNanoSec = tv.tv_usec * 1000 + nMilliseconds * 1000000;
        struct timespec tm;
        tm.tv_sec = tv.tv_sec + nNanoSec / 1000000000;
        tm.tv_nsec = nNanoSec % 1000000000;

        if(0 != sem_timedwait(&m_hSemaphore, &tm))
        {
            return E_WAIT_TIMEOUT;
        }
    }
#endif //  WIN32
}
#ifdef WIN32
void CThreadSemaphore::Release(int nReleaseCount)
{
    ReleaseSemaphore(m_hSemaphore, nReleaseCount, nullptr);
}
#endif
void CThreadSemaphore::Release()
{
#ifdef WIN32
	ReleaseSemaphore(m_hSemaphore, 1, nullptr);
#elif linux
    sem_post(&m_hSemaphore);
#endif // WIN32
}

