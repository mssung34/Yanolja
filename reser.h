#ifndef RESER_H
#define RESER_H

#include <QDialog>
#include <attraction.h>
#include "info.h"

namespace Ui {
class reser;
}

class reser : public QDialog
{
    Q_OBJECT

public:
    explicit reser(std::string Input_ID,QWidget *parent = nullptr);
    void show_attraction();
    void show_hotel();
    void show_guide();
    void show_reservation();
    ~reser();

private slots:
    void on_slt_btn_clicked();

    void on_out_btn_clicked();


    void on_fixspot_clicked();

    void on_fixhotel_clicked();

    void on_fixguide_clicked();

    void on_delspot_clicked();

    void on_delhotel_clicked();

    void on_delguide_clicked();

    void on_fixdate_clicked();

    void on_delall_clicked();

private:
    Ui::reser *ui;
    QSqlQuery query;
    QSqlRecord record;
    std::string query_string;
    std::string Input_ID;
    std::string New_spot;
    std::string New_hotel;
    std::string New_guide;
    std::string New_date;
    int slt=0;  // attraction:1 / hotel:0 // guide=2
};

#endif // RESER_H
