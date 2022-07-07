/********************************************************************************
** Form generated from reading UI file 'guide.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUIDE_H
#define UI_GUIDE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_guide
{
public:
    QListWidget *list;
    QPushButton *exit_btn;
    QPushButton *del_btn;
    QPushButton *change_btn;
    QPushButton *add_btn;
    QLineEdit *name_text;
    QLineEdit *phone_text;
    QLabel *name_label;
    QLabel *local_label;
    QLabel *can_label;
    QLabel *local_label_2;
    QLineEdit *user_id_text;
    QLineEdit *pos_text;

    void setupUi(QDialog *guide)
    {
        if (guide->objectName().isEmpty())
            guide->setObjectName(QString::fromUtf8("guide"));
        guide->resize(600, 400);
        list = new QListWidget(guide);
        list->setObjectName(QString::fromUtf8("list"));
        list->setGeometry(QRect(10, 10, 420, 370));
        exit_btn = new QPushButton(guide);
        exit_btn->setObjectName(QString::fromUtf8("exit_btn"));
        exit_btn->setGeometry(QRect(450, 340, 89, 25));
        del_btn = new QPushButton(guide);
        del_btn->setObjectName(QString::fromUtf8("del_btn"));
        del_btn->setGeometry(QRect(450, 300, 89, 25));
        change_btn = new QPushButton(guide);
        change_btn->setObjectName(QString::fromUtf8("change_btn"));
        change_btn->setGeometry(QRect(450, 260, 89, 25));
        add_btn = new QPushButton(guide);
        add_btn->setObjectName(QString::fromUtf8("add_btn"));
        add_btn->setGeometry(QRect(450, 220, 89, 25));
        name_text = new QLineEdit(guide);
        name_text->setObjectName(QString::fromUtf8("name_text"));
        name_text->setGeometry(QRect(440, 30, 113, 25));
        phone_text = new QLineEdit(guide);
        phone_text->setObjectName(QString::fromUtf8("phone_text"));
        phone_text->setGeometry(QRect(440, 80, 113, 25));
        name_label = new QLabel(guide);
        name_label->setObjectName(QString::fromUtf8("name_label"));
        name_label->setGeometry(QRect(440, 10, 67, 17));
        local_label = new QLabel(guide);
        local_label->setObjectName(QString::fromUtf8("local_label"));
        local_label->setGeometry(QRect(440, 60, 67, 17));
        can_label = new QLabel(guide);
        can_label->setObjectName(QString::fromUtf8("can_label"));
        can_label->setGeometry(QRect(440, 110, 67, 17));
        local_label_2 = new QLabel(guide);
        local_label_2->setObjectName(QString::fromUtf8("local_label_2"));
        local_label_2->setGeometry(QRect(440, 160, 67, 17));
        user_id_text = new QLineEdit(guide);
        user_id_text->setObjectName(QString::fromUtf8("user_id_text"));
        user_id_text->setGeometry(QRect(440, 180, 113, 25));
        pos_text = new QLineEdit(guide);
        pos_text->setObjectName(QString::fromUtf8("pos_text"));
        pos_text->setGeometry(QRect(440, 130, 113, 25));

        retranslateUi(guide);

        QMetaObject::connectSlotsByName(guide);
    } // setupUi

    void retranslateUi(QDialog *guide)
    {
        guide->setWindowTitle(QApplication::translate("guide", "Dialog", nullptr));
        exit_btn->setText(QApplication::translate("guide", "\353\222\244\353\241\234\352\260\200\352\270\260", nullptr));
        del_btn->setText(QApplication::translate("guide", "\354\202\255\354\240\234", nullptr));
        change_btn->setText(QApplication::translate("guide", "\354\210\230\354\240\225", nullptr));
        add_btn->setText(QApplication::translate("guide", "\354\266\224\352\260\200", nullptr));
        name_label->setText(QApplication::translate("guide", "\354\235\264\353\246\204", nullptr));
        local_label->setText(QApplication::translate("guide", "\354\240\204\355\231\224\353\262\210\355\230\270", nullptr));
        can_label->setText(QApplication::translate("guide", "\352\260\200\353\212\245\354\227\254\353\266\200", nullptr));
        local_label_2->setText(QApplication::translate("guide", "\354\230\210\354\225\275\352\263\240\352\260\235", nullptr));
    } // retranslateUi

};

namespace Ui {
    class guide: public Ui_guide {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUIDE_H
