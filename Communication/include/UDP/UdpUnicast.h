/**********************************************************************
 * @特别声明
 *     本段代码由liuk创建，所有通过正常途径获取此文件的开发人员
 * 均可任意修改、增加及删除文件内容，但请保留此声明。
 *     如有疑问请联系作者。
 * @特别声明结束
 ********************************************************************/
/**
 * @file	: UdpUnicast.h
 * @brief	:
 * @author	: liuk
 * @date	: 2017/05/06 10:12:11
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */
#ifndef _UDPUNICAST_H__
#define _UDPUNICAST_H__
#include "UdpSocket.h"
class CUdpUnicast :
	public CUdpSocket
{
public:
	CUdpUnicast();
	~CUdpUnicast();
};

#endif // _UDPUNICAST_H__