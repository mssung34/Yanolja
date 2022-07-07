#ifndef RESERVATION_H
#define RESERVATION_H

#include <QDialog>
#include "database.h"
#include "edit.h"
#include <vector>
#include <cstring>

namespace Ui {
class reservation;
}

class reservation : public QDialog
{
    Q_OBJECT

public:
    explicit reservation(QWidget *parent = nullptr);
    void show_list();
    ~reservation();

private slots:
    void on_exit_btn_clicked();

    void on_add_btn_clicked();

    void on_edit_btn_clicked();

    void on_del_btn_clicked();

private:
    Ui::reservation *ui;

    std::string query_string;
    QSqlQuery query;
    QSqlRecord rec;
};

#endif // RESERVATION_H
