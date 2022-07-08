#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include "database.h"
#include "signup.h"

QT_BEGIN_NAMESPACE
namespace Ui { class login; }
QT_END_NAMESPACE

class login : public QMainWindow
{
    Q_OBJECT

public:
    login(QWidget *parent = nullptr);
    ~login();
    std::string Input_ID;

private slots:
    void on_login_btn_clicked();

    void on_signup_btn_clicked();

    void on_out_btn_clicked();

private:
    Ui::login *ui;
    Database database;
    QSqlQuery query;
    std::string query_string;
    bool vip;
};
#endif // LOGIN_H
