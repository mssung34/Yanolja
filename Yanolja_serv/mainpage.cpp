#include "mainpage.h"
#include "ui_mainpage.h"

mainpage::mainpage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::mainpage)
{
    ui->setupUi(this);
    this->move(800, 400);
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
    this->hide();
    beach beach;
    beach.setModal(true);
    beach.exec();
    this->show();
}

void mainpage::on_tour_btn_clicked()
{
    this->hide();
    tour tour;
    tour.setModal(true);
    tour.exec();
    this->show();
}

void mainpage::on_reservation_btn_clicked()
{
    this->hide();
    reservation reservation;
    reservation.setModal(true);
    reservation.exec();
    this->show();
}

void mainpage::on_guide_btn_clicked()
{
    this->hide();
    guide guide;
    guide.setModal(true);
    guide.exec();
    this->show();
}

void mainpage::on_exit_btn_clicked()
{
    this->close();
}

