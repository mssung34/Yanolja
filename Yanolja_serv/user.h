#ifndef USER_H
#define USER_H

#include "database.h"
#include <iostream>
#include <vector>
#include <cstring>
#include <QDialog>

namespace Ui {
class user;
}

class user : public QDialog
{
    Q_OBJECT

public:
    explicit user(QWidget *parent = nullptr);
    void show_userlist();
    ~user();

private slots:
    void on_exit_btn_clicked();

    void on_vip_btn_clicked();

    void on_del_btn_clicked();

private:
    Ui::user *ui;

    std::string query_string;
    QSqlQuery query;
    QSqlRecord rec;
};

#endif // USER_H
