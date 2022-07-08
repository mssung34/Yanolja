/********************************************************************************
** Form generated from reading UI file 'edit.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDIT_H
#define UI_EDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_edit
{
public:
    QLineEdit *text1;
    QLineEdit *text2;
    QLineEdit *text3;
    QPushButton *ok_btn;
    QPushButton *exit_btn;
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;
    QLabel *label4;
    QLineEdit *text4;
    QLineEdit *text5;
    QLabel *label5;

    void setupUi(QDialog *edit)
    {
        if (edit->objectName().isEmpty())
            edit->setObjectName(QString::fromUtf8("edit"));
        edit->resize(350, 272);
        edit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        text1 = new QLineEdit(edit);
        text1->setObjectName(QString::fromUtf8("text1"));
        text1->setGeometry(QRect(10, 30, 211, 25));
        text2 = new QLineEdit(edit);
        text2->setObjectName(QString::fromUtf8("text2"));
        text2->setGeometry(QRect(10, 80, 211, 25));
        text3 = new QLineEdit(edit);
        text3->setObjectName(QString::fromUtf8("text3"));
        text3->setGeometry(QRect(10, 130, 211, 25));
        ok_btn = new QPushButton(edit);
        ok_btn->setObjectName(QString::fromUtf8("ok_btn"));
        ok_btn->setGeometry(QRect(240, 30, 89, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("Sans"));
        font.setBold(true);
        font.setWeight(75);
        ok_btn->setFont(font);
        ok_btn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(0, 0, 0);\n"
"	color: rgb(238, 238, 236);\n"
"    border-radius: 10px;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color: rgb(255, 255, 255);\n"
"	color: rgb(0, 0, 0);\n"
"    border-radius: 10px;\n"
"}"));
        exit_btn = new QPushButton(edit);
        exit_btn->setObjectName(QString::fromUtf8("exit_btn"));
        exit_btn->setGeometry(QRect(240, 80, 89, 30));
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
        label1 = new QLabel(edit);
        label1->setObjectName(QString::fromUtf8("label1"));
        label1->setGeometry(QRect(10, 10, 67, 17));
        label2 = new QLabel(edit);
        label2->setObjectName(QString::fromUtf8("label2"));
        label2->setGeometry(QRect(10, 60, 67, 17));
        label3 = new QLabel(edit);
        label3->setObjectName(QString::fromUtf8("label3"));
        label3->setGeometry(QRect(10, 110, 67, 17));
        label4 = new QLabel(edit);
        label4->setObjectName(QString::fromUtf8("label4"));
        label4->setGeometry(QRect(10, 160, 67, 17));
        text4 = new QLineEdit(edit);
        text4->setObjectName(QString::fromUtf8("text4"));
        text4->setGeometry(QRect(10, 180, 211, 25));
        text5 = new QLineEdit(edit);
        text5->setObjectName(QString::fromUtf8("text5"));
        text5->setGeometry(QRect(10, 230, 211, 25));
        label5 = new QLabel(edit);
        label5->setObjectName(QString::fromUtf8("label5"));
        label5->setGeometry(QRect(10, 210, 67, 17));

        retranslateUi(edit);

        QMetaObject::connectSlotsByName(edit);
    } // setupUi

    void retranslateUi(QDialog *edit)
    {
        edit->setWindowTitle(QApplication::translate("edit", "Edit", nullptr));
        ok_btn->setText(QApplication::translate("edit", "\355\231\225\354\235\270", nullptr));
        exit_btn->setText(QApplication::translate("edit", "\354\267\250\354\206\214", nullptr));
        label1->setText(QString());
        label2->setText(QString());
        label3->setText(QString());
        label4->setText(QString());
        label5->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class edit: public Ui_edit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDIT_H
