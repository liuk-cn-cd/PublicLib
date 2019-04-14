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



CThreadMutex::CThreadMutex()
{
#ifdef WIN32
	InitializeCriticalSection(&m_hMutex);
#endif // WIN32
}


CThreadMutex::~CThreadMutex()
{
#ifdef WIN32
	DeleteCriticalSection(&m_hMutex);
#endif // WIN32
}

E_WAIT_STATUS CThreadMutex::Acquire(int nMilliseconds)
{
#ifdef WIN32
	EnterCriticalSection(&m_hMutex);
#endif // WIN32
	return E_WAIT_SIGNAL;
}

void CThreadMutex::Release()
{
#ifdef WIN32
	LeaveCriticalSection(&m_hMutex);
#endif // WIN32
}
