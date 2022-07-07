#include "edit.h"
#include "ui_edit.h"

#include <QMessageBox>


edit::edit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edit)
{
    ui->setupUi(this);
}

edit::edit(std::string type, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edit)
{
    ui->setupUi(this);
    this->type = type;
    if(type == "tourTBL")
    {
        ui->label4->hide();
        ui->text4->hide();
        ui->label1->setText("이름");
        ui->label2->setText("주소");
        ui->label3->setText("전화번호");
    }
    else if(type == "beachTBL")
    {
        ui->label1->setText("이름");
        ui->label2->setText("화장실");
        ui->label3->setText("샤워장");
        ui->label4->setText("주차장");
    }
    is_add = true;
}

edit::edit(std::string type,std::vector<std::string> data , QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edit)
{
    ui->setupUi(this);
    this->type = type;
    if(type == "tourTBL")
    {
        ui->label4->hide();
        ui->text4->hide();
        ui->label1->setText("이름");
        ui->label2->setText("주소");
        ui->label3->setText("전화번호");
        ui->text1->setText(QString::fromStdString(data[0]));
        ui->text2->setText(QString::fromStdString(data[1]));
        ui->text3->setText(QString::fromStdString(data[2]));
    }
    else if(type == "beachTBL")
    {
        ui->label1->setText("이름");
        ui->label2->setText("화장실");
        ui->label3->setText("샤워장");
        ui->label4->setText("주차장");
        ui->text1->setText(QString::fromStdString(data[0]));
        ui->text2->setText(QString::fromStdString(data[1]));
        ui->text3->setText(QString::fromStdString(data[2]));
        ui->text4->setText(QString::fromStdString(data[3]));
    }
    else
    {
        QMessageBox::warning(this, "error", "type error");
        this->close();
    }
    name_str = data[0];
    is_add = false;
}

edit::~edit()
{
    delete ui;
}

void edit::on_ok_btn_clicked()
{
    if(is_add)
    {
        if(type == "tourTBL")
        {
            query.prepare("INSERT INTO tourTBL (name, address, phone) "
                          "VALUES (?, ?, ?)");
            query.addBindValue(ui->text1->text());
            query.addBindValue(ui->text2->text());
            query.addBindValue(ui->text3->text());
            query.exec();
            QMessageBox::information(this, "OK", "등록 완료");
            this->close();
        }
        else if(type == "beachTBL")
        {
            query.prepare("INSERT INTO beachTBL (name, toilet, shower, parking) "
                          "VALUES (?, ?, ?, ?)");
            query.addBindValue(ui->text1->text());
            query.addBindValue(ui->text2->text().toInt());
            query.addBindValue(ui->text3->text().toInt());
            query.addBindValue(ui->text4->text().toInt());
            query.exec();
            QMessageBox::information(this, "OK", "등록 완료");
            this->close();
        }
    }
    else
    {
        if(type == "tourTBL")
        {
            query_string = "UPDATE tourTBL SET name='" + ui->text1->text().toStdString() + "', address='" +
                    ui->text2->text().toStdString() + "', phone='" + ui->text3->text().toStdString() + "' WHERE name='"
                    + name_str + "'";
            query.exec(QString::fromStdString(query_string));
            QMessageBox::information(this, "OK", "수정 완료");
            this->close();
        }
        else if(type == "beachTBL")
        {
            query_string = "UPDATE beachTBL SET name='" + ui->text1->text().toStdString() + "', toilet=" +
                    ui->text2->text().toStdString() + ", shower=" + ui->text3->text().toStdString() + ", parking="
                    + ui->text4->text().toStdString() + " WHERE name='" + name_str + "'";
            query.exec(QString::fromStdString(query_string));
            QMessageBox::information(this, "OK", "수정 완료");
            this->close();
        }
    }
}

void edit::on_exit_btn_clicked()
{
    this->close();
}
