#include "TestCfg.h"



CTestCfg::CTestCfg()
{
	//a = 1;
	//b = 2;
	//c = 3;
	//d = "test";
	//e.push_back(1);
	//e.push_back(3);
	//e.push_back(5);
	//e.push_back(3);
	//e.push_back(5);
	//SubCfg s;
	//s.A = 2;
	//s.B = 3;
	//vecObj.push_back(s);
	//s.A = 4;
	//s.B = 5;
	//vecObj.push_back(s);
	//s.A = 6;
	//s.B = 7;
	//vecObj.push_back(s);
	//aa = 12;
	//bb = 1.2345;
	//cc = "abcdefg";
}

CTestCfg::~CTestCfg()
{
}

void CTestCfg::Save()
{
	bool bRet = StoreXmlFile("./test.xml");
	int a = 0;
}
#if 0
CXmlElement*  CTestCfg::XMLSerialize(bool bStore, CXmlElement* pRootXmlElement)
{
	std::string strNodeName = "测试";
	if (bStore)
	{
		pRootXmlElement->SetName(strNodeName);
	}

	if (bStore)
	{
		CXmlElement* pElement = new CXmlElement;
		pElement->SetName("A");
		pElement->SetValue(a);
		pRootXmlElement->PushChild(pElement);
	}
	else
	{
		CXmlElement* pElement = pRootXmlElement->NextChildElement();\
			if (pElement->GetName() == std::string("A"))
				pElement->GetValue(a);
	}

	if (bStore)
	{
		CXmlElement* pElement = new CXmlElement;
		pElement->SetName("B");
		pElement->SetValue(b);
		pRootXmlElement->PushChild(pElement);
	}
	else
	{
		CXmlElement* pElement = pRootXmlElement->NextChildElement();\
			if (pElement->GetName() == std::string("B"))
				pElement->GetValue(b);
	}

	if (bStore)
	{
		CXmlElement* pElement = new CXmlElement;
		pElement->SetName("C");
		pElement->SetValue(c);
		pRootXmlElement->PushChild(pElement);
	}
	else
	{
		CXmlElement* pElement = pRootXmlElement->NextChildElement();\
			if (pElement->GetName() == std::string("C"))
				pElement->GetValue(c);
	}

	if (bStore)
	{
		CXmlElement* pElement = new CXmlElement;
		pElement->SetName("D");
		pElement->SetValue(d);
		pRootXmlElement->PushChild(pElement);
	}
	else
	{
		CXmlElement* pElement = pRootXmlElement->NextChildElement();\
			if (pElement->GetName() == std::string("D"))
				pElement->GetValue(d);
	}

	if (bStore)\
	{\
		CXmlElement* pParent = new CXmlElement;\
		pParent->SetName("数组");\
		for (int i = 0; i < e.size(); i++)\
		{\
			CXmlElement* pSubElement = new CXmlElement;\
			pSubElement->SetName("成员");\
			pSubElement->SetValue(e[i]);\
			pParent->PushChild(pSubElement);\
		}\
			pRootXmlElement->PushChild(pParent);\
	}\
	else\
		{\
		CXmlElement* pParent = pRootXmlElement->NextChildElement();\
		if (pParent->GetName() == std::string("数组"))\
		{\
			CXmlElement* pSubElement = pParent->FirstChildElement();\
			e.resize(pParent->ChildCount());\
			int i = 0;\
			while (pSubElement)\
			{\
				pSubElement->GetValue(e[i++]);\
				pSubElement = pParent->NextChildElement();\
			}\
		}\
		}\

		if (bStore)\
		{ \
			CXmlElement* pObjElement = sub.XMLSerialize(bStore, new CXmlElement);\
			pObjElement->SetName("对象");\
			pRootXmlElement->PushChild(pObjElement);\
		}\
		else\
		{\
			sub.XMLSerialize(bStore, pRootXmlElement->NextChildElement());\
		}\
	return pRootXmlElement;
}
#endif
void CTestCfg::Read()
{
	bool bRet = ReadXmlFile("./test.xml");
	e.clear();
	vecObj.clear();
	a = 10;
	b = 20;
	c = 30;
	d = "TEST";
	e.push_back(11);
	e.push_back(13);
	e.push_back(15);
	e.push_back(13);
	e.push_back(15);
	SubCfg s;
	s.A = 12;
	s.B = 13;
	vecObj.push_back(s);
	s.A = 14;
	s.B = 15;
	vecObj.push_back(s);
	s.A = 16;
	s.B = 17;
	vecObj.push_back(s);
	aa = 112;
	bb = 1.12345;
	cc = "ABCDEFGHIJKLMN";
}


#if 1
BEGIN_XML_SERIALIZE(CTestCfg, 测试)
XML_SER_VAR(A, a)
XML_SER_VAR(B, b)
XML_SER_VAR(C, c)
XML_SER_VAR(D, d)
XML_SER_STL_VAR(数组, 成员, e)
XML_SER_OBJECT(对象, sub)
XML_SER_STL_OBJECT(对象数组, 对象, vecObj);
XML_SER_ATTR(属性1, aa)
XML_SER_ATTR(属性2, bb)
XML_SER_ATTR(属性3, cc)
END_XML_SERIALIZE()
#endif

SubCfg::SubCfg()
{
	A = 9;
	B = 0;
	strC = "不为尧存不为桀亡";
}

BEGIN_XML_SERIALIZE(SubCfg, OBJS)
XML_SER_VAR(AA, A)
XML_SER_VAR(BB, B)
XML_SER_VAR(字串, strC)
END_XML_SERIALIZE()
