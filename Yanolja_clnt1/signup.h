#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>
#include <database.h>
#include <cstring>

namespace Ui {
class signup;
}

class signup : public QDialog
{
    Q_OBJECT

public:
    explicit signup(QWidget *parent = nullptr);
    ~signup();

private slots:
    void on_check_btn_clicked();

    void on_signup_btn_clicked();

    void on_exit_btn_clicked();

private:
    Ui::signup *ui;

    Database database;
    QSqlQuery query;
    std::string query_string;

    bool ischeck;
};

#endif // SIGNUP_H
