#include "heplres.h"
#include "ui_heplres.h"
#include "main.h"

heplRES::heplRES(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::heplRES)
{
    ui->setupUi(this);
}

heplRES::~heplRES()
{
    delete ui;
}


