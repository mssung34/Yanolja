#ifndef DATE_H
#define DATE_H

#include <QDialog>
#include "login.h"
#include "attraction.h"

namespace Ui {
class date;
}

class date : public QDialog
{
    Q_OBJECT

public:
    explicit date(std::string Input_ID,QWidget *parent = nullptr);
    ~date();

private:
    Ui::date *ui;
    QSqlQuery query;
    std::string query_string;
    std::string Input_ID;
};

#endif // DATE_H
