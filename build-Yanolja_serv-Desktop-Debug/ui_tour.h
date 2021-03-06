/********************************************************************************
** Form generated from reading UI file 'tour.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOUR_H
#define UI_TOUR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_tour
{
public:
    QTableWidget *list;
    QPushButton *exit_btn;
    QPushButton *del_btn;
    QPushButton *edit_btn;
    QPushButton *add_btn;

    void setupUi(QDialog *tour)
    {
        if (tour->objectName().isEmpty())
            tour->setObjectName(QString::fromUtf8("tour"));
        tour->resize(1000, 550);
        tour->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        list = new QTableWidget(tour);
        list->setObjectName(QString::fromUtf8("list"));
        list->setGeometry(QRect(10, 60, 970, 470));
        list->horizontalHeader()->setDefaultSectionSize(200);
        list->horizontalHeader()->setStretchLastSection(true);
        list->verticalHeader()->setVisible(false);
        exit_btn = new QPushButton(tour);
        exit_btn->setObjectName(QString::fromUtf8("exit_btn"));
        exit_btn->setGeometry(QRect(880, 15, 89, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("Sans"));
        font.setBold(true);
        font.setWeight(75);
        exit_btn->setFont(font);
        exit_btn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(0, 0, 0);\n"
"	color: rgb(238, 238, 236);\n"
"    border-radius: 10px;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color: rgb(255, 255, 255);\n"
"	color: rgb(0, 0, 0);\n"
"    border-radius: 10px;\n"
"}"));
        del_btn = new QPushButton(tour);
        del_btn->setObjectName(QString::fromUtf8("del_btn"));
        del_btn->setGeometry(QRect(770, 15, 89, 30));
        del_btn->setFont(font);
        del_btn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(0, 0, 0);\n"
"	color: rgb(238, 238, 236);\n"
"    border-radius: 10px;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color: rgb(255, 255, 255);\n"
"	color: rgb(0, 0, 0);\n"
"    border-radius: 10px;\n"
"}"));
        edit_btn = new QPushButton(tour);
        edit_btn->setObjectName(QString::fromUtf8("edit_btn"));
        edit_btn->setGeometry(QRect(660, 15, 89, 30));
        edit_btn->setFont(font);
        edit_btn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(0, 0, 0);\n"
"	color: rgb(238, 238, 236);\n"
"    border-radius: 10px;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color: rgb(255, 255, 255);\n"
"	color: rgb(0, 0, 0);\n"
"    border-radius: 10px;\n"
"}"));
        add_btn = new QPushButton(tour);
        add_btn->setObjectName(QString::fromUtf8("add_btn"));
        add_btn->setGeometry(QRect(550, 15, 89, 30));
        add_btn->setFont(font);
        add_btn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(0, 0, 0);\n"
"	color: rgb(238, 238, 236);\n"
"    border-radius: 10px;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color: rgb(255, 255, 255);\n"
"	color: rgb(0, 0, 0);\n"
"    border-radius: 10px;\n"
"}"));

        retranslateUi(tour);

        QMetaObject::connectSlotsByName(tour);
    } // setupUi

    void retranslateUi(QDialog *tour)
    {
        tour->setWindowTitle(QApplication::translate("tour", "Dialog", nullptr));
        exit_btn->setText(QApplication::translate("tour", "\353\222\244\353\241\234\352\260\200\352\270\260", nullptr));
        del_btn->setText(QApplication::translate("tour", "\354\202\255\354\240\234", nullptr));
        edit_btn->setText(QApplication::translate("tour", "\354\210\230\354\240\225", nullptr));
        add_btn->setText(QApplication::translate("tour", "\354\266\224\352\260\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class tour: public Ui_tour {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOUR_H
