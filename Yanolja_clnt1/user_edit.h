#ifndef USER_EDIT_H
#define USER_EDIT_H

#include <QDialog>
#include <vector>
#include "database.h"
#include <QMessageBox>

namespace Ui {
class user_edit;
}

class user_edit : public QDialog
{
    Q_OBJECT

public:
    explicit user_edit(std::vector<std::string> data, QWidget *parent = nullptr);
    ~user_edit();

private slots:
    void on_ok_btn_clicked();

    void on_exit_btn_clicked();

private:
    Ui::user_edit *ui;
    QSqlQuery query;
    std::string query_string;
};

#endif // USER_EDIT_H
