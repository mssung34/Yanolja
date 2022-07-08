#ifndef MENU_H
#define MENU_H

#include <QDialog>
#include "login.h"


namespace Ui {
class menu;
}

class menu : public QDialog
{
    Q_OBJECT

public:
    explicit menu(std::string Input_ID,QWidget *parent = nullptr);
    ~menu();

private slots:
    void on_attraction_btn_clicked();

    void on_lofo_btn_clicked();

    void on_out_btn_clicked();

private:
    Ui::menu *ui;
    QSqlQuery query;
    std::string query_string;
    std::string Input_ID;
};

#endif // MENU_H
