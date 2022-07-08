#include "reservation.h"
#include "ui_reservation.h"

#include <QMessageBox>

reservation::reservation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::reservation)
{
    ui->setupUi(this);
    show_list();
}

void reservation::show_list()
{
    ui->list->clear();
    query_string = "SELECT * FROM reservationTBL";
    query.exec(QString::fromStdString(query_string));
    rec = query.record();
    int id_col = rec.indexOf("ID");
    int hotel_col = rec.indexOf("hotel");
    int attraction_col = rec.indexOf("attraction");
    int guide_col = rec.indexOf("guide");
    int date_col = rec.indexOf("date");
    ui->list->setRowCount(query.size());
    ui->list->setColumnCount(rec.count());
    ui->list->setHorizontalHeaderItem(0, new QTableWidgetItem("ID"));
    ui->list->setHorizontalHeaderItem(1, new QTableWidgetItem("숙박"));
    ui->list->setHorizontalHeaderItem(2, new QTableWidgetItem("관광지"));
    ui->list->setHorizontalHeaderItem(3, new QTableWidgetItem("가이드"));
    ui->list->setHorizontalHeaderItem(4, new QTableWidgetItem("날짜"));
    int i=0;
    while(query.next())
    {
        ui->list->setItem(i,0,new QTableWidgetItem(query.value(id_col).toString()));
        ui->list->setItem(i,1,new QTableWidgetItem(query.value(hotel_col).toString()));
        ui->list->setItem(i,2,new QTableWidgetItem(query.value(attraction_col).toString()));
        ui->list->setItem(i,3,new QTableWidgetItem(query.value(guide_col).toString()));
        ui->list->setItem(i++,4,new QTableWidgetItem(query.value(date_col).toString()));
    }
}

reservation::~reservation()
{
    delete ui;
}

void reservation::on_exit_btn_clicked()
{
    this->close();
}

void reservation::on_add_btn_clicked()
{
    edit edit("reservationTBL");
    edit.setModal(true);
    edit.exec();
    show_list();
}

void reservation::on_edit_btn_clicked()
{
    std::vector<std::string> data;
    int row = ui->list->currentRow();
    data.push_back(ui->list->takeItem(row, 0)->text().toStdString());
    data.push_back(ui->list->takeItem(row, 1)->text().toStdString());
    data.push_back(ui->list->takeItem(row, 2)->text().toStdString());
    data.push_back(ui->list->takeItem(row, 3)->text().toStdString());
    data.push_back(ui->list->takeItem(row, 4)->text().toStdString());

    edit edit("reservationTBL", data);
    edit.setModal(true);
    edit.exec();
    show_list();
}

void reservation::on_del_btn_clicked()
{
    int row = ui->list->currentRow();
    query_string = "DELETE FROM reservationTBL WHERE ID='" + ui->list->takeItem(row, 0)->text().toStdString() + "'";
    query.exec(QString::fromStdString(query_string));
    QMessageBox::information(this, "OK", "삭제 완료");
    show_list();
}
