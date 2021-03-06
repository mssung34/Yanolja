#include "guide.h"
#include "ui_guide.h"
#include "split.h"

#include <QMessageBox>

using namespace std;

guide::guide(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::guide)
{
    ui->setupUi(this);
    show_guidelist();
}

void guide::show_guidelist()
{
    ui->list->clear();
    query_string = "SELECT * FROM guideTBL";
    query.exec(QString::fromStdString(query_string));
    rec = query.record();
    int name_col = rec.indexOf("name");
    int phone_col = rec.indexOf("phone");
    int possible_col = rec.indexOf("possible");
    int user_id_col = rec.indexOf("user_id");
    while(query.next())
    {
        ui->list->addItem(query.value(name_col).toString() + "\t" + query.value(phone_col).toString()
                          + "\t" + query.value(possible_col).toString() + "\t" + query.value(user_id_col).toString());
    }
}

guide::~guide()
{
    delete ui;
}

void guide::on_add_btn_clicked()
{
    query.prepare("INSERT INTO guideTBL (name, phone, possible, user_id) "
                      "VALUES (?, ?, ?, ?)");
    query.addBindValue(ui->name_text->text());
    query.addBindValue(ui->phone_text->text());
    query.addBindValue(ui->pos_text->text());
    query.addBindValue(ui->user_id_text->text());
    query.exec();
    QMessageBox::information(this, "OK", "등록 완료");
    show_guidelist();
}

void guide::on_change_btn_clicked()
{
    QListWidgetItem *item = ui->list->currentItem();
    vector<string> guide_data = split(item->text().toStdString(), '\t');
    query.exec("UPDATE guideTBL SET name='"+ui->name_text->text()+"', phone='"+
               ui->phone_text->text()+"',possible='" +ui->pos_text->text() +
               "', user_id='" + ui->user_id_text->text()+"'"+ "WHERE name='" + QString::fromStdString(guide_data[0]) + "'");
    QMessageBox::information(this, "OK", "수정 완료");
    show_guidelist();
}

void guide::on_del_btn_clicked()
{
    QListWidgetItem *item = ui->list->currentItem();
    vector<string> guide_data = split(item->text().toStdString(), '\t');
    query_string = "DELETE FROM guideTBL WHERE name='" + guide_data[0] + "'";
    query.exec(QString::fromStdString(query_string));
    QMessageBox::information(this, "OK", "삭제 완료");
    show_guidelist();
}

void guide::on_exit_btn_clicked()
{
    this->close();
}

void guide::on_list_itemClicked(QListWidgetItem *item)
{
    vector<string> guide_data = split(item->text().toStdString(), '\t');
    ui->name_text->setText(QString::fromStdString(guide_data[0]));
    ui->phone_text->setText(QString::fromStdString(guide_data[1]));
    ui->pos_text->setText(QString::fromStdString(guide_data[2]));
    ui->user_id_text->setText(QString::fromStdString(guide_data[3]));
}
