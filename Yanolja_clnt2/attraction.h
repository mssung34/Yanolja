#ifndef ATTRACTION_H
#define ATTRACTION_H

#include <QDialog>
#include <menu.h>
#include <date.h>

namespace Ui {
class attraction;
}

class attraction : public QDialog
{
    Q_OBJECT

public:
    explicit attraction(std::string Input_ID,QWidget *parent = nullptr);
    void show_attraction();
    void show_hotel();
    void show_guide();
    void take_reservation();
    ~attraction();

private slots:
    void on_out_btn_clicked();
    void on_slt_btn_clicked();


    void on_take_btn_clicked();

private:
    Ui::attraction *ui;
    QSqlQuery query;
    QSqlRecord record;
    std::string query_string;
    std::string Input_ID;
    int slt=0;  // attraction:1 / hotel:0 // guide=2
};

#endif // ATTRACTION_H
