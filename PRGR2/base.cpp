#include "base.h"
#include "ui_base.h"
#include <QFile>
#include <fstream>
#include <sstream>

base::base(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::base)
{
    ui->setupUi(this);
}

base::~base()
{
    delete ui;
}

void base::on_cansel_clicked()
{
    close();
}

void base::on_save_clicked()
{
    std::string windone = ui->hyposEdit->toPlainText().toStdString();
    std::string windtwo = ui->rulesEdit->toPlainText().toStdString();
    std::string windthree = ui->questEdit->toPlainText().toStdString();
    std::string windfour = ui->varEdit->toPlainText().toStdString();
    open((QString( QCoreApplication::applicationDirPath()  + "//txt//hypos.txt" )).toStdString(), windone);
    open((QString( QCoreApplication::applicationDirPath()  + "//txt//rules.txt" )).toStdString(), windtwo);
    open((QString( QCoreApplication::applicationDirPath()  + "//txt//questions.txt" )).toStdString(), windthree);
    open((QString( QCoreApplication::applicationDirPath()  + "//txt//sub.txt" )).toStdString(), windfour);

    /*open("C:\\Users\\Ira\\Desktop\\PRGR2\\build-PRGR2-Desktop_Qt_5_15_2_MinGW_64_bit-Debug\\debug\\hypos.txt", windone);
    open("C:\\Users\\Ira\\Desktop\\PRGR2\\build-PRGR2-Desktop_Qt_5_15_2_MinGW_64_bit-Debug\\debug\\rules.txt", windtwo);
    open("C:\\Users\\Ira\\Desktop\\PRGR2\\build-PRGR2-Desktop_Qt_5_15_2_MinGW_64_bit-Debug\\debug\\questions.txt", windthree);
    open("C:\\Users\\Ira\\Desktop\\PRGR2\\build-PRGR2-Desktop_Qt_5_15_2_MinGW_64_bit-Debug\\debug\\sub.txt", windfour);*/
    close();
}

void base::open(std::string filename, std::string alltext){

    std::string line;
    std::ofstream file (filename);

    if (file.is_open()){
        file << alltext;
    }
    file.close();
}

