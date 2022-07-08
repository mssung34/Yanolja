#ifndef CHANGE_PW_H
#define CHANGE_PW_H

#include <QDialog>
#include "login.h"
#include "info.h"
#include "menu.h"

namespace Ui {
class change_pw;
}

class change_pw : public QDialog
{
    Q_OBJECT

public:
    explicit change_pw(std::string Input_ID,QWidget *parent = nullptr);
    ~change_pw();

private slots:
    void on_out_btn_clicked();

    void on_check_btn_clicked();

    void on_change_btn_clicked();

private:
    Ui::change_pw *ui;
    QSqlQuery query;
    std::string query_string;
    std::string Input_ID;
    std::string New_pw;
};

#endif // CHANGE_PW_H
