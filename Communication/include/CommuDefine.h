/**********************************************************************
 * @特别声明
 *     本段代码由liuk创建，所有通过正常途径获取此文件的开发人员
 * 均可任意修改、增加及删除文件内容，但请保留此声明。
 *     如有疑问请联系作者。
 * @特别声明结束
 ********************************************************************/
/**
 * @file	: CommuDefine.h
 * @brief	: 通用定义
 * @author	: liuk
 * @date	: 2017/04/30 10:39:32
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */


#ifndef COMMUDEFINE_H__
#define COMMUDEFINE_H__
#ifdef WIN32
#include <WinSock.h>
typedef SOCKET SocketHandle;
#elif LINUX
#include <sys.socket.h>
#include <arpa/inet.h>
typedef int SocketHandle;
#endif // WIN32

#endif