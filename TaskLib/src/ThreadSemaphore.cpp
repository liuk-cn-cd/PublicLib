#include "ThreadSemaphore.h"

CThreadSemaphore::CThreadSemaphore(int nInitCount /*= 0*/, int nMaxCount /*= 1*/)
{
#ifdef WIN32
	m_hSemaphore = CreateSemaphore(NULL, nInitCount, nMaxCount, NULL);
#endif
}


CThreadSemaphore::~CThreadSemaphore()
{
#ifdef WIN32
	CloseHandle(m_hSemaphore);
#endif // WIN32
}

E_WAIT_STATUS CThreadSemaphore::Acquire(int nMilliseconds)
{
#ifdef  WIN32
	return E_WAIT_STATUS(WaitForSingleObject(m_hSemaphore, nMilliseconds));
#endif //  WIN32
}

void CThreadSemaphore::Release(int nReleaseCount)
{
#ifdef WIN32
	ReleaseSemaphore(m_hSemaphore, nReleaseCount, NULL);
#endif // WIN32
}

void CThreadSemaphore::Release()
{
#ifdef WIN32
	ReleaseSemaphore(m_hSemaphore, 1, NULL);
#endif // WIN32
}

#ifdef LINUX
void CThreadSemaphore::Acquire(int nAcquireCount)
{

}
#endif