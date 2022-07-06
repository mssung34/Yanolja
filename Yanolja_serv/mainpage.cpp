#include "mainpage.h"
#include "ui_mainpage.h"

mainpage::mainpage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::mainpage)
{
    ui->setupUi(this);
}

mainpage::~mainpage()
{
    delete ui;
}

void mainpage::on_user_btn_clicked()
{
    this->hide();
    user user;
    user.setModal(true);
    user.exec();
    this->show();
}

void mainpage::on_beach_btn_clicked()
{

}

void mainpage::on_tour_btn_clicked()
{

}

void mainpage::on_guide_btn_clicked()
{

}

void mainpage::on_exit_btn_clicked()
{
    this->close();
}
