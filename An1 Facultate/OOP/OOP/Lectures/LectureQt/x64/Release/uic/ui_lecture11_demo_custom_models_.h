/********************************************************************************
** Form generated from reading UI file 'lecture11_demo_custom_models_.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LECTURE11_DEMO_CUSTOM_MODELS__H
#define UI_LECTURE11_DEMO_CUSTOM_MODELS__H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Lecture11_demo_custom_modelsClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *tableView;
    QHBoxLayout *horizontalLayout_2;
    QTableView *genesTableView;
    QWidget *treeView;
    QHBoxLayout *horizontalLayout_3;
    QTreeView *genesTreeView;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_4;
    QListView *listView;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Lecture11_demo_custom_modelsClass)
    {
        if (Lecture11_demo_custom_modelsClass->objectName().isEmpty())
            Lecture11_demo_custom_modelsClass->setObjectName(QString::fromUtf8("Lecture11_demo_custom_modelsClass"));
        Lecture11_demo_custom_modelsClass->resize(1024, 514);
        centralWidget = new QWidget(Lecture11_demo_custom_modelsClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QFont font;
        font.setPointSize(14);
        tabWidget->setFont(font);
        tableView = new QWidget();
        tableView->setObjectName(QString::fromUtf8("tableView"));
        horizontalLayout_2 = new QHBoxLayout(tableView);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        genesTableView = new QTableView(tableView);
        genesTableView->setObjectName(QString::fromUtf8("genesTableView"));

        horizontalLayout_2->addWidget(genesTableView);

        tabWidget->addTab(tableView, QString());
        treeView = new QWidget();
        treeView->setObjectName(QString::fromUtf8("treeView"));
        horizontalLayout_3 = new QHBoxLayout(treeView);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        genesTreeView = new QTreeView(treeView);
        genesTreeView->setObjectName(QString::fromUtf8("genesTreeView"));

        horizontalLayout_3->addWidget(genesTreeView);

        tabWidget->addTab(treeView, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        horizontalLayout_4 = new QHBoxLayout(tab);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        listView = new QListView(tab);
        listView->setObjectName(QString::fromUtf8("listView"));

        horizontalLayout_4->addWidget(listView);

        tabWidget->addTab(tab, QString());

        horizontalLayout->addWidget(tabWidget);

        Lecture11_demo_custom_modelsClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Lecture11_demo_custom_modelsClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1024, 21));
        Lecture11_demo_custom_modelsClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Lecture11_demo_custom_modelsClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Lecture11_demo_custom_modelsClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Lecture11_demo_custom_modelsClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Lecture11_demo_custom_modelsClass->setStatusBar(statusBar);

        retranslateUi(Lecture11_demo_custom_modelsClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Lecture11_demo_custom_modelsClass);
    } // setupUi

    void retranslateUi(QMainWindow *Lecture11_demo_custom_modelsClass)
    {
        Lecture11_demo_custom_modelsClass->setWindowTitle(QCoreApplication::translate("Lecture11_demo_custom_modelsClass", "Lecture11_demo_custom_models", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tableView), QCoreApplication::translate("Lecture11_demo_custom_modelsClass", "TableView", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(treeView), QCoreApplication::translate("Lecture11_demo_custom_modelsClass", "TreeView", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("Lecture11_demo_custom_modelsClass", "ListView", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Lecture11_demo_custom_modelsClass: public Ui_Lecture11_demo_custom_modelsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LECTURE11_DEMO_CUSTOM_MODELS__H
