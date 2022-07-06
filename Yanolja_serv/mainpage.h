#ifndef MAINPAGE_H
#define MAINPAGE_H

#include "user.h"
#include "guide.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class mainpage; }
QT_END_NAMESPACE

class mainpage : public QMainWindow
{
    Q_OBJECT

public:
    mainpage(QWidget *parent = nullptr);
    ~mainpage();

private slots:

    void on_user_btn_clicked();

    void on_beach_btn_clicked();

    void on_tour_btn_clicked();

    void on_guide_btn_clicked();

    void on_exit_btn_clicked();

private:
    Ui::mainpage *ui;

};
#endif // MAINPAGE_H
