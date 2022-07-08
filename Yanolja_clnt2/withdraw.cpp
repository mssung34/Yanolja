#include "withdraw.h"
#include "ui_withdraw.h"
#include <cstring>
#include <iostream>
#include <cstdlib>

withdraw::withdraw(std::string recv_ID,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::withdraw)
{
    Input_ID=recv_ID;
    ui->setupUi(this);
}

withdraw::~withdraw()
{
    delete ui;
}

void withdraw::on_out_btn_clicked()
{
    this->hide();
    info info(Input_ID);
    info.setModal(true);
    info.exec();
    this->show();
}

void withdraw::on_withdraw_btn_clicked()
{
    withdraw_id=ui->id_input->text().toStdString();
    if(Input_ID == withdraw_id)
    {

        query_string = "INSERT INTO outTBL select * FROM userTBL WHERE ID='"+Input_ID+"'";
        query.prepare(QString::fromStdString(query_string));
        query.exec();
        query.first();

        query_string="SELECT * FROM userTBL WHERE ID='"+Input_ID+"'";
        query.exec(QString::fromStdString(query_string));
        query.first();

        query_string="DELETE FROM userTBL WHERE ID='"+Input_ID+"'";
        query.exec(QString::fromStdString(query_string));
        query.first();

        QMessageBox::information(this,"탈퇴 성공 ㅠㅠ","다음에 만나요");
        this->close();




    }
    else
    {
        QMessageBox::information(this,"Error","아이디가 일치하지 않습니다.");
    }
}
