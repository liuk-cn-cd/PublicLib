/**********************************************************************
 * @特别声明
 *     本段代码由liuk创建，所有通过正常途径获取此文件的开发人员
 * 均可任意修改、增加及删除文件内容，但请保留此声明。
 *     如有疑问请联系作者。
 * @特别声明结束
 ********************************************************************/

/**
 * @file	: Thread.h
 * @brief	: 线程类声明文件
 * @author	: liuk
 * @date	: 2016/12/18 15:57:28
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */
#ifndef _THREAD_H
#define  _THRED_H
#include "ThreadBase.h"
#include "ThreadEvent.h"

/*!
 * @class	: CThread
 * @brief	: 线程类，纯虚，使用时继承此类
 * @author	: liuk
 * @date	: 2016/12/18 15:58
 */
class TASKLIB_EXPORT CThread
{
public:
	CThread();
	virtual ~CThread();
public:
	/**
	 * @fn		: Start
	 * @brief	: 线程开始
	 * @access	: public 
	 * @return	: void
	 */
	bool Active();

	/**
	 * @fn		: Pause
	 * @brief	: 暂停线程
	 * @access	: public 
	 * @return	: 成功返回true
	 */
	bool Pause();

	void Quit();

	/**
	 * @fn		: Continue
	 * @brief	: 继续暂停的线程
	 * @access	: public 
	 * @return	: void
	 */
	void Continue();

	/**
	 * @fn		: Signal
	 * @brief	: 发送信号
	 * @access	: public 
	 * @return	: void
	 */
	void Signal();

	/**
	 * @fn		: Wait
	 * @brief	: CThread::Wait
	 * @access	: public 
	 * @param	: unsigned int nMillisecond
	 * @param	: nMillisecond ：等待nMillisecond毫秒，未等到则返回，如果设为INFINITE则一直阻塞
	 * @return	: E_WAIT_ABANDONED, 被放弃的
	 *			  E_WAIT_SIGNAL, 等到了信号
	 *			  E_WAIT_TIMEOUT,超时
	 *			  E_WAIT_FAILED, 错误
	 */
	E_WAIT_STATUS Wait(unsigned int nMillisecond = INFINITE);

	/**
	 * @fn		: Terminate
	 * @brief	: 中断线程
	 * @access	: public 
	 * @param	: unsigned int nExitCode， 退出码
	 * @return	: void
	 */
	void Terminate(unsigned int nExitCode = -1);

	/**
	 * @fn		: IsPause
	 * @brief	: 线程是否暂停
	 * @access	: public 
	 * @return	: bool
	 */
	bool IsPause() const;

	/**
	 * @fn		: IsQuit
	 * @brief	: 线程是否已退出
	 * @access	: public 
	 * @return	: bool
	 */
	bool IsQuit() const;

	/**
	 * @fn		: IsRunning
	 * @brief	: 线程是否在运行中
	 * @access	: public 
	 * @return	: bool
	 */
	bool IsRunning() const;
public:
	/**
	 * @fn		: run
	 * @brief	: 线程逻辑，其子类继承此函数
	 * @access	: virtual public 
	 * @return	: void
	 */
	virtual void run() = 0;
private:
	static unsigned __stdcall StartRun(CThread * thread_ptr);
private:
	THREADID m_hThread;
	CThreadEvent m_hEvent;
	bool m_bQuit;
	bool m_bRunning;
	bool m_bPause;
#ifdef WIN32
	unsigned m_unThreadAddress;
#endif
};

#endif