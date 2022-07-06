#include "mainpage.h"
#include "database.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    Database database;
    QApplication a(argc, argv);
    mainpage w;
    w.show();
    return a.exec();
}
