#include "reser.h"
#include "ui_reser.h"

reser::reser(std::string recv_ID,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::reser)
{
    Input_ID=recv_ID;
    ui->setupUi(this);
    show_attraction();
    show_reservation();
}

reser::~reser()
{
    delete ui;
}

void reser::on_out_btn_clicked()
{
    this->hide();
    info info(Input_ID);
    info.setModal(true);
    info.exec();
    this->show();
}

void reser::show_attraction()
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
}

void reser::show_hotel()
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

void reser::show_guide()
{
    ui->tableWidget->clear();
    query_string="SELECT * FROM guideTBL";
    query.exec(QString::fromStdString(query_string));
    record=query.record();
    ui->tableWidget->setRowCount(query.size());
    ui->tableWidget->setColumnCount(record.count());
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("이름"));
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("전화번호"));
    ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("고용여부"));
    ui->tableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem("고용한 사람"));
    int g_name=record.indexOf("name");
    int g_phone=record.indexOf("phone");
    int g_possible=record.indexOf("possible");

    int i=0;
    while(query.next())
    {
      ui->tableWidget->setItem(i,0,new QTableWidgetItem(query.value(g_name).toString()));
      ui->tableWidget->setItem(i,1,new QTableWidgetItem(query.value(g_phone).toString()));
      ui->tableWidget->setItem(i,2,new QTableWidgetItem(query.value(g_possible).toString()));
      ui->tableWidget->setItem(i++,3,new QTableWidgetItem(QString::fromStdString(Input_ID)));
    }
    ui->slt_btn->setText("휴양지 정보");
    slt=0;
} // show_guide

void reser::on_slt_btn_clicked()
{
    if(slt==0)
        show_attraction();
    else if(slt==1)
        show_hotel();
    else if(slt==2)
        show_guide();
}

void reser::show_reservation()
{
    ui->listWidget->clear();
    query_string="SELECT * FROM reservationTBL WHERE ID='"+Input_ID+"'";
    query.exec(QString::fromStdString(query_string));
    record=query.record();
    int re_id=record.indexOf("ID");
    int re_hotel=record.indexOf("hotel");
    int re_attraction=record.indexOf("attraction");
    int re_guide=record.indexOf("guide");
    int re_date=record.indexOf("date");

    while(query.next())
    {
        ui->listWidget->addItem("ID:"+query.value(re_id).toString()+"\n");
        ui->listWidget->addItem("Hotel:"+query.value(re_hotel).toString()+"\n");
        ui->listWidget->addItem("Attraction:"+query.value(re_attraction).toString()+"\n");
        ui->listWidget->addItem("Guide:"+query.value(re_guide).toString()+"\n");
        ui->listWidget->addItem("Date:"+query.value(re_date).toString()+"\n");

    }
}


void reser::on_fixspot_clicked()
{
    New_spot = ui->input_attraction->text().toStdString();
    query_string="SELECT name FROM beachTBL where name='"+New_spot+"'";  //ID,hotel,attraction,guide,date
    query.exec(QString::fromStdString(query_string));
    query.first();
    if(query.size()==0)
        QMessageBox::information(this,"Error","존재하지 않은 관광지 입니다.");
    else
    {
        query_string="UPDATE reservationTBL SET attraction='"+New_spot+"' where ID='"+Input_ID+"'";
        query.exec(QString::fromStdString(query_string));
        QMessageBox::information(this,"succse","관광지 변경이 완료되었습니다.");
        show_reservation();
    }
}

void reser::on_fixhotel_clicked()
{
    New_hotel=ui->input_hotel->text().toStdString();
    query_string="SELECT name FROM tourTBL where name='"+New_hotel+"'";  //ID,hotel,attraction,guide,date
    query.exec(QString::fromStdString(query_string));
    query.first();
    if(query.size()==0)
        QMessageBox::information(this,"Error","존재하지 않은 호텔 입니다.");
    else
    {
        query_string="UPDATE reservationTBL SET hotel='"+New_hotel+"' where ID='"+Input_ID+"'";
        query.exec(QString::fromStdString(query_string));
        QMessageBox::information(this,"succse","호텔 변경이 완료되었습니다.");
        show_reservation();
    }
}

void reser::on_fixguide_clicked()
{
    New_guide=ui->input_guide->text().toStdString();
    query_string="SELECT name,possible FROM guideTBL where name='"+New_guide+"'";  //ID,hotel,attraction,guide,date
    query.exec(QString::fromStdString(query_string));
    query.first();
    if(query.size()==0)
        QMessageBox::information(this,"Error","존재하지 않은 가이드 입니다.");
    else
    {
        if(query.value(1).toString() == 'x')
            QMessageBox::information(this,"Error","고용이 불가능한 가이드 입니다.");
        else
        {
            query_string="UPDATE reservationTBL SET guide='"+New_guide+"' where ID='"+Input_ID+"'";
            query.exec(QString::fromStdString(query_string));
            QMessageBox::information(this,"succse","가이드 변경이 완료되었습니다.");
            show_reservation();
        }

    }
}

void reser::on_fixdate_clicked()
{
    New_date=ui->input_date->text().toStdString();
    query_string="SELECT * FROM reservationTBL";  //ID,hotel,attraction,guide,date
    query.exec(QString::fromStdString(query_string));

    query_string="UPDATE reservationTBL SET date='"+New_date+"' WHERE ID='"+Input_ID+"'";
    query.exec(QString::fromStdString(query_string));
    QMessageBox::information(this,"succse","날짜 변경이 완료되었습니다.");
    show_reservation();
}

void reser::on_delspot_clicked()
{
    New_spot = ui->input_attraction->text().toStdString();
    query_string="SELECT * FROM reservationTBL";  //ID,hotel,attraction,guide,date
    query.exec(QString::fromStdString(query_string));

    query_string="UPDATE reservationTBL SET attraction='" "' WHERE ID='"+Input_ID+"'";
    query.exec(QString::fromStdString(query_string));
    QMessageBox::information(this,"succse","관광지 취소가 완료되었습니다.");
    show_reservation();
}

void reser::on_delhotel_clicked()
{
    New_hotel = ui->input_hotel->text().toStdString();
    query_string="SELECT * FROM reservationTBL";  //ID,hotel,attraction,guide,date
    query.exec(QString::fromStdString(query_string));

    query_string="UPDATE reservationTBL SET hotel='" "' WHERE ID='"+Input_ID+"'";
    query.exec(QString::fromStdString(query_string));
    QMessageBox::information(this,"succse","호텔 취소가 완료되었습니다.");
    show_reservation();
}

void reser::on_delguide_clicked()
{
    New_guide = ui->input_guide->text().toStdString();
    query_string="SELECT * FROM reservationTBL";  //ID,hotel,attraction,guide,date
    query.exec(QString::fromStdString(query_string));

    query_string="UPDATE reservationTBL SET guide='" "' WHERE ID='"+Input_ID+"'";
    query.exec(QString::fromStdString(query_string));
    QMessageBox::information(this,"succse","가이드 취소가 완료되었습니다.");
    show_reservation();
}

void reser::on_delall_clicked()
{
    query_string="DELETE FROM reservationTBL WHERE ID='"+Input_ID+"'";
    query.exec(QString::fromStdString(query_string));
    query.first();
    QMessageBox::information(this,"succse","예약 취소가 완료되었습니다.");
    show_reservation();
}
