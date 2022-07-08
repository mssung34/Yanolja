#include "date.h"
#include "ui_date.h"

date::date(std::string recv_ID,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::date)
{
    Input_ID = recv_ID;
    ui->setupUi(this);
}

date::~date()
{
    delete ui;
}
