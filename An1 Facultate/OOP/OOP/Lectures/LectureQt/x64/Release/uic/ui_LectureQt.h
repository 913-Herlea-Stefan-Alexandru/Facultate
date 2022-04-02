/********************************************************************************
** Form generated from reading UI file 'LectureQt.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LECTUREQT_H
#define UI_LECTUREQT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LectureQtClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *LectureQtClass)
    {
        if (LectureQtClass->objectName().isEmpty())
            LectureQtClass->setObjectName(QString::fromUtf8("LectureQtClass"));
        LectureQtClass->resize(600, 400);
        menuBar = new QMenuBar(LectureQtClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        LectureQtClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(LectureQtClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        LectureQtClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(LectureQtClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        LectureQtClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(LectureQtClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        LectureQtClass->setStatusBar(statusBar);

        retranslateUi(LectureQtClass);

        QMetaObject::connectSlotsByName(LectureQtClass);
    } // setupUi

    void retranslateUi(QMainWindow *LectureQtClass)
    {
        LectureQtClass->setWindowTitle(QCoreApplication::translate("LectureQtClass", "LectureQt", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LectureQtClass: public Ui_LectureQtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LECTUREQT_H
