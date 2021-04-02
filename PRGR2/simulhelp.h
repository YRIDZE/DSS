#ifndef SIMULHELP_H
#define SIMULHELP_H

#include <QDialog>

namespace Ui {
class simulhelp;
}

class simulhelp : public QDialog
{
    Q_OBJECT

public:
    Ui::simulhelp *ui;
    explicit simulhelp(QWidget *parent = nullptr);
    ~simulhelp();

private:

};

#endif // SIMULHELP_H
