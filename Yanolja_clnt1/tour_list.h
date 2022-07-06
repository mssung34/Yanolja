#ifndef TOUR_LIST_H
#define TOUR_LIST_H

#include "database.h"
#include <QDialog>

namespace Ui {
class tour_list;
}

class tour_list : public QDialog
{
    Q_OBJECT

public:
    explicit tour_list(QWidget *parent = nullptr);
    void show_tour();
    void show_beach();
    ~tour_list();

private slots:
    void on_slt_btn_clicked();

    void on_exit_btn_clicked();

private:
    Ui::tour_list *ui;

    QSqlQuery query;
    QSqlRecord rec;
    std::string query_string;

    bool slt = false; //tour : 0 / beach : 1
};

#endif // TOUR_LIST_H
