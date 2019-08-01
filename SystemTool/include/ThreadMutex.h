/**********************************************************************
 * @�ر�����
 *     ���δ�����liuk����������ͨ������;����ȡ���ļ��Ŀ�����Ա
 * ���������޸ġ����Ӽ�ɾ���ļ����ݣ����뱣����������
 *     ������������ϵ���ߡ�
 * @�ر���������
 ********************************************************************/

/**
 * @file	: ThreadMutex.h
 * @brief	: ����������
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
 * @brief	: ������������һ�δ���
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
	 * @brief	: �õ������������ռ��������
	 * @access	: public 
	 * @param	: int nMilliseconds ,���ò�����Ϊ�˱��ֽӿ�һ�¶�����
	 * @return	: void
	 */
    virtual E_WAIT_STATUS Acquire(uint32 nMilliseconds = INFINITE);

	/**
	 * @fn		: Release
	 * @brief	: �ͷ���
	 * @access	: public 
	 * @return	: void
	 */
	virtual void Release();
private:
	HMUTEX m_hMutex;
};

#endif // _THRAEDMUTEX_H
