#ifndef DATABASE_H
#define DATABASE_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QtSql>
#include <QSqlTableModel>

class Database
{
private:
    QSqlDatabase db;
public:
    Database() {
        open_db();
    }
    void open_db()
    {
        db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("10.10.20.34");      // IP 또는 DNS Host name
        db.setDatabaseName("Yanolja"); // DB명
        db.setUserName("yanolja");     // 계정 명
        db.setPassword("1q2w3e4r");     // 계정 Password

        if(!db.open())
        {
            qDebug()<<"connect error";
            exit(1);
        }
    }
    void close_db()
    {
        db.close();
    }
    ~Database() {
        close_db();
    }
};

#endif // DATABASE_H
