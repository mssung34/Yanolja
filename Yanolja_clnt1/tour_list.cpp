#include "tour_list.h"
#include "ui_tour_list.h"
#include <vector>

tour_list::tour_list(std::string id, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tour_list)
{
    ui->setupUi(this);
    show_beach();
    this->id = id;
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
    int parking_col = rec.indexOf("phone");
    ui->list->setRowCount(query.size());
    ui->list->setColumnCount(rec.count());
    ui->list->setHorizontalHeaderItem(0, new QTableWidgetItem("시설명"));
    ui->list->setHorizontalHeaderItem(1, new QTableWidgetItem("주소"));
    ui->list->setHorizontalHeaderItem(2, new QTableWidgetItem("전화번호"));
    int i=0;
    while(query.next())
    {
        ui->list->setItem(i,0,new QTableWidgetItem(query.value(name_col).toString()));
        ui->list->setItem(i,1,new QTableWidgetItem(query.value(addr_col).toString()));
        ui->list->setItem(i++,2,new QTableWidgetItem(query.value(parking_col).toString()));
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
    ui->list->setRowCount(query.size());
    ui->list->setColumnCount(rec.count());
    ui->list->setHorizontalHeaderItem(0, new QTableWidgetItem("이름"));
    ui->list->setHorizontalHeaderItem(1, new QTableWidgetItem("화장실"));
    ui->list->setHorizontalHeaderItem(2, new QTableWidgetItem("샤워장"));
    ui->list->setHorizontalHeaderItem(3, new QTableWidgetItem("주차장"));
    int name_col = rec.indexOf("name");
    int toilet_col = rec.indexOf("toilet");
    int shower_col = rec.indexOf("shower");
    int parking_col = rec.indexOf("parking");
    int i=0;
    while(query.next())
    {
        ui->list->setItem(i,0,new QTableWidgetItem(query.value(name_col).toString()));
        ui->list->setItem(i,1,new QTableWidgetItem(query.value(toilet_col).toString()));
        ui->list->setItem(i,2,new QTableWidgetItem(query.value(shower_col).toString()));
        ui->list->setItem(i++,3,new QTableWidgetItem(query.value(parking_col).toString()));
    }
    ui->slt_btn->setText("숙박 정보");
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

void tour_list::on_user_btn_clicked()
{
    query_string = "SELECT * FROM userTBL WHERE ID='" + id + "'";
    query.exec(QString::fromStdString(query_string));
    query.next();
    std::vector<std::string> data;
    for(int i = 0; i < 4; i++)
    {
        data.push_back(query.value(i).toString().toStdString());
    }
    user_edit user(data);
    user.setModal(true);
    user.exec();
}
