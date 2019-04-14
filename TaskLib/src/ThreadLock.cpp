#include "ThreadLock.h"
#include "SyncBase.h"

CThreadLock::CThreadLock(CSyncBase & syncObj)
	: m_syncObj(syncObj)
{
	m_syncObj.Acquire();
}

CThreadLock::~CThreadLock()
{
	m_syncObj.Release();
}
