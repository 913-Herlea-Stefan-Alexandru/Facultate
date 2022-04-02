/********************************************************************************
** Form generated from reading UI file 'Lecture10_demo_Notepad.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LECTURE10_DEMO_NOTEPAD_H
#define UI_LECTURE10_DEMO_NOTEPAD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Lecture10_demo_NotepadClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Lecture10_demo_NotepadClass)
    {
        if (Lecture10_demo_NotepadClass->objectName().isEmpty())
            Lecture10_demo_NotepadClass->setObjectName(QString::fromUtf8("Lecture10_demo_NotepadClass"));
        Lecture10_demo_NotepadClass->resize(600, 400);
        menuBar = new QMenuBar(Lecture10_demo_NotepadClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        Lecture10_demo_NotepadClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Lecture10_demo_NotepadClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Lecture10_demo_NotepadClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(Lecture10_demo_NotepadClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Lecture10_demo_NotepadClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Lecture10_demo_NotepadClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Lecture10_demo_NotepadClass->setStatusBar(statusBar);

        retranslateUi(Lecture10_demo_NotepadClass);

        QMetaObject::connectSlotsByName(Lecture10_demo_NotepadClass);
    } // setupUi

    void retranslateUi(QMainWindow *Lecture10_demo_NotepadClass)
    {
        Lecture10_demo_NotepadClass->setWindowTitle(QCoreApplication::translate("Lecture10_demo_NotepadClass", "Lecture10_demo_Notepad", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Lecture10_demo_NotepadClass: public Ui_Lecture10_demo_NotepadClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LECTURE10_DEMO_NOTEPAD_H
