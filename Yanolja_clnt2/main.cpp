#include "login.h"
#include "signup.h"
#include "database.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    login w;
    w.show();
    return a.exec();
}
