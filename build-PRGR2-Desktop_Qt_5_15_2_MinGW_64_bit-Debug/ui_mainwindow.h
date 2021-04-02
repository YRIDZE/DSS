/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *reset;
    QAction *help;
    QAction *close;
    QAction *base;
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *start_btn;
    QPushButton *yes_btn;
    QPushButton *no_btn;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *result_show;
    QPushButton *help_res;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(500, 392);
        QFont font;
        font.setKerning(true);
        MainWindow->setFont(font);
        reset = new QAction(MainWindow);
        reset->setObjectName(QString::fromUtf8("reset"));
        help = new QAction(MainWindow);
        help->setObjectName(QString::fromUtf8("help"));
        help->setEnabled(false);
        close = new QAction(MainWindow);
        close->setObjectName(QString::fromUtf8("close"));
        base = new QAction(MainWindow);
        base->setObjectName(QString::fromUtf8("base"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        start_btn = new QPushButton(centralwidget);
        start_btn->setObjectName(QString::fromUtf8("start_btn"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(start_btn->sizePolicy().hasHeightForWidth());
        start_btn->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setUnderline(true);
        font1.setKerning(true);
        start_btn->setFont(font1);

        horizontalLayout_2->addWidget(start_btn);

        yes_btn = new QPushButton(centralwidget);
        yes_btn->setObjectName(QString::fromUtf8("yes_btn"));
        yes_btn->setEnabled(false);
        yes_btn->setFont(font1);

        horizontalLayout_2->addWidget(yes_btn);

        no_btn = new QPushButton(centralwidget);
        no_btn->setObjectName(QString::fromUtf8("no_btn"));
        no_btn->setEnabled(false);
        no_btn->setFont(font1);

        horizontalLayout_2->addWidget(no_btn);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        result_show = new QTextEdit(centralwidget);
        result_show->setObjectName(QString::fromUtf8("result_show"));
        QFont font2;
        font2.setPointSize(9);
        font2.setKerning(true);
        result_show->setFont(font2);
        result_show->setReadOnly(true);

        verticalLayout_2->addWidget(result_show);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        help_res = new QPushButton(centralwidget);
        help_res->setObjectName(QString::fromUtf8("help_res"));
        help_res->setEnabled(false);

        gridLayout_2->addWidget(help_res, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 500, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(reset);
        menu->addAction(base);
        menu->addAction(help);
        menu->addAction(close);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "OWLprog", nullptr));
        reset->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\207\320\260\321\202\321\214 \321\201\320\275\320\260\321\207\320\260\320\273\320\260", nullptr));
        help->setText(QCoreApplication::translate("MainWindow", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", nullptr));
        close->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\271\321\202\320\270", nullptr));
        base->setText(QCoreApplication::translate("MainWindow", "\320\221\320\260\320\267\320\260 \320\267\320\275\320\260\320\275\320\270\320\271", nullptr));
        start_btn->setText(QCoreApplication::translate("MainWindow", "\320\241\320\242\320\220\320\240\320\242", nullptr));
        yes_btn->setText(QCoreApplication::translate("MainWindow", "\320\224\320\220", nullptr));
        no_btn->setText(QCoreApplication::translate("MainWindow", "\320\235\320\225\320\242", nullptr));
        result_show->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:7.8pt;\"><br /></p></body></html>", nullptr));
        help_res->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261\321\212\321\217\321\201\320\275\320\265\320\275\320\270\320\265 \321\200\320\265\321\210\320\265\320\275\320\270\321\217", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\225\320\251\320\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
