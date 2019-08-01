#ifdef linux
#include "ReadWriteMutex.h"
#include <sys/time.h>

CReadWriteMutex::CReadWriteMutex()
{

}

E_WAIT_STATUS CReadWriteMutex::ReadLock(uint32 nMilliseconds)
{
    if(nMilliseconds == INFINITE)
    {
        pthread_rwlock_rdlock(&m_hMutex);
    }
    else
    {
        struct timeval tv;
        gettimeofday(&tv, nullptr);

        long nNanoSec = tv.tv_usec * 1000 + nMilliseconds * 1000000;
        struct timespec tm;
        tm.tv_sec = tv.tv_sec + nNanoSec / 1000000000;
        tm.tv_nsec = nNanoSec % 1000000000;

        if(0 != pthread_rwlock_timedrdlock(&m_hMutex, &tm))
        {
            return E_WAIT_TIMEOUT;
        }
    }
    return E_WAIT_SIGNAL;
}

E_WAIT_STATUS CReadWriteMutex::WriteLock(uint32 nMilliseconds)
{
    if(nMilliseconds == INFINITE)
    {
        pthread_rwlock_wrlock(&m_hMutex);
    }
    else
    {
        struct timeval tv;
        gettimeofday(&tv, nullptr);

        long nNanoSec = tv.tv_usec * 1000 + nMilliseconds * 1000000;
        struct timespec tm;
        tm.tv_sec = tv.tv_sec + nNanoSec / 1000000000;
        tm.tv_nsec = nNanoSec % 1000000000;

        if(0 != pthread_rwlock_timedwrlock(&m_hMutex, &tm))
        {
            return E_WAIT_TIMEOUT;
        }
    }
    return E_WAIT_SIGNAL;
}

E_WAIT_STATUS CReadWriteMutex::Acquire(uint32 nMilliseconds)
{
    return WriteLock(nMilliseconds);
}

void CReadWriteMutex::Release()
{
    pthread_rwlock_unlock(&m_hMutex);
}
#endif
