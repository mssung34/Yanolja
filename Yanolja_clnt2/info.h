#ifndef INFO_H
#define INFO_H

#include <QDialog>
#include "login.h"
#include <iostream>
#include <cstring>
#include <string>
#include "change_pw.h"
#include "withdraw.h"
#include "reser.h"


namespace Ui {
class info;
}

class info : public QDialog
{
    Q_OBJECT

public:
    explicit info(std::string Input_ID,QWidget *parent = nullptr);
    void show_info();
    ~info();

private slots:

    void on_out_btn_clicked();
    void on_change_pw_clicked();
    void on_withdraw_btn_clicked();
    void on_check_btn_clicked();
    void show_reservation();

    void on_fix_btn_clicked();

private:
    Ui::info *ui;
    QSqlQuery query;
    QSqlRecord record;
    std::string query_string;
    std::string Input_ID;
    int slt=0;
};

#endif // INFO_H
