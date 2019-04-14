/**********************************************************************
 * @特别声明
 *     本段代码由liuk创建，所有通过正常途径获取此文件的开发人员
 * 均可任意修改、增加及删除文件内容，但请保留此声明。
 *     如有疑问请联系作者。
 * @特别声明结束
 ********************************************************************/
/**
 * @file	: CommandQueue.cpp
 * @brief	: 命令队列实现文件
 * @author	: liuk
 * @date	: 2016/12/24 15:30:13
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */
#include "CommandQueue.h"



CCommandQueue::CCommandQueue()
	: m_taskSemaphore(0, 65535)
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
