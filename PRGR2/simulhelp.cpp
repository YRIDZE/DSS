#include "simulhelp.h"
#include "ui_simulhelp.h"

simulhelp::simulhelp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::simulhelp)
{
    ui->setupUi(this);
}

simulhelp::~simulhelp()
{
    delete ui;
}
