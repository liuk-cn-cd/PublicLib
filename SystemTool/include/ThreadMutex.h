/**********************************************************************
 * @特别声明
 *     本段代码由liuk创建，所有通过正常途径获取此文件的开发人员
 * 均可任意修改、增加及删除文件内容，但请保留此声明。
 *     如有疑问请联系作者。
 * @特别声明结束
 ********************************************************************/

/**
 * @file	: ThreadMutex.h
 * @brief	: 互斥锁声明
 * @author	: liuk
 * @date	: 2016/12/23 20:50:22
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */
#ifndef _THRAEDMUTEX_H
#define _THRAEDMUTEX_H
#include "SyncBase.h"
/*!
 * @class	: CThreadMutex
 * @brief	: 互斥锁，锁定一段代码
 * @author	: liuk
 * @date	: 2016/12/23 20:51
 */
class TASKLIB_EXPORT CThreadMutex : public CSyncBase
{
public:
	CThreadMutex();
	~CThreadMutex();
public:
	/**
	 * @fn		: Acquire
	 * @brief	: 得到锁，如果锁被占用则阻塞
	 * @access	: public 
	 * @param	: int nMilliseconds ,无用参数，为了保持接口一致而保留
	 * @return	: void
	 */
    virtual E_WAIT_STATUS Acquire(uint32 nMilliseconds = INFINITE);

	/**
	 * @fn		: Release
	 * @brief	: 释放锁
	 * @access	: public 
	 * @return	: void
	 */
	virtual void Release();
private:
	HMUTEX m_hMutex;
};

#endif // _THRAEDMUTEX_H
