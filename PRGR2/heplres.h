#ifndef HEPLRES_H
#define HEPLRES_H

#include <QDialog>
#include "main.h"
#include "mainwindow.h"

namespace Ui {
class heplRES;
}

class heplRES : public QDialog
{
    Q_OBJECT

public:
    explicit heplRES(QWidget *parent = nullptr);
    ~heplRES();

private:
    Ui::heplRES *ui;
};

#endif // HEPLRES_H
