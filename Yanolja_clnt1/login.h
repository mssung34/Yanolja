#ifndef LOGIN_H
#define LOGIN_H

#include "signup.h"
#include "database.h"
#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class login; }
QT_END_NAMESPACE

class login : public QMainWindow
{
    Q_OBJECT

public:
    login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_login_btn_clicked();

    void on_signup_btn_clicked();

    void on_exit_btn_clicked();

private:
    Ui::login *ui;

    Database database;
    QSqlQuery query;
    std::string query_string;
};
#endif // LOGIN_H
