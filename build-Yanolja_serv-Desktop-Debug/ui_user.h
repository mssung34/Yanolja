/********************************************************************************
** Form generated from reading UI file 'user.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USER_H
#define UI_USER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_user
{
public:
    QListWidget *list;
    QPushButton *vip_btn;
    QPushButton *exit_btn;
    QPushButton *del_btn;

    void setupUi(QDialog *user)
    {
        if (user->objectName().isEmpty())
            user->setObjectName(QString::fromUtf8("user"));
        user->resize(600, 400);
        list = new QListWidget(user);
        list->setObjectName(QString::fromUtf8("list"));
        list->setGeometry(QRect(10, 10, 571, 341));
        vip_btn = new QPushButton(user);
        vip_btn->setObjectName(QString::fromUtf8("vip_btn"));
        vip_btn->setGeometry(QRect(380, 360, 89, 25));
        exit_btn = new QPushButton(user);
        exit_btn->setObjectName(QString::fromUtf8("exit_btn"));
        exit_btn->setGeometry(QRect(490, 360, 89, 25));
        del_btn = new QPushButton(user);
        del_btn->setObjectName(QString::fromUtf8("del_btn"));
        del_btn->setGeometry(QRect(10, 360, 89, 25));

        retranslateUi(user);

        QMetaObject::connectSlotsByName(user);
    } // setupUi

    void retranslateUi(QDialog *user)
    {
        user->setWindowTitle(QApplication::translate("user", "Dialog", nullptr));
        vip_btn->setText(QApplication::translate("user", "VIP \353\266\200\354\227\254/\355\225\264\354\240\234", nullptr));
        exit_btn->setText(QApplication::translate("user", " \353\222\244\353\241\234\352\260\200\352\270\260", nullptr));
        del_btn->setText(QApplication::translate("user", "\355\232\214\354\233\220\354\240\225\353\263\264\354\202\255\354\240\234", nullptr));
    } // retranslateUi

};

namespace Ui {
    class user: public Ui_user {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USER_H
