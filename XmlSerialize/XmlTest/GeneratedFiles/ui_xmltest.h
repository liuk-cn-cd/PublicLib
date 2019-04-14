/********************************************************************************
** Form generated from reading UI file 'xmltest.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_XMLTEST_H
#define UI_XMLTEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_XmlTestClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *XmlTestClass)
    {
        if (XmlTestClass->objectName().isEmpty())
            XmlTestClass->setObjectName(QStringLiteral("XmlTestClass"));
        XmlTestClass->resize(600, 400);
        menuBar = new QMenuBar(XmlTestClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        XmlTestClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(XmlTestClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        XmlTestClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(XmlTestClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        XmlTestClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(XmlTestClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        XmlTestClass->setStatusBar(statusBar);

        retranslateUi(XmlTestClass);

        QMetaObject::connectSlotsByName(XmlTestClass);
    } // setupUi

    void retranslateUi(QMainWindow *XmlTestClass)
    {
        XmlTestClass->setWindowTitle(QApplication::translate("XmlTestClass", "XmlTest", 0));
    } // retranslateUi

};

namespace Ui {
    class XmlTestClass: public Ui_XmlTestClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XMLTEST_H
