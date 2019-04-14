/**********************************************************************
 * @特别声明
 *     本段代码由liuk创建，所有通过正常途径获取此文件的开发人员
 * 均可任意修改、增加及删除文件内容，但请保留此声明。
 *     如有疑问请联系作者。
 * @特别声明结束
 ********************************************************************/
/**
 * @file	: ThreadSemaphore.h
 * @brief	:
 * @author	: liuk
 * @date	: 2016/12/23 20:58:55
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */
#ifndef _THREADSEMAPHORE_H
#define _THREADSEMAPHORE_H
#include "SyncBase.h"
/*!
 * @class	: CThreadSemaphore
 * @brief	: 线程信号量
 * @author	: liuk
 * @date	: 2016/12/23 20:59
 */
class TASKLIB_EXPORT CThreadSemaphore : public CSyncBase
{
public:
	CThreadSemaphore(int nInitCount = 1, int nMaxCount = 1);
	~CThreadSemaphore();
#ifdef LINUX
	/**
	 * @fn		: Acquire
	 * @brief	: 使用信号量
	 * @access	: public 
	 * @param	: nAcquireCount，使用的信号量数量，若信号量不足则阻塞，此参数在windows下无效，windows只能一次使用一个信号量
	 * @return	: void
	 */
	void Acquire(int nAcquireCount);
#endif

	/**
	 * @fn		: Acquire
	 * @brief	: 信号量使用一个，没有资源则阻塞
	 * @access	: public 
	 * @return	: void
	 */
	virtual E_WAIT_STATUS Acquire(int nMilliseconds = INFINITE);

	/**
	 * @fn		: Release
	 * @brief	: 释放信号量
	 * @access	: public 
	 * @param	: nReleaseCount，释放的信号量数量，超出最大限制则阻塞
	 * @return	: void
	 */
	void Release(int nReleaseCount);

	/**
	 * @fn		: Release
	 * @brief	: 释放一个信号量，资源已满则阻塞
	 * @access	: public 
	 * @return	: void
	 */
	virtual void Release();
private:
	HSEMAPHORE m_hSemaphore;
};

#endif // !_THREADSEMAPHORE_H