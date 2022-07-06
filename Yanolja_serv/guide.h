#ifndef GUIDE_H
#define GUIDE_H

#include "database.h"
#include <QDialog>
#include <QListWidgetItem>


namespace Ui {
class guide;
}

class guide : public QDialog
{
    Q_OBJECT

public:
    explicit guide(QWidget *parent = nullptr);
    void show_guidelist();
    ~guide();

private slots:
    void on_add_btn_clicked();

    void on_change_btn_clicked();

    void on_del_btn_clicked();

    void on_exit_btn_clicked();

    void on_list_itemClicked(QListWidgetItem *item);

private:
    Ui::guide *ui;

    QSqlQuery query;
    QSqlRecord rec;
    std::string query_string;
};

#endif // GUIDE_H
