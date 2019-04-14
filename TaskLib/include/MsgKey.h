/**********************************************************************
 * @特别声明
 *     本段代码由liuk创建，所有通过正常途径获取此文件的开发人员
 * 均可任意修改、增加及删除文件内容，但请保留此声明。
 *     如有疑问请联系作者。
 * @特别声明结束
 ********************************************************************/
/**
 * @file	: MsgKey.h
 * @brief	: 消息键声明文件
 * @author	: liuk
 * @date	: 2016/12/24 15:33:46
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */
#ifndef MSGKEY_H
#define MSGKEY_H
#include "ThreadBase.h"
/*!
 * @class	: CMsgKey
 * @brief	: 消息键类
 * @author	: liuk
 * @date	: 2016/12/24 15:34
 */
class TASKLIB_EXPORT CMsgKey
{
public:
	CMsgKey(unsigned int nCode = 0, unsigned int nFlag1 = 0, unsigned int nFlag2 = 0, unsigned int nFlag3 = 0);
	~CMsgKey();

public:
	unsigned int GetMsgCode()const;
	unsigned int GetFlag1() const;
	unsigned int GetFlag2() const;
	unsigned int GetFlag3() const;
	CMsgKey& operator=(const CMsgKey& rObj);
private:
	unsigned int m_nMsgCode;
	unsigned int m_nFlag1;
	unsigned int m_nFlag2;
	unsigned int m_nFlag3;
};

#endif // MSGKEY_H