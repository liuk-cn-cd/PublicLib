/**********************************************************************
 * @特别声明
 *     本段代码由liuk创建，所有通过正常途径获取此文件的开发人员
 * 均可任意修改、增加及删除文件内容，但请保留此声明。
 *     如有疑问请联系作者。
 * @特别声明结束
 ********************************************************************/
/**
 * @file	: communication_global.h
 * @brief	: 通信库导出函数
 * @author	: liuk
 * @date	: 2017/04/30 10:37:46
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */
#ifndef COMMUNICATION_GLOBAL_H
#define COMMUNICATION_GLOBAL_H

#ifdef WIN32

#ifdef COMMUNICATION_LIB
#define COMMUNICATION_EXPORT _declspec(dllexport)
#else
#define COMMUNICATION_EXPORT _declspec(dllimport)
#endif // COMMUNICATION_LIB

#elif LINUX
#define COMMUNICATION_EXPORT
#endif


#endif // COMMUNICATION_GLOBAL_H
