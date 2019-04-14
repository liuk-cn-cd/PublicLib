/**********************************************************************
 * @特别声明
 *     本段代码由liuk创建，所有通过正常途径获取此文件的开发人员
 * 均可任意修改、增加及删除文件内容，但请保留此声明。
 *     如有疑问请联系作者。
 * @特别声明结束
 ********************************************************************/
/**
 * @file	: CommandQueue.h
 * @brief	: 命令队列声明文件
 * @author	: liuk
 * @date	: 2016/12/24 15:27:01
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */
#ifndef _COMMANDQUEUE_H
#define _COMMANDQUEUE_H
#include <queue>
#include <utility>
#include "ThreadSemaphore.h"
#include "ThreadMutex.h"
#include "DataObject.h"
#include "MsgKey.h"
#include "ThreadLock.h"

typedef std::pair<CDataObject, CMsgKey> CCommand;

/*!
 * @class	: CCommandQueue
 * @brief	: 命令队列
 * @author	: liuk
 * @date	: 2016/12/24 15:27
 */
class TASKLIB_EXPORT CCommandQueue
{
public:
	CCommandQueue();
	~CCommandQueue();

	/**
	 * @fn		: DequeueCommand
	 * @brief	: 命令出队，如果当前没有则阻塞
	 * @access	: public 
	 * @param	: CDataObject & dataObj
	 * @param	: const CMsgKey &
	 * @return	: void
	 */
	void DequeueCommand(CDataObject& dataObj, CMsgKey& msgKey);

	/**
	 * @fn		: EnqueueCommand
	 * @brief	: 命令入队，如果达到最大命令数(65535)则阻塞
	 * @access	: public 
	 * @param	: const CDataObject & dataObj
	 * @return	: void
	 */
	void EnqueueCommand(const CDataObject& dataObj, const CMsgKey& msgKey);
private:
	// 命令信号量
	CThreadSemaphore m_taskSemaphore;
	// 命令队列
	std::queue<CCommand > m_queCmd;

	CThreadMutex m_queCommandLock;
};

#endif // _COMMANDQUEUE_H