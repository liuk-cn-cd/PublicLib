/**********************************************************************
 * @特别声明
 *     本段代码由liuk创建，所有通过正常途径获取此文件的开发人员
 * 均可任意修改、增加及删除文件内容，但请保留此声明。
 *     如有疑问请联系作者。
 * @特别声明结束
 ********************************************************************/

/**
 * @file	: ThreadLock.h
 * @brief	: 线程锁类声明
 * @author	: liuk
 * @date	: 2016/12/24 14:15:33
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */
#ifndef _THREADLOCK_H
#define _THREADLOCK_H
#include "ThreadBase.h"

class CSyncBase;

#define GUARD(ClassName, ObjName) \
	CThreadLock lock##ClassName##ObjName((ObjName));


/*!
 * @class	: CThreadLock
 * @brief	: 线程锁类，构造时加锁，析构时释放
 * @author	: liuk
 * @date	: 2016/12/24 14:19
 */
class TASKLIB_EXPORT CThreadLock
{
public:
	CThreadLock(CSyncBase& syncObj);
	~CThreadLock();
private:
	CSyncBase& m_syncObj;
};

#endif // !_THREADLOCK_H