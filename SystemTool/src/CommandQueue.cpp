/**********************************************************************
 * @�ر�����
 *     ���δ�����liuk����������ͨ������;����ȡ���ļ��Ŀ�����Ա
 * ���������޸ġ����Ӽ�ɾ���ļ����ݣ����뱣����������
 *     ������������ϵ���ߡ�
 * @�ر���������
 ********************************************************************/
/**
 * @file	: CommandQueue.cpp
 * @brief	: �������ʵ���ļ�
 * @author	: liuk
 * @date	: 2016/12/24 15:30:13
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */
#include "CommandQueue.h"



CCommandQueue::CCommandQueue()
#ifdef WIN32
    : m_taskSemaphore(0, 65536)
#elif linux
    : m_taskSemaphore(0)
#endif
{
}


CCommandQueue::~CCommandQueue()
{
}

void CCommandQueue::DequeueCommand(CDataObject& dataObj, CMsgKey& msgKey)
{
	m_taskSemaphore.Acquire();
	CCommand cmd = m_queCmd.front();
	dataObj	 = cmd.first;
	msgKey	 = cmd.second;
	GUARD(CThreadMutex, m_queCommandLock)
	m_queCmd.pop();
	
}

void CCommandQueue::EnqueueCommand(const CDataObject& dataObj, const CMsgKey& msgKey)
{
	CCommand cmd(dataObj, msgKey);
	{
		GUARD(CThreadMutex, m_queCommandLock)
		m_queCmd.push(cmd);
	}
	m_taskSemaphore.Release();
}
