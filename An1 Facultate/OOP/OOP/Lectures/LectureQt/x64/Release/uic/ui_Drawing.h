/********************************************************************************
** Form generated from reading UI file 'Drawing.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRAWING_H
#define UI_DRAWING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DrawingClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DrawingClass)
    {
        if (DrawingClass->objectName().isEmpty())
            DrawingClass->setObjectName(QString::fromUtf8("DrawingClass"));
        DrawingClass->resize(600, 400);
        menuBar = new QMenuBar(DrawingClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        DrawingClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(DrawingClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        DrawingClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(DrawingClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        DrawingClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(DrawingClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        DrawingClass->setStatusBar(statusBar);

        retranslateUi(DrawingClass);

        QMetaObject::connectSlotsByName(DrawingClass);
    } // setupUi

    void retranslateUi(QMainWindow *DrawingClass)
    {
        DrawingClass->setWindowTitle(QCoreApplication::translate("DrawingClass", "Drawing", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DrawingClass: public Ui_DrawingClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRAWING_H
