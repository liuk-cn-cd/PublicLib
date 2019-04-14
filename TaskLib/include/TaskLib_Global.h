/**********************************************************************
* @特别声明
*     本段代码由liuk创建，所有通过正常途径获取此文件的开发人员
* 均可任意修改、增加及删除文件内容，但请保留此声明。
*     如有疑问请联系作者。
* @特别声明结束
********************************************************************/
/**
* @file	: TaskLib_Global.h
* @brief	: 线程库导出头文件
* @author	: liuk
* @date	: 2016/12/18 15:27:01
* @version : 1.0.0.0
* @contact	: liukangx@hotmail.com
*
*/
#ifndef _TASKLIB_GLOBAL_H
#define _TASKLIB_GLOBAL_H

#ifdef WIN32

#ifdef TASKLIB_LIB
#define TASKLIB_EXPORT _declspec(dllexport)
#else
#define TASKLIB_EXPORT _declspec(dllimport)
#endif // TASKLIB_LIB

#elif LINUX
#define TASKLIB_EXPORT
#endif

#endif