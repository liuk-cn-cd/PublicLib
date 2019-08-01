/**********************************************************************
 * @�ر�����
 *     ���δ�����liuk����������ͨ������;����ȡ���ļ��Ŀ�����Ա
 * ���������޸ġ����Ӽ�ɾ���ļ����ݣ����뱣����������
 *     ������������ϵ���ߡ�
 * @�ر���������
 ********************************************************************/

/**
 * @file	: Task.cpp
 * @brief	: ������ʵ���ļ�
 * @author	: liuk
 * @date	: 2016/12/18 17:05:48
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */
#include "Task.h"
#ifdef WIN32
#include <process.h>
#elif linux

#endif


CTask::CTask():m_pUser(nullptr)
{
	
}


CTask::~CTask()
{
}

void CTask::Attach(ITaskUser* pUser)
{
	m_pUser = pUser;
}

void CTask::run()
{
	if (nullptr != m_pUser)
	{
		m_pUser->OnRunTask(this);
	}
}
