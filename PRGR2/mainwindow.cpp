#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QDir>
#include "main.h"
#include "help.h"
#include "base.h"
#include "ui_base.h"
#include "ui_help.h"
#include "simulhelp.h"
#include "ui_simulhelp.h"
#include <fstream>
#include <sstream>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::quest(std::string q){
    curr_var = q;
    ui->result_show->append("Вопрос:  " + QString::fromUtf8(que[q].c_str()));

    shp.ui->helpEdit->clear();
    shp.ui->helpEdit->append("Проходит проверку: <br>");
    for (auto &a: var_stack){
        if(hyp.find(a)!=hyp.end()){
            std::stringstream line;
            line << ">>> гипотеза \"" <<hyp[a]<<"\"";
            shp.ui->helpEdit->append(QString::fromUtf8(line.str().c_str()));

        }
        else if(subvariable.find(a)!=subvariable.end()){
            std::stringstream line2;
            line2 << ">>> утверждение \"" <<subvariable[a]<<"\"";
            shp.ui->helpEdit->append(QString::fromUtf8(line2.str().c_str()));

        }
        else {
            std::stringstream line3;
            line3 << ">>> вопрос \"" <<que[a]<<"\"";
            shp.ui->helpEdit->append(QString::fromUtf8(line3.str().c_str()));

        }
    }

}

void MainWindow::on_close_triggered()
{
    QMessageBox::StandardButton reply = QMessageBox::question (this, " ","Вы уверены, что хотите выйти?",
                                                               QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes){
        QApplication::quit();
    }
    else{
        qDebug()<<"захотели выйти";
    }
}

std::string MainWindow::open(std::string filename){
    std::stringstream alltext;
    std::string line;
    std::ifstream file (filename);
    if (file.is_open()){
        while(getline(file, line)){
            alltext<<line<<std::endl;
        }
    }
    file.close();
 return alltext.str();
}


void MainWindow:: f2(){
    try{
        result = f();
        std::string nope = "Нет подходящего метода";
        ui->result_show->append("\n>>> "+QString::fromUtf8(!result.empty() ? hyp[result].c_str() : nope.c_str()));

        ui->no_btn->setEnabled(false);
        ui->yes_btn->setEnabled(false);
        ui->help_res->setEnabled(true);
        ui->help->setEnabled(false);
    }
    catch(NotAskedException &e){
        quest(e.what());
    }
}

void MainWindow::on_start_btn_clicked()
{
    ui->result_show->append(ui->start_btn->text());
    ui->start_btn->setEnabled(false);
    ui->no_btn->setEnabled(true);
    ui->yes_btn->setEnabled(true);
    ui->help_res->setEnabled(false);
    ui->help->setEnabled(true);
    schitHYP();
    schitRULE();
    schitQUES();
    schitSub();
    f2();
}

void MainWindow::on_reset_triggered()
{
    mem = {};
    ui->result_show->clear();
    ui->no_btn->setEnabled(true);
    ui->yes_btn->setEnabled(true);
    ui->help_res->setEnabled(false);
    ui->help->setEnabled(true);
    schitHYP();
    schitRULE();
    schitQUES();
    schitSub();
    f2();

}
void MainWindow::on_yes_btn_clicked()
{
    ui->result_show->append("Ответ:    " + ui->yes_btn->text());
    mem[curr_var] = 1;
    f2();

}

void MainWindow::on_no_btn_clicked()
{
    ui->result_show->append("Ответ:    " + ui->no_btn->text());
    mem[curr_var] = 0;
    f2();
}

void MainWindow::on_help_triggered()
{
    shp.setModal(true);
    shp.exec();
}

void MainWindow::on_help_res_clicked()
{
    hp.ui->textEdit->clear();
    std::string nope = "Ответы на вопросы, которые были заданы, не приводят к выбору любого из известных системе методов.";

    if (result.empty()) {
        hp.ui->textEdit->append(QString::fromUtf8(nope.c_str()));
    }
    else {
        std::ostringstream result_hypos;
        result_hypos<<"Ответ <b>\"" << hyp[result]<<"\"</b> был дан потому, что: <br>";
        hp.ui->textEdit->append(QString::fromUtf8(result_hypos.str().c_str()));
        std::set<std::string> res = rule_nodes[result]->nodesques();
        for (auto &a: res){
            std::ostringstream tab;
            tab << " - на вопрос \""<<que[a]<<"\" был дан ответ: ";
            if (mem[a] == false){
                tab<<" <b> Heт</b>";
            } else {tab<<" <b>Да</b>";}
            hp.ui->textEdit->append(QString::fromUtf8(tab.str().c_str()));
        }
    }

    hp.setModal(true);
    hp.exec();
}


void MainWindow::on_base_triggered()
{
    base b;

    b.ui->hyposEdit->append(open((QString( QCoreApplication::applicationDirPath()  + "//txt//hypos.txt" )).toStdString()).c_str());
    b.ui->rulesEdit->append(open((QString( QCoreApplication::applicationDirPath()  + "//txt//rules.txt" )).toStdString()).c_str());
    b.ui->questEdit->append(open((QString( QCoreApplication::applicationDirPath()  + "//txt//questions.txt" )).toStdString()).c_str());
    b.ui->varEdit->append(open((QString( QCoreApplication::applicationDirPath()  + "//txt//sub.txt" )).toStdString()).c_str());

    //b.ui->hyposEdit->append(QString::fromUtf8(open("C:\\Users\\Ira\\Desktop\\PRGR2\\build-PRGR2-Desktop_Qt_5_15_2_MinGW_64_bit-Debug\\debug\\hypos.txt").c_str()));
    //b.ui->rulesEdit->append(QString::fromUtf8(open("C:\\Users\\Ira\\Desktop\\PRGR2\\build-PRGR2-Desktop_Qt_5_15_2_MinGW_64_bit-Debug\\debug\\rules.txt").c_str()));
    //b.ui->questEdit->append(QString::fromUtf8(open("C:\\Users\\Ira\\Desktop\\PRGR2\\build-PRGR2-Desktop_Qt_5_15_2_MinGW_64_bit-Debug\\debug\\questions.txt").c_str()));
    //b.ui->varEdit->append(QString::fromUtf8(open("C:\\Users\\Ira\\Desktop\\PRGR2\\build-PRGR2-Desktop_Qt_5_15_2_MinGW_64_bit-Debug\\debug\\sub.txt").c_str()));

    b.setModal(true);
    b.exec();

}
