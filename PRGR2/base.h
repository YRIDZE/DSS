#ifndef BASE_H
#define BASE_H

#include <QDialog>

namespace Ui {
class base;
}

class base : public QDialog
{
    Q_OBJECT

public:
    Ui::base *ui;
    explicit base(QWidget *parent = nullptr);
    ~base();

private slots:
    void on_cansel_clicked();

    void on_save_clicked();
    void open(std::string filename, std::string alltext);


private:
};

#endif // BASE_H
