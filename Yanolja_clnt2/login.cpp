#include "login.h"
#include "ui_login.h"
#include "menu.h"
#include <QMessageBox>

login::login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}



void login::on_login_btn_clicked()  // 로그인버튼
{
    query_string="SELECT PW,vip FROM userTBL WHERE ID='"+ui->id_input->text().toStdString()+"'";
    query.exec(QString::fromStdString(query_string));
    std::string Input_ID=ui->id_input->text().toStdString();

    if(query.size()==0)
    {
        QMessageBox::warning(this,"error","존재하지 않는 ID 입니다."); // 쿼리문에서 못찾을경우 --> 아이디가 없음 ㅇㅇ
    }
    else
    {
        query.next();
        if(query.value(0) == ui->pw_input->text())  // 비번
        {
            if(query.value(1)==1)  //vip일경우
            {
             QMessageBox::information(this,"success","VIP회원님 환영합니다.");
             this->hide();
             menu menu(Input_ID);
             menu.setModal(true);
             menu.exec();
             this->show();
            }
            else
            {
             QMessageBox::warning(this,"error","VIP회원만 로그인 가능합니다.");
            }
        }
        else
        {
            QMessageBox::warning(this,"PW error","비밀번호를 확인해주세요.");
        }

    }
}

void login::on_signup_btn_clicked()
{
    this->hide();
    signup signup(Input_ID);
    signup.setModal(true);
    signup.exec();
    this->show();
}

void login::on_out_btn_clicked()
{
    this->close();
}
