#ifndef GUIDE_H
#define GUIDE_H

#include <QDialog>

namespace Ui {
class guide;
}

class guide : public QDialog
{
    Q_OBJECT

public:
    explicit guide(QWidget *parent = nullptr);
    ~guide();

private:
    Ui::guide *ui;
};

#endif // GUIDE_H
