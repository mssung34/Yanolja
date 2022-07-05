#include "signup.h"
#include "ui_signup.h"

#include <QMessageBox>

signup::signup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signup)
{
    ui->setupUi(this);
    ischeck = false;
}

signup::~signup()
{
    delete ui;
}

void signup::on_check_btn_clicked()
{
    query_string = "SELECT ID FROM userTBL WHERE ID='" + ui->id_text->text().toStdString() + "'";
    query.exec(QString::fromStdString(query_string));
    if(query.size() == 0)
    {
        QMessageBox::information(this, "OK", "OK");
        ischeck = true;
    }
    else
        QMessageBox::information(this, "NO", "NO");
}

void signup::on_signup_btn_clicked()
{
    if(!ischeck)
    {
        QMessageBox::warning(this, "error", "ID 중복확인 필요");
    }
    else
    {
        if(ui->pw_text->text() != ui->pw2_text->text())
        {
            QMessageBox::warning(this, "error", "PW 불일치");
        }
        else
        {
            query.prepare("INSERT INTO userTBL (ID, PW, name, phone) "
                              "VALUES (?, ?, ?, ?)");
            query.addBindValue(ui->id_text->text());
            query.addBindValue(ui->pw_text->text());
            query.addBindValue(ui->name_text->text());
            query.addBindValue(ui->phone_text->text());
            query.exec();
            QMessageBox::information(this, "경 축", "회원가입 완료");
            this->close();
        }
    }
}

void signup::on_exit_btn_clicked()
{
    this->close();
}
