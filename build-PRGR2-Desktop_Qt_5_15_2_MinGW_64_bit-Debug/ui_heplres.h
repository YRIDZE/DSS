/********************************************************************************
** Form generated from reading UI file 'heplres.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HEPLRES_H
#define UI_HEPLRES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_heplRES
{
public:
    QTextEdit *result_help;

    void setupUi(QDialog *heplRES)
    {
        if (heplRES->objectName().isEmpty())
            heplRES->setObjectName(QString::fromUtf8("heplRES"));
        heplRES->resize(400, 300);
        result_help = new QTextEdit(heplRES);
        result_help->setObjectName(QString::fromUtf8("result_help"));
        result_help->setGeometry(QRect(13, 26, 371, 261));
        result_help->setReadOnly(true);

        retranslateUi(heplRES);

        QMetaObject::connectSlotsByName(heplRES);
    } // setupUi

    void retranslateUi(QDialog *heplRES)
    {
        heplRES->setWindowTitle(QCoreApplication::translate("heplRES", "\320\236\320\261\321\212\321\217\321\201\320\275\320\265\320\275\320\270\320\265 \321\200\320\265\321\210\320\265\320\275\320\270\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class heplRES: public Ui_heplRES {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HEPLRES_H
