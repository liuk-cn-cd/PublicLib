/**********************************************************************
 * @特别声明
 *     本段代码由liuk创建，所有通过正常途径获取此文件的开发人员
 * 均可任意修改、增加及删除文件内容，但请保留此声明。
 *     如有疑问请联系作者。
 * @特别声明结束
 ********************************************************************/

/**
 * @file	: CommandExecutor.h
 * @brief	: 命令执行器声明
 * @author	: liuk
 * @date	: 2016/12/24 15:11:37
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */
#ifndef _COMMANDEXECUTOR_H
#define _COMMANDEXECUTOR_H
#include "Task.h"
#include "CommandQueue.h"
#include "ThreadLock.h"
#include "ThreadMutex.h"
class CCommandExecutor;

/*!
 * @class	: CCommandExecutorUser
 * @brief	: 命令执行器观察者
 * @author	: liuk
 * @date	: 2016/12/24 15:15
 */
class TASKLIB_EXPORT CCommandExecutorUser
{
public:
	CCommandExecutorUser() {}
	virtual ~CCommandExecutorUser() {}
public:
	/**
	 * @fn		: OnCommadExecute
	 * @brief	: 命令处理函数，子类实现此函数处理实际任务
	 * @access	: virtual private 
	 * @param	: CCommandExecutor * pCmdExecutor
	 * @return	: bool
	 */
	virtual bool OnCommadExecute(CCommandExecutor* pCmdExecutor, const CDataObject& dataObj, const CMsgKey& msgKey) = 0;
};

/*!
 * @class	: CCommandExecutor
 * @brief	: 命令执行器
 * @author	: liuk
 * @date	: 2016/12/24 15:15
 */
class TASKLIB_EXPORT CCommandExecutor :
	public CTaskUser
{
public:
	CCommandExecutor();
	~CCommandExecutor();
public:
	/**
	* @fn		: OnRunTask
	* @brief	: 子类实现此函数，事实上的任务处理
	* @access	: virtual public
	* @return	: void
	*/
	virtual void OnRunTask(CTask* pTask);

	/**
	 * @fn		: PutCmd
	 * @brief	: 添加一条命令
	 * @access	: public 
	 * @param	: const CDataObject &
	 * @param	: const CMsgKey & msgKey
	 * @return	: void
	 */
	void PutCmd(const CDataObject&, const CMsgKey& msgKey);

	void Attach(CCommandExecutorUser* pUser);
private:
	CTask m_cmdTask;
	CCommandExecutorUser* m_pUser;
	CCommandQueue m_queCommand;
};

#endif // !_COMMANDEXECUTOR_H