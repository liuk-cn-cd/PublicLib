/**********************************************************************
 * @特别声明
 *     本段代码由liuk创建，所有通过正常途径获取此文件的开发人员
 * 均可任意修改、增加及删除文件内容，但请保留此声明。
 *     如有疑问请联系作者。
 * @特别声明结束
 ********************************************************************/

/**
 * @file	: Task.cpp
 * @brief	: 任务类实现文件
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
