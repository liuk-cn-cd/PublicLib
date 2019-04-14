/**********************************************************************
 * @�ر�����
 *     ���δ�����liuk����������ͨ������;����ȡ���ļ��Ŀ�����Ա
 * ���������޸ġ����Ӽ�ɾ���ļ����ݣ����뱣����������
 *     ������������ϵ���ߡ�
 * @�ر���������
 ********************************************************************/
/**
 * @file	: ThreadEvent.cpp
 * @brief	: �߳��¼�ʵ�ֺ���
 * @author	: liuk
 * @date	: 2016/12/24 10:48:52
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */
#include "ThreadEvent.h"

CThreadEvent::CThreadEvent(bool bInitEvent)
{
#ifdef WIN32
	m_hEvent = CreateEvent(NULL, FALSE, bInitEvent ? TRUE : FALSE, NULL);
#endif // WIN32
}


CThreadEvent::~CThreadEvent()
{
#ifdef WIN32
	ResetEvent(m_hEvent);
#endif // WIN32
}

E_WAIT_STATUS CThreadEvent::Wait(unsigned int nMillisecond /*= INFINITE*/)
{
#ifdef WIN32
	return (E_WAIT_STATUS)WaitForSingleObject(m_hEvent, nMillisecond);
#endif // WIN32
}

void CThreadEvent::Signal()
{
#ifdef WIN32
	SetEvent(m_hEvent);
#endif // WIN32
}

E_WAIT_STATUS CThreadEvent::Acquire(int nMilliseconds)
{
	return Wait(nMilliseconds);
}

void CThreadEvent::Release()
{
	Signal();
}
