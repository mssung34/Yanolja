#include "info.h"
#include "ui_info.h"
#include "menu.h"
#include "login.h"

info::info(std::string recv_ID,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::info)
{
    ui->setupUi(this);
    Input_ID=recv_ID;
    this->show_info();
}

info::~info()
{
    delete ui;
}

void info::show_info()
{
    ui->listWidget->clear();
    query_string="SELECT * FROM userTBL WHERE ID='"+Input_ID+"'";
    query.exec(QString::fromStdString(query_string));
    record=query.record();
    int id=record.indexOf("ID");
    int pw=record.indexOf("PW");
    int name=record.indexOf("name");
    int phone=record.indexOf("phone");
    int vip=record.indexOf("vip");

    while(query.next())
    {
        ui->listWidget->addItem("ID:"+query.value(id).toString()+"\n");
        ui->listWidget->addItem("PW:"+query.value(pw).toString()+"\n");
        ui->listWidget->addItem("Name:"+query.value(name).toString()+"\n");
        ui->listWidget->addItem("Phone:"+query.value(phone).toString()+"\n");
        ui->listWidget->addItem("vip:"+query.value(vip).toString()+"\n");
       // ui->listWidget->addItem("ID:"+query.value(id).toString()+"\nPW:"+query.value(pw).toString()+"\nName:"+query.value(name).toString()+"\nPhone:"+query.value(phone).toString()+"\nVIP:"+query.value(vip).toString());
    }
    ui->check_btn->setText("예약현황");
    slt=1;
}


void info::on_out_btn_clicked()
{
    this->hide();
    menu menu(Input_ID);
    menu.setModal(true);
    menu.exec();
    this->show();
}

void info::on_change_pw_clicked()
{
    this->hide();
    change_pw change_pw(Input_ID);
    change_pw.setModal(true);
    change_pw.exec();
    this->show();
}

void info::on_withdraw_btn_clicked()
{
    this->hide();
    withdraw withdraw(Input_ID);
    withdraw.setModal(true);
    withdraw.exec();
    this->show();
}

void info::on_check_btn_clicked()
{
    if(slt==0)
        show_info();
    else if(slt==1)
        show_reservation();
}

void info::show_reservation()
{
    ui->listWidget->clear();
    query_string="SELECT * FROM reservationTBL WHERE ID='"+Input_ID+"'";
    query.exec(QString::fromStdString(query_string));
    record=query.record();
    int re_id=record.indexOf("ID");
    int re_hotel=record.indexOf("hotel");
    int re_attraction=record.indexOf("attraction");
    int re_guide=record.indexOf("guide");
    int re_date=record.indexOf("date");


    while(query.next())
    {
        ui->listWidget->addItem("ID:"+query.value(re_id).toString()+"\n");
        ui->listWidget->addItem("Hotel:"+query.value(re_hotel).toString()+"\n");
        ui->listWidget->addItem("Attraction:"+query.value(re_attraction).toString()+"\n");
        ui->listWidget->addItem("Guide:"+query.value(re_guide).toString()+"\n");
        ui->listWidget->addItem("Date:"+query.value(re_date).toString()+"\n");
        //ui->listWidget->addItem("ID:"+query.value(id).toString()+"\nPW:"+query.value(pw).toString()+"\nName:"+query.value(name).toString()+"\nPhone:"+query.value(phone).toString()+"\nVIP:"+query.value(vip).toString());
    }
    ui->check_btn->setText("내정보");
    slt=0;
}


void info::on_fix_btn_clicked()
{
    this->hide();
    reser reser(Input_ID);
    reser.setModal(true);
    reser.exec();
    this->show();
}
