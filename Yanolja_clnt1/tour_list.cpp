#include "tour_list.h"
#include "ui_tour_list.h"

tour_list::tour_list(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tour_list)
{
    ui->setupUi(this);
    show_beach();
}


tour_list::~tour_list()
{
    delete ui;
}

void tour_list::show_tour()
{
    ui->list->clear();
    query_string = "SELECT * FROM tourTBL";
    query.exec(QString::fromStdString(query_string));
    rec = query.record();
    int name_col = rec.indexOf("name");
    int addr_col = rec.indexOf("address");
    int parking_col = rec.indexOf("parking");
    int credit_col = rec.indexOf("credit");
    while(query.next())
    {
        ui->list->addItem(query.value(name_col).toString() + "\t\t" + query.value(addr_col).toString()
                          + "\t\t" + query.value(parking_col).toString() + "\t\t" + query.value(credit_col).toString());
    }
    ui->slt_btn->setText("해수욕장 정보");
    slt = true;
}

void tour_list::show_beach()
{
    ui->list->clear();
    query_string = "SELECT * FROM beachTBL";
    query.exec(QString::fromStdString(query_string));
    rec = query.record();
    int name_col = rec.indexOf("name");
    int toilet_col = rec.indexOf("toilet");
    int shower_col = rec.indexOf("shower");
    int parking_col = rec.indexOf("parking");
    while(query.next())
    {
        ui->list->addItem(query.value(name_col).toString() + "\t\t" + query.value(toilet_col).toString()
                          + "\t\t" + query.value(shower_col).toString() + "\t\t" + query.value(parking_col).toString());
    }
    ui->slt_btn->setText("숙박/식당 정보");
    slt = false;
}

void tour_list::on_slt_btn_clicked()
{
    if(slt)
        show_beach();
    else
        show_tour();
}

void tour_list::on_exit_btn_clicked()
{
    this->close();
}
