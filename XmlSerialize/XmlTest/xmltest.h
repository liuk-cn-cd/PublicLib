#ifndef XMLTEST_H
#define XMLTEST_H

#include <QtWidgets/QMainWindow>
#include "ui_xmltest.h"

class XmlTest : public QMainWindow
{
	Q_OBJECT

public:
	XmlTest(QWidget *parent = 0);
	~XmlTest();

private:
	Ui::XmlTestClass ui;
};

#endif // XMLTEST_H
