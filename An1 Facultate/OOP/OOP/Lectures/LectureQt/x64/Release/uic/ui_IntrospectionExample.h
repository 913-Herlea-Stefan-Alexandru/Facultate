/********************************************************************************
** Form generated from reading UI file 'IntrospectionExample.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTROSPECTIONEXAMPLE_H
#define UI_INTROSPECTIONEXAMPLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IntrospectionExampleClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *IntrospectionExampleClass)
    {
        if (IntrospectionExampleClass->objectName().isEmpty())
            IntrospectionExampleClass->setObjectName(QString::fromUtf8("IntrospectionExampleClass"));
        IntrospectionExampleClass->resize(600, 400);
        menuBar = new QMenuBar(IntrospectionExampleClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        IntrospectionExampleClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(IntrospectionExampleClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        IntrospectionExampleClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(IntrospectionExampleClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        IntrospectionExampleClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(IntrospectionExampleClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        IntrospectionExampleClass->setStatusBar(statusBar);

        retranslateUi(IntrospectionExampleClass);

        QMetaObject::connectSlotsByName(IntrospectionExampleClass);
    } // setupUi

    void retranslateUi(QMainWindow *IntrospectionExampleClass)
    {
        IntrospectionExampleClass->setWindowTitle(QCoreApplication::translate("IntrospectionExampleClass", "IntrospectionExample", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IntrospectionExampleClass: public Ui_IntrospectionExampleClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTROSPECTIONEXAMPLE_H
