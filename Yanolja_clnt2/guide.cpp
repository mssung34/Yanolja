#include "guide.h"
#include "ui_guide.h"

guide::guide(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::guide)
{
    ui->setupUi(this);
}

guide::~guide()
{
    delete ui;
}
