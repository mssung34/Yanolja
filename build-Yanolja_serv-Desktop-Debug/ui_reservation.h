/********************************************************************************
** Form generated from reading UI file 'reservation.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESERVATION_H
#define UI_RESERVATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_reservation
{
public:
    QTableWidget *list;
    QPushButton *exit_btn;
    QPushButton *del_btn;
    QPushButton *edit_btn;
    QPushButton *add_btn;

    void setupUi(QDialog *reservation)
    {
        if (reservation->objectName().isEmpty())
            reservation->setObjectName(QString::fromUtf8("reservation"));
        reservation->resize(1000, 550);
        reservation->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        list = new QTableWidget(reservation);
        if (list->columnCount() < 5)
            list->setColumnCount(5);
        list->setObjectName(QString::fromUtf8("list"));
        list->setGeometry(QRect(10, 60, 970, 470));
        list->setColumnCount(5);
        list->horizontalHeader()->setDefaultSectionSize(180);
        list->horizontalHeader()->setStretchLastSection(true);
        exit_btn = new QPushButton(reservation);
        exit_btn->setObjectName(QString::fromUtf8("exit_btn"));
        exit_btn->setGeometry(QRect(890, 15, 89, 30));
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
        del_btn = new QPushButton(reservation);
        del_btn->setObjectName(QString::fromUtf8("del_btn"));
        del_btn->setGeometry(QRect(780, 15, 89, 30));
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
        edit_btn = new QPushButton(reservation);
        edit_btn->setObjectName(QString::fromUtf8("edit_btn"));
        edit_btn->setGeometry(QRect(670, 15, 89, 30));
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
        add_btn = new QPushButton(reservation);
        add_btn->setObjectName(QString::fromUtf8("add_btn"));
        add_btn->setGeometry(QRect(560, 15, 89, 30));
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

        retranslateUi(reservation);

        QMetaObject::connectSlotsByName(reservation);
    } // setupUi

    void retranslateUi(QDialog *reservation)
    {
        reservation->setWindowTitle(QApplication::translate("reservation", "Dialog", nullptr));
        exit_btn->setText(QApplication::translate("reservation", "\353\222\244\353\241\234\352\260\200\352\270\260", nullptr));
        del_btn->setText(QApplication::translate("reservation", "\354\202\255\354\240\234", nullptr));
        edit_btn->setText(QApplication::translate("reservation", "\354\210\230\354\240\225", nullptr));
        add_btn->setText(QApplication::translate("reservation", "\354\266\224\352\260\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class reservation: public Ui_reservation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESERVATION_H
