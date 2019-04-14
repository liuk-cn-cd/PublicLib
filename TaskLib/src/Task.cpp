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
#include <process.h>



CTask::CTask():m_pUser(NULL)
{
	
}


CTask::~CTask()
{
}

void CTask::Attach(CTaskUser* pUser)
{
	m_pUser = pUser;
}

void CTask::run()
{
	if (NULL != m_pUser)
	{
		m_pUser->OnRunTask(this);
	}
}
