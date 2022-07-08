#include "attraction.h"
#include "login.h"
#include "menu.h"
#include "date.h"
#include "ui_attraction.h"

attraction::attraction(std::string recv_ID,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::attraction)
{
    Input_ID=recv_ID;
    ui->setupUi(this);
    show_attraction();
}

attraction::~attraction()
{
    delete ui;
}

void attraction::on_out_btn_clicked()
{
    this->hide();
    menu menu(Input_ID);
    menu.setModal(true);
    menu.exec();
    this->show();
}

void attraction::show_attraction()
{
    ui->tableWidget->clear();
    query_string="SELECT * FROM beachTBL";
    query.exec(QString::fromStdString(query_string));
    record=query.record();
    ui->tableWidget->setRowCount(query.size());
    ui->tableWidget->setColumnCount(record.count());
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("이름"));
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("화장실"));
    ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("샤워장"));
    ui->tableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem("주차장"));
    int at_name=record.indexOf("name");
    int at_toilet=record.indexOf("toilet");
    int at_shower=record.indexOf("shower");
    int at_parking=record.indexOf("parking");
    int i=0;
    while(query.next())
    {
      ui->tableWidget->setItem(i,0,new QTableWidgetItem(query.value(at_name).toString()));
      ui->tableWidget->setItem(i,1,new QTableWidgetItem(query.value(at_toilet).toString()));
      ui->tableWidget->setItem(i,2,new QTableWidgetItem(query.value(at_shower).toString()));
      ui->tableWidget->setItem(i++,3,new QTableWidgetItem(query.value(at_parking).toString()));
    }
    ui->slt_btn->setText("호탤 정보");
    slt=1;
} // show_attraction

void attraction::show_hotel()
{
    ui->tableWidget->clear();
    query_string="SELECT * FROM tourTBL";
    query.exec(QString::fromStdString(query_string));
    record=query.record();
    ui->tableWidget->setRowCount(query.size());
    ui->tableWidget->setColumnCount(record.count());
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("시설명"));
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("주소"));
    ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("전화번호"));
    int ht_name=record.indexOf("name");
    int ht_addr=record.indexOf("address");
    int ht_phone=record.indexOf("phone");

    int i=0;
    while(query.next())
    {
      ui->tableWidget->setItem(i,0,new QTableWidgetItem(query.value(ht_name).toString()));
      ui->tableWidget->setItem(i,1,new QTableWidgetItem(query.value(ht_addr).toString()));
      ui->tableWidget->setItem(i++,2,new QTableWidgetItem(query.value(ht_phone).toString()));
    }
    ui->slt_btn->setText("가이드 정보");
    slt=2;
} // show_hotel

void attraction::show_guide()
{
    ui->tableWidget->clear();
    query_string="SELECT name,phone,possible FROM guideTBL";
    query.exec(QString::fromStdString(query_string));
    record=query.record();
    ui->tableWidget->setRowCount(query.size());
    ui->tableWidget->setColumnCount(record.count());
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("이름"));
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("전화번호"));
    ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("고용여부"));

    int g_name=record.indexOf("name");
    int g_phone=record.indexOf("phone");
    int g_possible=record.indexOf("possible");


    int i=0;
    while(query.next())
    {
      ui->tableWidget->setItem(i,0,new QTableWidgetItem(query.value(g_name).toString()));
      ui->tableWidget->setItem(i,1,new QTableWidgetItem(query.value(g_phone).toString()));
      ui->tableWidget->setItem(i++,2,new QTableWidgetItem(query.value(g_possible).toString()));
    }
    ui->slt_btn->setText("휴양지 정보");
    slt=0;
} // show_guide


void attraction::on_slt_btn_clicked()
{
    if(slt==0)
        show_attraction();
    else if(slt==1)
        show_hotel();
    else if(slt==2)
        show_guide();

}

void attraction::on_take_btn_clicked()
{
    int can_re=0;
    int spot_error=0;
    int hotel_error=0;
    int guide_error=0;
    query_string="SELECT name FROM beachTBL WHERE name='"+ui->input_attraction->text().toStdString()+"'";
    query.exec(QString::fromStdString(query_string));
    query.first();
    if(query.size()==0)
    {
        QMessageBox::information(this,"Error","존재하지 않은 관광지 입니다.");
        spot_error++;
    }
    else
    {
        can_re++;
        spot_error=0;
    }
    // 관광지 조건

    query_string="SELECT name FROM tourTBL WHERE name='"+ui->input_hotel->text().toStdString()+"'";
    query.exec(QString::fromStdString(query_string));
    query.first();
    if(query.size()==0)
    {
        QMessageBox::information(this,"Error","존재하지 않은 호텔 입니다.");
        hotel_error++;
    }
    else
    {
        can_re++;
        hotel_error=0;
    }
    // 호탤 조건

    query_string="SELECT name,possible FROM guideTBL WHERE name='"+ui->input_guide->text().toStdString()+"'";
    query.exec(QString::fromStdString(query_string));
    query.first();
    if(query.size()==0)
    {
        QMessageBox::information(this,"Error","존재하지 않은 가이드 입니다.");
        guide_error++;
    }
    else
    {
        if(query.value(1).toString()=='x')
        {
            QMessageBox::information(this,"Error","고용이 불가능한 가이드 입니다.");
            guide_error++;
        }
        else
        {
            can_re++;
            guide_error=0;
        }

    } // 가이드 조건

    if(can_re!=0 && spot_error==0 && hotel_error==0 && guide_error==0)
    {
        take_reservation();
        can_re=0;
    }
    /*this->hide();
    menu menu(Input_ID);
    menu.setModal(true);
    menu.exec();
    this->show();*/

} // push_take_btn

void attraction::take_reservation()
{
    QString date = ui->calendarWidget->selectedDate().toString("yyyy년 MM월 dd일");
    query.prepare("INSERT INTO reservationTBL (ID,hotel,attraction,guide,date)" "VALUES (?,?,?,?,?)");
    query.addBindValue(QString::fromStdString(Input_ID));
    query.addBindValue(ui->input_hotel->text());
    query.addBindValue(ui->input_attraction->text());
    query.addBindValue(ui->input_guide->text());
    query.addBindValue(date);
    query.exec();

    query_string="UPDATE guideTBL SET possible='x' WHERE name='"+ui->input_guide->text().toStdString()+"'";
    query.exec(QString::fromStdString(query_string));

    QMessageBox::information(this,"축하합니다","예약이 완료되었습니다.");

} // take_reservation()
