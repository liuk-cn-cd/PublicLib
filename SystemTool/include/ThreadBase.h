/**********************************************************************
 * @特别声明
 *     本段代码由liuk创建，所有通过正常途径获取此文件的开发人员
 * 均可任意修改、增加及删除文件内容，但请保留此声明。
 *     如有疑问请联系作者。
 * @特别声明结束
 ********************************************************************/
/**
 * @file	: ThreadBase.h
 * @brief	: 线程库基础类型定义文件
 * @author	: liuk
 * @date	: 2016/12/24 10:49:20
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */
#ifndef _THREADBASE_H
#define  _THREADBASE_H
#include "TaskLib_Global.h"
#include "TypeDef.h"
#ifdef WIN32
#include <windows.h>
typedef uintptr_t THREADID;
typedef HANDLE HEVENT;
typedef HANDLE HSEMAPHORE;
typedef CRITICAL_SECTION HMUTEX;
#elif linux
#include <pthread.h>
#include <semaphore.h>
typedef pthread_t THREADID;
typedef pthread_cond_t HEVENT;
typedef sem_t HSEMAPHORE;
typedef pthread_mutex_t HMUTEX;
typedef pthread_rwlock_t HRWMUTEX;
#endif

#ifndef INFINITE
#define  INFINITE 0xFFFFFFFF
#endif // !INFINITEINFINITE

enum E_WAIT_STATUS
{
	E_WAIT_ABANDONED = 0x00000080L, // 被放弃的 
	E_WAIT_SIGNAL = 0x00000000L,	// 等到了信号
	E_WAIT_TIMEOUT = 0x00000102L,	// 超时
	E_WAIT_FAILED = 0xFFFFFFFFL,	// 错误
};

#endif
