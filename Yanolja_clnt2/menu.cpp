#include "menu.h"
#include "ui_menu.h"
#include "login.h"
#include "info.h"
#include "attraction.h"

menu::menu(std::string recv_ID,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
    Input_ID=recv_ID;
}

menu::~menu()
{
    delete ui;
}

void menu::on_attraction_btn_clicked()
{
    this->hide();
    attraction attraction(Input_ID);
    attraction.setModal(true);
    attraction.exec();
    this->show();
}

void menu::on_lofo_btn_clicked()
{
    this->hide();
    info info(Input_ID);
    info.setModal(true);
    info.exec();
    this->show();
}

void menu::on_out_btn_clicked()
{
    this->close();
}
