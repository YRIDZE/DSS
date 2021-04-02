#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include <iostream>
#include "main.h"
#include "help.h"
#include "base.h"
#include "simulhelp.h"

class Node;

bool rule(std::string);
bool spash(std::string, std::string);
std::string f();


extern std::string curr_var2;
class NotAskedException;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    simulhelp shp;
    help hp;
    ~MainWindow();

private slots:

    void on_yes_btn_clicked();
    void on_close_triggered();
    void on_start_btn_clicked();
    void quest(std::string);
    void f2();
    void on_no_btn_clicked();
    void on_reset_triggered();
    void on_help_triggered();
    void on_help_res_clicked();
    void on_base_triggered();
    std::string open(std::string);


private:
    Ui::MainWindow *ui;


};
#endif // MAINWINDOW_H
