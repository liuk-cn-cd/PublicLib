/**********************************************************************
 * @�ر�����
 *     ���δ�����liuk����������ͨ������;����ȡ���ļ��Ŀ�����Ա
 * ���������޸ġ����Ӽ�ɾ���ļ����ݣ����뱣����������
 *     ������������ϵ���ߡ�
 * @�ر���������
 ********************************************************************/

/**
 * @file	: ReadWriteMutex.h
 * @brief	: ��д������
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
 * @brief	: ��д����
 * @author	: liuk
 * @date	: 2019/7/30 17:06:18
 */
class CReadWriteMutex : public CSyncBase
{
public:
    CReadWriteMutex();
public:
    /**
     * @brief ReadLock �Ӷ���
     * @param nMilliseconds �ȴ�ʱ�䣬Ĭ��Ϊһֱ�ȴ�
     * @return ���صȴ����
     */
    E_WAIT_STATUS ReadLock(uint32 nMilliseconds = INFINITE);

    /**
     * @brief WriteLock ��д��
     * @param nMilliseconds �ȴ�ʱ�䣬Ĭ��Ϊһֱ�ȴ�
     * @return ���صȴ����
     */
    E_WAIT_STATUS WriteLock(uint32 nMilliseconds = INFINITE);
    /**
     * @brief Acquire ��ȡ�����˴�ָд��
     * @param nMilliseconds
     * @return
     */
    virtual E_WAIT_STATUS Acquire(uint32 nMilliseconds = INFINITE);
    /**
     * @brief Release �ͷ���
     */
    virtual void Release();
private:
    HRWMUTEX m_hMutex;
};
#endif // linux
#endif // READWRITEMUTEX_H
