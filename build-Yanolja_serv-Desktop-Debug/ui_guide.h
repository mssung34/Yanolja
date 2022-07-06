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
    QLineEdit *local_text;
    QLabel *name_label;
    QLabel *local_label;

    void setupUi(QDialog *guide)
    {
        if (guide->objectName().isEmpty())
            guide->setObjectName(QString::fromUtf8("guide"));
        guide->resize(600, 400);
        list = new QListWidget(guide);
        list->setObjectName(QString::fromUtf8("list"));
        list->setGeometry(QRect(10, 10, 371, 371));
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
        name_text->setGeometry(QRect(440, 80, 113, 25));
        local_text = new QLineEdit(guide);
        local_text->setObjectName(QString::fromUtf8("local_text"));
        local_text->setGeometry(QRect(440, 130, 113, 25));
        name_label = new QLabel(guide);
        name_label->setObjectName(QString::fromUtf8("name_label"));
        name_label->setGeometry(QRect(440, 50, 67, 17));
        local_label = new QLabel(guide);
        local_label->setObjectName(QString::fromUtf8("local_label"));
        local_label->setGeometry(QRect(440, 110, 67, 17));

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
        local_label->setText(QApplication::translate("guide", "\353\213\264\353\213\271\352\265\254\354\227\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class guide: public Ui_guide {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUIDE_H
