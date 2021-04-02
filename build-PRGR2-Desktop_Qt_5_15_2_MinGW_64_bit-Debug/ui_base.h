/********************************************************************************
** Form generated from reading UI file 'base.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BASE_H
#define UI_BASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_base
{
public:
    QGridLayout *gridLayout;
    QTextEdit *hyposEdit;
    QTextEdit *questEdit;
    QLabel *hypos;
    QLabel *quest;
    QLabel *rules;
    QTextEdit *rulesEdit;
    QTextEdit *varEdit;
    QLabel *var;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *save;
    QPushButton *cansel;

    void setupUi(QDialog *base)
    {
        if (base->objectName().isEmpty())
            base->setObjectName(QString::fromUtf8("base"));
        base->resize(804, 617);
        gridLayout = new QGridLayout(base);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        hyposEdit = new QTextEdit(base);
        hyposEdit->setObjectName(QString::fromUtf8("hyposEdit"));

        gridLayout->addWidget(hyposEdit, 1, 0, 1, 1);

        questEdit = new QTextEdit(base);
        questEdit->setObjectName(QString::fromUtf8("questEdit"));

        gridLayout->addWidget(questEdit, 5, 0, 1, 1);

        hypos = new QLabel(base);
        hypos->setObjectName(QString::fromUtf8("hypos"));

        gridLayout->addWidget(hypos, 0, 0, 1, 1);

        quest = new QLabel(base);
        quest->setObjectName(QString::fromUtf8("quest"));

        gridLayout->addWidget(quest, 4, 0, 1, 1);

        rules = new QLabel(base);
        rules->setObjectName(QString::fromUtf8("rules"));

        gridLayout->addWidget(rules, 0, 1, 1, 1);

        rulesEdit = new QTextEdit(base);
        rulesEdit->setObjectName(QString::fromUtf8("rulesEdit"));

        gridLayout->addWidget(rulesEdit, 1, 1, 1, 1);

        varEdit = new QTextEdit(base);
        varEdit->setObjectName(QString::fromUtf8("varEdit"));

        gridLayout->addWidget(varEdit, 5, 1, 1, 1);

        var = new QLabel(base);
        var->setObjectName(QString::fromUtf8("var"));

        gridLayout->addWidget(var, 4, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        save = new QPushButton(base);
        save->setObjectName(QString::fromUtf8("save"));

        horizontalLayout_2->addWidget(save);

        cansel = new QPushButton(base);
        cansel->setObjectName(QString::fromUtf8("cansel"));

        horizontalLayout_2->addWidget(cansel);


        gridLayout->addLayout(horizontalLayout_2, 6, 1, 1, 1);


        retranslateUi(base);

        QMetaObject::connectSlotsByName(base);
    } // setupUi

    void retranslateUi(QDialog *base)
    {
        base->setWindowTitle(QCoreApplication::translate("base", "\320\221\320\260\320\267\320\260 \320\267\320\275\320\260\320\275\320\270\320\271", nullptr));
        hypos->setText(QCoreApplication::translate("base", "\320\223\320\270\320\277\320\276\321\202\320\265\320\267\321\213", nullptr));
        quest->setText(QCoreApplication::translate("base", "\320\222\320\276\320\277\321\200\320\276\321\201\321\213", nullptr));
        rules->setText(QCoreApplication::translate("base", "\320\237\321\200\320\260\320\262\320\270\320\273\320\260", nullptr));
        var->setText(QCoreApplication::translate("base", "\320\237\320\265\321\200\320\265\320\274\320\265\320\275\320\275\321\213\320\265", nullptr));
        save->setText(QCoreApplication::translate("base", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        cansel->setText(QCoreApplication::translate("base", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class base: public Ui_base {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BASE_H
