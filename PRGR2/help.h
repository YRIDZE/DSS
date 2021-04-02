
#ifndef HELP_H // hlep
#define HELP_H

#include <QDialog>

namespace Ui {
class help;
}

class help : public QDialog
{
    Q_OBJECT

public:
    Ui::help *ui;
    explicit help(QWidget *parent = nullptr);
    ~help();

private:
};

#endif // HELP_H
