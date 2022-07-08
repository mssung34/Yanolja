#ifndef WITHDRAW_H
#define WITHDRAW_H

#include <QDialog>
#include "login.h"
#include "info.h"
#include "menu.h"

namespace Ui {
class withdraw;
}

class withdraw : public QDialog
{
    Q_OBJECT

public:
    explicit withdraw(std::string Input_ID,QWidget *parent = nullptr);
    ~withdraw();

private slots:
    void on_out_btn_clicked();

    void on_withdraw_btn_clicked();

private:
    Ui::withdraw *ui;
    QSqlQuery query;
    std::string query_string;
    std::string Input_ID;
    std::string withdraw_id;
    std::string id;
    std::string pw;
    std::string name;
    std::string phone;
    int vip;

};

#endif // WITHDRAW_H
