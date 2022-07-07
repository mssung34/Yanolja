#ifndef EDIT_H
#define EDIT_H

#include "database.h"
#include <vector>
#include <QDialog>

namespace Ui {
class edit;
}

class edit : public QDialog
{
    Q_OBJECT

public:
    explicit edit(QWidget *parent = nullptr);
    explicit edit(std::string type, QWidget *parent = nullptr); //추가
    explicit edit(std::string type,std::vector<std::string> data , QWidget *parent = nullptr); //수정
    ~edit();

private slots:
    void on_ok_btn_clicked();

    void on_exit_btn_clicked();

private:
    Ui::edit *ui;

    std::string query_string;
    QSqlQuery query;
    QSqlRecord rec;

    std::string name_str;
    std::string type;
    bool is_add;
};

#endif // EDIT_H
