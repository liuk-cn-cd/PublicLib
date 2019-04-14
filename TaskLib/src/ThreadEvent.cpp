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
