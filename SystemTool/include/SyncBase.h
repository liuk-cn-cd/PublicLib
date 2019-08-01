/**********************************************************************
 * @特别声明
 *     本段代码由liuk创建，所有通过正常途径获取此文件的开发人员
 * 均可任意修改、增加及删除文件内容，但请保留此声明。
 *     如有疑问请联系作者。
 * @特别声明结束
 ********************************************************************/

/**
 * @file	: SyncBase.h
 * @brief	: 线程同步基类声明
 * @author	: liuk
 * @date	: 2016/12/24 14:06:18
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */
#ifndef _SYNCBASE_H
#define _SYNCBASE_H
#include "ThreadBase.h"
/*!
 * @class	: CSyncBase
 * @brief	: 线程同步类基类
 * @author	: liuk
 * @date	: 2016/12/24 14:06
 */
class TASKLIB_EXPORT CSyncBase
{
public:
	CSyncBase();
	virtual ~CSyncBase();
public:
    virtual E_WAIT_STATUS Acquire(uint32 nMilliseconds = INFINITE) = 0;
	virtual void Release() = 0;
};

#endif // _SYNCBASE_H
