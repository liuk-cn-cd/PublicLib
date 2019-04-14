#pragma once
#include "XmlSerializeObject.h"
#include "XmlSerializeMacro.h"
#include <vector>
class SubCfg : public CXmlSerializeObject
{
	DECLARE_XML_SERIALIZE()
public:
	SubCfg();
	int A;
	int B;
	std::string strC;
};
class CTestCfg : public CXmlSerializeObject
{
	DECLARE_XML_SERIALIZE()
public:
	CTestCfg();
	~CTestCfg();
	void Save();
	void Read();
	int a;
	double b;
	float c;
	std::string d;
	std::vector<int> e;
	SubCfg sub;
	std::vector<SubCfg> vecObj;

	int aa;
	double bb;
	std::string cc;

};

