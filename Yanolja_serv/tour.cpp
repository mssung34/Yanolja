#include "tour.h"
#include "ui_tour.h"
#include "split.h"

#include <QMessageBox>

tour::tour(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tour)
{
    ui->setupUi(this);
    show_list();
}

tour::~tour()
{
    delete ui;
}

void tour::show_list()
{
    ui->list->clear();
    query_string = "SELECT * FROM tourTBL";
    query.exec(QString::fromStdString(query_string));
    rec = query.record();
    int name_col = rec.indexOf("name");
    int addr_col = rec.indexOf("address");
    int phone_col = rec.indexOf("phone");
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
        ui->list->setItem(i++,2,new QTableWidgetItem(query.value(phone_col).toString()));
    }
}

void tour::on_add_btn_clicked()
{
    edit edit("tourTBL");
    edit.setModal(true);
    edit.exec();
    show_list();
}

void tour::on_edit_btn_clicked()
{
    std::vector<std::string> data;
    int row = ui->list->currentRow();
    data.push_back(ui->list->takeItem(row, 0)->text().toStdString());
    data.push_back(ui->list->takeItem(row, 1)->text().toStdString());
    data.push_back(ui->list->takeItem(row, 2)->text().toStdString());

    edit edit("tourTBL", data);
    edit.setModal(true);
    edit.exec();
    show_list();
}

void tour::on_del_btn_clicked()
{
    int row = ui->list->currentRow();
    query_string = "DELETE FROM tourTBL WHERE name='" + ui->list->takeItem(row, 0)->text().toStdString() + "'";
    query.exec(QString::fromStdString(query_string));
    QMessageBox::information(this, "OK", "삭제 완료");
    show_list();
}

void tour::on_exit_btn_clicked()
{
    this->close();
}
