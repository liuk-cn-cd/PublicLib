/**********************************************************************
 * @特别声明
 *     本段代码由liuk创建，所有通过正常途径获取此文件的开发人员
 * 均可任意修改、增加及删除文件内容，但请保留此声明。
 *     如有疑问请联系作者。
 * @特别声明结束
 ********************************************************************/
/**
 * @file	: DataObject.h
 * @brief	: 串行化数据类声明文件
 * @author	: liuk
 * @date	: 2016/12/24 15:05:25
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */
#ifndef _DATAOBJECT_H
#define _DATAOBJECT_H
#include "ThreadBase.h"
/*!
 * @class	: CDataObject
 * @brief	: 串行化数据类
 * @author	: liuk
 * @date	: 2016/12/24 15:06
 */
class TASKLIB_EXPORT CDataObject
{
public:
	CDataObject();
	virtual ~CDataObject();
};

#endif // _DATAOBJECT_H