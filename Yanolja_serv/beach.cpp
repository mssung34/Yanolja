#include "beach.h"
#include "ui_beach.h"

#include <QMessageBox>

beach::beach(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::beach)
{
    ui->setupUi(this);
    show_list();
}

void beach::show_list()
{
    ui->list->clear();
    query_string = "SELECT * FROM beachTBL";
    query.exec(QString::fromStdString(query_string));
    rec = query.record();
    int name_col = rec.indexOf("name");
    int toilet_col = rec.indexOf("toilet");
    int shower_col = rec.indexOf("shower");
    int parking_col = rec.indexOf("parking");
    ui->list->setRowCount(query.size());
    ui->list->setColumnCount(rec.count());
    ui->list->setHorizontalHeaderItem(0, new QTableWidgetItem("이름"));
    ui->list->setHorizontalHeaderItem(1, new QTableWidgetItem("화장실"));
    ui->list->setHorizontalHeaderItem(2, new QTableWidgetItem("샤워장"));
    ui->list->setHorizontalHeaderItem(3, new QTableWidgetItem("주차장"));
    int i=0;
    while(query.next())
    {
        ui->list->setItem(i,0,new QTableWidgetItem(query.value(name_col).toString()));
        ui->list->setItem(i,1,new QTableWidgetItem(query.value(toilet_col).toString()));
        ui->list->setItem(i,2,new QTableWidgetItem(query.value(shower_col).toString()));
        ui->list->setItem(i++,3,new QTableWidgetItem(query.value(parking_col).toString()));
    }
}

beach::~beach()
{
    delete ui;
}

void beach::on_add_btn_clicked()
{
    edit edit("beachTBL");
    edit.setModal(true);
    edit.exec();
    show_list();
}

void beach::on_edit_btn_clicked()
{
    std::vector<std::string> data;
    int row = ui->list->currentRow();
    data.push_back(ui->list->takeItem(row, 0)->text().toStdString());
    data.push_back(ui->list->takeItem(row, 1)->text().toStdString());
    data.push_back(ui->list->takeItem(row, 2)->text().toStdString());
    data.push_back(ui->list->takeItem(row, 3)->text().toStdString());

    edit edit("beachTBL", data);
    edit.setModal(true);
    edit.exec();
    show_list();
}

void beach::on_del_btn_clicked()
{
    int row = ui->list->currentRow();
    query_string = "DELETE FROM beachTBL WHERE name='" + ui->list->takeItem(row, 0)->text().toStdString() + "'";
    query.exec(QString::fromStdString(query_string));
    QMessageBox::information(this, "OK", "삭제 완료");
    show_list();
}

void beach::on_exit_btn_clicked()
{
    this->close();
}
