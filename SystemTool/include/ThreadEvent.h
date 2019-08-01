/**********************************************************************
 * @特别声明
 *     本段代码由liuk创建，所有通过正常途径获取此文件的开发人员
 * 均可任意修改、增加及删除文件内容，但请保留此声明。
 *     如有疑问请联系作者。
 * @特别声明结束
 ********************************************************************/
/**
 * @file	: ThreadEvent.h
 * @brief	: 线程事件类声明文件
 * @author	: liuk
 * @date	: 2016/12/24 10:43:40
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */
#ifndef _THREADEVENT_H
#define  _THREADEVENT_H
#include "SyncBase.h"
/*!
 * @class	: CThreadEvent
 * @brief	: 线程事件
 * @author	: liuk
 * @date	: 2016/12/24 10:43
 */
class TASKLIB_EXPORT CThreadEvent : public CSyncBase
{
public:
#ifdef WIN32
	CThreadEvent(bool bInitEvent = false);
#elif linux
    CThreadEvent();
#endif
	~CThreadEvent();
	/**
	 * @fn		: Wait
	 * @brief	: 等待信号
	 * @access	: public 
	 * @param	: nMillisecond ：等待nMillisecond毫秒，未等到则返回，如果设为INFINITE则一直阻塞
	 * @return	: E_WAIT_ABANDONED, 被放弃的 
	 *			  E_WAIT_SIGNAL, 等到了信号
	 *			  E_WAIT_TIMEOUT,超时
	 *			  E_WAIT_FAILED, 错误
	 */
    E_WAIT_STATUS Wait(uint32 nMillisecond = INFINITE);

	/**
	 * @fn		: Signal
	 * @brief	: 发出信号，Wait函数接到此信号则返回E_WAIT_SIGNAL
	 * @access	: public 
	 * @return	: void
	 */
	void Signal();

	/**
	 * @fn		: Acquire
	 * @brief	: 等待事件
	 * @access	: virtual public 
	 * @return	: void
	 */
    virtual E_WAIT_STATUS Acquire(uint32 nMilliseconds = INFINITE);

	/**
	 * @fn		: Release
	 * @brief	: 阻塞事件
	 * @access	: virtual public 
	 * @return	: void
	 */
	virtual void Release();
private:
	HEVENT m_hEvent;
    HMUTEX m_hMutex;
};

#endif // _THREADEVENT_H
