/********************************************************************************
** Form generated from reading UI file 'simulhelp.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMULHELP_H
#define UI_SIMULHELP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_simulhelp
{
public:
    QGridLayout *gridLayout;
    QTextEdit *helpEdit;

    void setupUi(QDialog *simulhelp)
    {
        if (simulhelp->objectName().isEmpty())
            simulhelp->setObjectName(QString::fromUtf8("simulhelp"));
        simulhelp->resize(375, 187);
        gridLayout = new QGridLayout(simulhelp);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        helpEdit = new QTextEdit(simulhelp);
        helpEdit->setObjectName(QString::fromUtf8("helpEdit"));
        helpEdit->setReadOnly(true);

        gridLayout->addWidget(helpEdit, 0, 0, 1, 1);


        retranslateUi(simulhelp);

        QMetaObject::connectSlotsByName(simulhelp);
    } // setupUi

    void retranslateUi(QDialog *simulhelp)
    {
        simulhelp->setWindowTitle(QCoreApplication::translate("simulhelp", "\320\236\320\261\321\212\321\217\321\201\320\275\320\265\320\275\320\270\320\265 \320\262\320\276\320\277\321\200\320\276\321\201\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class simulhelp: public Ui_simulhelp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMULHELP_H
