/********************************************************************************
** Form generated from reading UI file 'beach.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BEACH_H
#define UI_BEACH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_beach
{
public:
    QTableWidget *list;
    QPushButton *exit_btn;
    QPushButton *del_btn;
    QPushButton *edit_btn;
    QPushButton *add_btn;

    void setupUi(QDialog *beach)
    {
        if (beach->objectName().isEmpty())
            beach->setObjectName(QString::fromUtf8("beach"));
        beach->resize(1000, 550);
        list = new QTableWidget(beach);
        list->setObjectName(QString::fromUtf8("list"));
        list->setGeometry(QRect(10, 60, 970, 470));
        list->horizontalHeader()->setDefaultSectionSize(200);
        list->horizontalHeader()->setStretchLastSection(true);
        list->verticalHeader()->setVisible(false);
        exit_btn = new QPushButton(beach);
        exit_btn->setObjectName(QString::fromUtf8("exit_btn"));
        exit_btn->setGeometry(QRect(880, 10, 89, 25));
        del_btn = new QPushButton(beach);
        del_btn->setObjectName(QString::fromUtf8("del_btn"));
        del_btn->setGeometry(QRect(770, 10, 89, 25));
        edit_btn = new QPushButton(beach);
        edit_btn->setObjectName(QString::fromUtf8("edit_btn"));
        edit_btn->setGeometry(QRect(660, 10, 89, 25));
        add_btn = new QPushButton(beach);
        add_btn->setObjectName(QString::fromUtf8("add_btn"));
        add_btn->setGeometry(QRect(550, 10, 89, 25));

        retranslateUi(beach);

        QMetaObject::connectSlotsByName(beach);
    } // setupUi

    void retranslateUi(QDialog *beach)
    {
        beach->setWindowTitle(QApplication::translate("beach", "Dialog", nullptr));
        exit_btn->setText(QApplication::translate("beach", "\353\217\214\354\225\204\352\260\200\352\270\260", nullptr));
        del_btn->setText(QApplication::translate("beach", "\354\202\255\354\240\234", nullptr));
        edit_btn->setText(QApplication::translate("beach", "\354\210\230\354\240\225", nullptr));
        add_btn->setText(QApplication::translate("beach", "\354\266\224\352\260\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class beach: public Ui_beach {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BEACH_H
