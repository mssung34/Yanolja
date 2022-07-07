#ifndef TOUR_H
#define TOUR_H

#include <QDialog>
#include "database.h"
#include "edit.h"
#include <vector>
#include <cstring>

namespace Ui {
class tour;
}

class tour : public QDialog
{
    Q_OBJECT

public:
    explicit tour(QWidget *parent = nullptr);
    ~tour();
    void show_list();

private slots:
    void on_add_btn_clicked();

    void on_edit_btn_clicked();

    void on_del_btn_clicked();

    void on_exit_btn_clicked();

private:
    Ui::tour *ui;

    std::string query_string;
    QSqlQuery query;
    QSqlRecord rec;
};

#endif // TOUR_H
