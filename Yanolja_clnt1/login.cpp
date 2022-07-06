#include "login.h"
#include "ui_login.h"

#include <QMessageBox>

login::login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}


void login::on_login_btn_clicked()
{
    query_string = "SELECT PW FROM userTBL WHERE ID='" + ui->id_text->text().toStdString() + "'";
    query.exec(QString::fromStdString(query_string));
    if(query.size() == 0)
    {
        QMessageBox::warning(this, "error", "ID error");
    }
    else
    {
        query.next();
        if(query.value(0) != ui->pw_text->text())
        {
            QMessageBox::warning(this, "error", "PW error");
        }
        else
        {
            QMessageBox::information(this, "환 영", "로그인 성공");
            this->hide();
            tour_list tour;
            tour.setModal(true);
            tour.exec();
            this->show();
        }
    }
}

void login::on_signup_btn_clicked()
{
    this->hide();
    signup signup;
    signup.setModal(true);
    signup.exec();
    this->show();
}

void login::on_exit_btn_clicked()
{
    this->close();
}
