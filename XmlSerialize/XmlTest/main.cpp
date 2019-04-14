#include "xmltest.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	XmlTest w;
	w.show();
	return a.exec();
}
