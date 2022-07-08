#ifndef BEACH_H
#define BEACH_H

#include <QDialog>
#include "database.h"
#include "edit.h"
#include <vector>
#include <cstring>

namespace Ui {
class beach;
}

class beach : public QDialog
{
    Q_OBJECT

public:
    explicit beach(QWidget *parent = nullptr);
    ~beach();
    void show_list();

private slots:
    void on_add_btn_clicked();

    void on_edit_btn_clicked();

    void on_del_btn_clicked();

    void on_exit_btn_clicked();

private:
    Ui::beach *ui;

    std::string query_string;
    QSqlQuery query;
    QSqlRecord rec;
};

#endif // BEACH_H
