#include "change_pw.h"
#include "ui_change_pw.h"

change_pw::change_pw(std::string recv_ID,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::change_pw)
{
    Input_ID=recv_ID;
    ui->setupUi(this);
}

change_pw::~change_pw()
{
    delete ui;
}

void change_pw::on_out_btn_clicked()
{
    this->hide();
    info info(Input_ID);
    info.setModal(true);
    info.exec();
    this->show();
}

void change_pw::on_check_btn_clicked()
{
    query_string="SELECT PW FROM userTBL WHERE ID='"+Input_ID+"'";
    query.exec(QString::fromStdString(query_string));
    query.next();

    if(query.value(0) == ui->oldpw->text())
    {
        QMessageBox::information(this,"Error.","기존과 동일한 PW입니다");
    }
    else
    {
        QMessageBox::information(this,"succes","PW변경이 가능합니다.");
    }
}

void change_pw::on_change_btn_clicked()
{
    New_pw = ui->newpw->text().toStdString();
    if(ui->newpw->text() == ui->oldpw->text() && ui->newpw->text() !=query.value(0))
    {
        query_string="UPDATE userTBL SET PW='"+New_pw+"' WHERE ID='"+Input_ID+"'";
        query.exec(QString::fromStdString(query_string));
        QMessageBox::information(this,"succse","PW 변경이 완료되었습니다.");
        this->hide();
        menu menu(Input_ID);
        menu.setModal(true);
        menu.exec();
        this->show();
    }
    else
    {
        QMessageBox::information(this,"Error","PW를 확인해주세요.");
    }
}

