#include "signup.h"
#include "ui_signup.h"
#include "login.h"
#include "database.h"
#include <QMessageBox>

signup::signup(std::string recv_ID,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signup)
{
    ui->setupUi(this);
    check=false;
    Input_ID=recv_ID;
}

signup::~signup()
{
    delete ui;
}

void signup::on_id_check_clicked()
{
    query_string="SELECT ID FROM userTBL WHERE ID='"+ui->id_input->text().toStdString()+"'";
    query.exec(QString::fromStdString(query_string));
    if(query.size()==0)
    {
        QMessageBox::information(this,"Success","사용가능한 ID입니다.");
        check=true;
    }
    else
    {
        QMessageBox::information(this,"Fail","이미 사용하고있는 ID입니다.");
    }
}

void signup::on_singup_btn_clicked()
{
    if(check==false)
    {
        QMessageBox::warning(this,"Fail","ID 중복을 확인하세요");
    }
    else
    {
        if(ui->pw_input->text() == ui->pw_check->text()) //비번확인 성공
        {
            query.prepare("INSERT INTO userTBL (ID,PW,name,phone,vip)" "VALUES (?,?,?,?,?)");
            query.addBindValue(ui->id_input->text());
            query.addBindValue(ui->pw_input->text());
            query.addBindValue(ui->name_input->text());
            query.addBindValue(ui->phone_input->text());
            query.addBindValue(vip);
            query.exec();
            QMessageBox::information(this,"축하합니다","회원가입 완료");
            this->close();
        }
        else
        {
            QMessageBox::information(this,"Error","PW를 확인해주세요");
        }

    }

}

void signup::on_out_btn_clicked()  // 나가기버튼
{
    this->close();
}
