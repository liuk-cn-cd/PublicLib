#include "xmltest.h"
#include "TestCfg.h"
XmlTest::XmlTest(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	CTestCfg cfg;
	cfg.Read();
	cfg.Save();
}

XmlTest::~XmlTest()
{

}
