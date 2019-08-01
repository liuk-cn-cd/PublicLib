/**********************************************************************
 * @特别声明
 *     本段代码由liuk创建，所有通过正常途径获取此文件的开发人员
 * 均可任意修改、增加及删除文件内容，但请保留此声明。
 *     如有疑问请联系作者。
 * @特别声明结束
 ********************************************************************/

/**
 * @file	: ReadWriteMutex.h
 * @brief	: 读写锁声明
 * @author	: liuk
 * @date	: 2019/7/30 17:06:18
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 *
 */
#ifndef READWRITEMUTEX_H
#define READWRITEMUTEX_H
#ifdef linux
#include "SyncBase.h"
/*!
 * @class	: CReadWriteMutex
 * @brief	: 读写锁类
 * @author	: liuk
 * @date	: 2019/7/30 17:06:18
 */
class CReadWriteMutex : public CSyncBase
{
public:
    CReadWriteMutex();
public:
    /**
     * @brief ReadLock 加读锁
     * @param nMilliseconds 等待时间，默认为一直等待
     * @return 返回等待结果
     */
    E_WAIT_STATUS ReadLock(uint32 nMilliseconds = INFINITE);

    /**
     * @brief WriteLock 加写锁
     * @param nMilliseconds 等待时间，默认为一直等待
     * @return 返回等待结果
     */
    E_WAIT_STATUS WriteLock(uint32 nMilliseconds = INFINITE);
    /**
     * @brief Acquire 获取锁，此处指写锁
     * @param nMilliseconds
     * @return
     */
    virtual E_WAIT_STATUS Acquire(uint32 nMilliseconds = INFINITE);
    /**
     * @brief Release 释放锁
     */
    virtual void Release();
private:
    HRWMUTEX m_hMutex;
};
#endif // linux
#endif // READWRITEMUTEX_H
