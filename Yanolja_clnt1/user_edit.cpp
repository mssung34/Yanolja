#include "user_edit.h"
#include "ui_user_edit.h"

user_edit::user_edit(std::vector<std::string> data, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::user_edit)
{
    ui->setupUi(this);
    ui->id_text->setText(QString::fromStdString(data[0]));
    ui->pw_text->setText(QString::fromStdString(data[1]));
    ui->name_text->setText(QString::fromStdString(data[2]));
    ui->phone_text->setText(QString::fromStdString(data[3]));
}

user_edit::~user_edit()
{
    delete ui;
}

void user_edit::on_ok_btn_clicked()
{
    query_string = "UPDATE userTBL SET PW='" + ui->pw_text->text().toStdString() + "', name='" + ui->name_text->text().toStdString()
            + "', phone='" + ui->phone_text->text().toStdString() + "' WHERE ID='" + ui->id_text->text().toStdString() + "'";
    query.exec(QString::fromStdString(query_string));
    QMessageBox::information(this, "OK", "수정 완료");
    this->close();
}

void user_edit::on_exit_btn_clicked()
{
    this->close();
}
