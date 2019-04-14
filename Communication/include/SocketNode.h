/**********************************************************************
 * @特别声明
 *     本段代码由liuk创建，所有通过正常途径获取此文件的开发人员
 * 均可任意修改、增加及删除文件内容，但请保留此声明。
 *     如有疑问请联系作者。
 * @特别声明结束
 ********************************************************************/
/**
 * @file	: SocketNode.h
 * @brief	:
 * @author	: liuk
 * @date	: 2017/04/30 10:46:58
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */
#include <string>
#include "communication_global.h"

#define PACKAGE_MAX_SIZE 65535
/*!
 * @class	: CSocketNode
 * @brief	: 通信数据节点
 * @author	: liuk
 * @date	: 2017/04/30 10:47
 */
class COMMUNICATION_EXPORT CSocketNode
{
public:
	CSocketNode();
	CSocketNode(const CSocketNode& rObj);
	~CSocketNode();

	CSocketNode& operator=(const CSocketNode& rObj);

public:
	const unsigned char* GetDataBuffer() const;
	int GetDataSize() const;
	std::string GetSrcIp() const;
	int GetSrcPort() const;

	void SetData(const unsigned char* pData, int nlen);
	void SetSrcAddr(const std::string& strIp, unsigned short usPort);
private:
	void Clear();
private:
	std::string m_strSrcIp;
	unsigned short m_usSrcPort;

	unsigned char* m_pData;
	int m_nSize;

};

