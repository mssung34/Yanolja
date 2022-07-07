/********************************************************************************
** Form generated from reading UI file 'mainpage.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINPAGE_H
#define UI_MAINPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainpage
{
public:
    QWidget *centralwidget;
    QPushButton *user_btn;
    QPushButton *guide_btn;
    QPushButton *beach_btn;
    QPushButton *tour_btn;
    QPushButton *exit_btn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *mainpage)
    {
        if (mainpage->objectName().isEmpty())
            mainpage->setObjectName(QString::fromUtf8("mainpage"));
        mainpage->resize(240, 200);
        centralwidget = new QWidget(mainpage);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        user_btn = new QPushButton(centralwidget);
        user_btn->setObjectName(QString::fromUtf8("user_btn"));
        user_btn->setGeometry(QRect(10, 10, 89, 25));
        guide_btn = new QPushButton(centralwidget);
        guide_btn->setObjectName(QString::fromUtf8("guide_btn"));
        guide_btn->setGeometry(QRect(130, 50, 89, 25));
        beach_btn = new QPushButton(centralwidget);
        beach_btn->setObjectName(QString::fromUtf8("beach_btn"));
        beach_btn->setGeometry(QRect(130, 10, 89, 25));
        tour_btn = new QPushButton(centralwidget);
        tour_btn->setObjectName(QString::fromUtf8("tour_btn"));
        tour_btn->setGeometry(QRect(10, 50, 89, 25));
        exit_btn = new QPushButton(centralwidget);
        exit_btn->setObjectName(QString::fromUtf8("exit_btn"));
        exit_btn->setGeometry(QRect(130, 120, 89, 25));
        mainpage->setCentralWidget(centralwidget);
        menubar = new QMenuBar(mainpage);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 240, 22));
        mainpage->setMenuBar(menubar);
        statusbar = new QStatusBar(mainpage);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        mainpage->setStatusBar(statusbar);

        retranslateUi(mainpage);

        QMetaObject::connectSlotsByName(mainpage);
    } // setupUi

    void retranslateUi(QMainWindow *mainpage)
    {
        mainpage->setWindowTitle(QApplication::translate("mainpage", "mainpage", nullptr));
        user_btn->setText(QApplication::translate("mainpage", "\355\232\214\354\233\220\352\264\200\353\246\254", nullptr));
        guide_btn->setText(QApplication::translate("mainpage", "\352\260\200\354\235\264\353\223\234\352\264\200\353\246\254", nullptr));
        beach_btn->setText(QApplication::translate("mainpage", "\352\264\200\352\264\221\354\247\200\352\264\200\353\246\254", nullptr));
        tour_btn->setText(QApplication::translate("mainpage", "\354\210\231\353\260\225\354\227\205\354\262\264 \352\264\200\353\246\254", nullptr));
        exit_btn->setText(QApplication::translate("mainpage", "\354\242\205\353\243\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainpage: public Ui_mainpage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINPAGE_H
