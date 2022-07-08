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
    QPushButton *reservation_btn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *mainpage)
    {
        if (mainpage->objectName().isEmpty())
            mainpage->setObjectName(QString::fromUtf8("mainpage"));
        mainpage->resize(230, 270);
        QFont font;
        font.setFamily(QString::fromUtf8("Sans"));
        font.setBold(true);
        font.setWeight(75);
        mainpage->setFont(font);
        mainpage->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        centralwidget = new QWidget(mainpage);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        user_btn = new QPushButton(centralwidget);
        user_btn->setObjectName(QString::fromUtf8("user_btn"));
        user_btn->setGeometry(QRect(40, 10, 150, 30));
        user_btn->setFont(font);
        user_btn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(0, 0, 0);\n"
"	color: rgb(238, 238, 236);\n"
"    border-radius: 10px;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color: rgb(255, 255, 255);\n"
"	color: rgb(0, 0, 0);\n"
"    border-radius: 10px;\n"
"}"));
        guide_btn = new QPushButton(centralwidget);
        guide_btn->setObjectName(QString::fromUtf8("guide_btn"));
        guide_btn->setGeometry(QRect(40, 170, 150, 30));
        guide_btn->setFont(font);
        guide_btn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(0, 0, 0);\n"
"	color: rgb(238, 238, 236);\n"
"    border-radius: 10px;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color: rgb(255, 255, 255);\n"
"	color: rgb(0, 0, 0);\n"
"    border-radius: 10px;\n"
"}"));
        beach_btn = new QPushButton(centralwidget);
        beach_btn->setObjectName(QString::fromUtf8("beach_btn"));
        beach_btn->setGeometry(QRect(40, 90, 150, 30));
        beach_btn->setFont(font);
        beach_btn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(0, 0, 0);\n"
"	color: rgb(238, 238, 236);\n"
"    border-radius: 10px;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color: rgb(255, 255, 255);\n"
"	color: rgb(0, 0, 0);\n"
"    border-radius: 10px;\n"
"}"));
        tour_btn = new QPushButton(centralwidget);
        tour_btn->setObjectName(QString::fromUtf8("tour_btn"));
        tour_btn->setGeometry(QRect(40, 130, 150, 30));
        tour_btn->setFont(font);
        tour_btn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(0, 0, 0);\n"
"	color: rgb(238, 238, 236);\n"
"    border-radius: 10px;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color: rgb(255, 255, 255);\n"
"	color: rgb(0, 0, 0);\n"
"    border-radius: 10px;\n"
"}"));
        exit_btn = new QPushButton(centralwidget);
        exit_btn->setObjectName(QString::fromUtf8("exit_btn"));
        exit_btn->setGeometry(QRect(40, 210, 150, 30));
        exit_btn->setFont(font);
        exit_btn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(239, 41, 41);\n"
"	color: rgb(255, 255, 255);\n"
"    border-radius: 10px;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color: rgb(255, 255, 255);\n"
"	color: rgb(0, 0, 0);\n"
"    border-radius: 10px;\n"
"}"));
        reservation_btn = new QPushButton(centralwidget);
        reservation_btn->setObjectName(QString::fromUtf8("reservation_btn"));
        reservation_btn->setGeometry(QRect(40, 50, 150, 30));
        reservation_btn->setFont(font);
        reservation_btn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(0, 0, 0);\n"
"	color: rgb(238, 238, 236);\n"
"    border-radius: 10px;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color: rgb(255, 255, 255);\n"
"	color: rgb(0, 0, 0);\n"
"    border-radius: 10px;\n"
"}"));
        mainpage->setCentralWidget(centralwidget);
        menubar = new QMenuBar(mainpage);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 230, 22));
        mainpage->setMenuBar(menubar);
        statusbar = new QStatusBar(mainpage);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        mainpage->setStatusBar(statusbar);

        retranslateUi(mainpage);

        QMetaObject::connectSlotsByName(mainpage);
    } // setupUi

    void retranslateUi(QMainWindow *mainpage)
    {
        mainpage->setWindowTitle(QApplication::translate("mainpage", "Main", nullptr));
        user_btn->setText(QApplication::translate("mainpage", "\355\232\214\354\233\220\352\264\200\353\246\254", nullptr));
        guide_btn->setText(QApplication::translate("mainpage", "\352\260\200\354\235\264\353\223\234\352\264\200\353\246\254", nullptr));
        beach_btn->setText(QApplication::translate("mainpage", "\352\264\200\352\264\221\354\247\200\352\264\200\353\246\254", nullptr));
        tour_btn->setText(QApplication::translate("mainpage", "\354\210\231\353\260\225\354\227\205\354\262\264 \352\264\200\353\246\254", nullptr));
        exit_btn->setText(QApplication::translate("mainpage", "\354\242\205\353\243\214", nullptr));
        reservation_btn->setText(QApplication::translate("mainpage", "\354\230\210\354\225\275 \352\264\200\353\246\254", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainpage: public Ui_mainpage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINPAGE_H
