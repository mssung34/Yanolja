#include "user.h"
#include "ui_user.h"
#include "split.h"

#include <QMessageBox>

using namespace std;

user::user(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::user)
{
    ui->setupUi(this);
    show_userlist();
}

void user::show_userlist()
{
    ui->list->clear();
    query_string = "SELECT * FROM userTBL";
    query.exec(QString::fromStdString(query_string));
    rec = query.record();
    int id_col = rec.indexOf("ID");
    int pw_col = rec.indexOf("PW");
    int name_col = rec.indexOf("name");
    int phone_col = rec.indexOf("phone");
    int vip_col = rec.indexOf("vip");
    while(query.next())
    {
        ui->list->addItem(query.value(id_col).toString() + "\t" + query.value(pw_col).toString()
                          + "\t" + query.value(name_col).toString() + "\t" + query.value(phone_col).toString()
                          + "\t" + query.value(vip_col).toString());
    }
}

user::~user()
{
    delete ui;
}

void user::on_exit_btn_clicked()
{
    this->close();
}

void user::on_vip_btn_clicked()
{
    QListWidgetItem *item = ui->list->currentItem();
    vector<string> user_data = split(item->text().toStdString(), '\t');
    qDebug()<<QString::fromStdString(user_data[4]);

    if(user_data[4] == "0")
    {
        query_string = "UPDATE userTBL SET VIP=1 WHERE ID='" + user_data[0] + "'";
        query.exec(QString::fromStdString(query_string));
    }
    else
    {
        query_string = "UPDATE userTBL SET VIP=0 WHERE ID='" + user_data[0] + "'";
        query.exec(QString::fromStdString(query_string));
    }
    QMessageBox::information(this, "OK", "수정 완료");
    show_userlist();
}

void user::on_del_btn_clicked()
{
    QListWidgetItem *item = ui->list->currentItem();
    vector<string> user_data = split(item->text().toStdString(), '\t');

    query.prepare("INSERT INTO outTBL (ID, PW, name, phone, vip) "
                      "VALUES (?, ?, ?, ?, ?)");
    for (int i = 0; i < 5; i++)
    {
        if(i == 4)
            query.addBindValue(stoi(user_data[i]));
        else
            query.addBindValue(QString::fromStdString(user_data[i]));
    }
    query.exec();

    query_string = "DELETE FROM userTBL WHERE ID='" + user_data[0] + "'";
    query.exec(QString::fromStdString(query_string));
    QMessageBox::information(this, "OK", "삭제 완료");
    show_userlist();
}
