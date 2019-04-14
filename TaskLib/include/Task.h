/**********************************************************************
 * @特别声明
 *     本段代码由liuk创建，所有通过正常途径获取此文件的开发人员
 * 均可任意修改、增加及删除文件内容，但请保留此声明。
 *     如有疑问请联系作者。
 * @特别声明结束
 ********************************************************************/

/**
 * @file	: Task.h
 * @brief	: 任务类声明文件
 * @author	: liuk
 * @date	: 2016/12/18 15:26:50
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */
#ifndef _TASK_H
#define  _TASK_H

#include "Thread.h"
class CTask;
/*!
 * @class	: CTaskUser
 * @brief	: 任务观察者，实际任务的执行分派者
 * @author	: liuk
 * @date	: 2016/12/18 15:27
 */
class TASKLIB_EXPORT CTaskUser
{
public:
	CTaskUser() {}
	virtual ~CTaskUser() {}
public:
	/**
	 * @fn		: OnRunTask
	 * @brief	: 子类实现此函数，事实上的任务处理
	 * @access	: virtual public 
	 * @return	: void
	 */
	virtual void OnRunTask(CTask* pTask) = 0;
};

/*!
 * @class	: CTask
 * @brief	: 任务类，包含一个单独的任务线程
 * @author	: liuk
 * @date	: 2016/12/18 15:29
 */
class TASKLIB_EXPORT CTask : public CThread
{
public:
	CTask();
	~CTask();
public:
	/**
	 * @fn		: Attach
	 * @brief	: 绑定任务观察者
	 * @access	: public 
	 * @param	: CTaskUser * pUser
	 * @return	: void
	 */
	void Attach(CTaskUser* pUser);
protected:
	/**
	 * @fn		: run
	 * @brief	: 任务执行逻辑
	 * @access	: virtual protected 
	 * @return	: void
	 */
	virtual void run();
private:
	CTaskUser* m_pUser;
};
#endif // !_TASK_H


