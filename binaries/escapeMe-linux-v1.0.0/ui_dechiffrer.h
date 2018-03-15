/********************************************************************************
** Form generated from reading UI file 'dechiffrer.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DECHIFFRER_H
#define UI_DECHIFFRER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dechiffrer
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *sentence;
    QLineEdit *lineEdit;
    QPushButton *buttonVerif;

    void setupUi(QWidget *Dechiffrer)
    {
        if (Dechiffrer->objectName().isEmpty())
            Dechiffrer->setObjectName(QStringLiteral("Dechiffrer"));
        Dechiffrer->resize(400, 300);
        verticalLayout = new QVBoxLayout(Dechiffrer);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(Dechiffrer);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setScaledContents(false);

        verticalLayout->addWidget(label);

        sentence = new QLabel(Dechiffrer);
        sentence->setObjectName(QStringLiteral("sentence"));
        QFont font1;
        font1.setFamily(QStringLiteral("Courier"));
        font1.setPointSize(15);
        font1.setBold(false);
        font1.setWeight(50);
        sentence->setFont(font1);

        verticalLayout->addWidget(sentence, 0, Qt::AlignHCenter);

        lineEdit = new QLineEdit(Dechiffrer);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(0, 40));
        lineEdit->setFont(font);

        verticalLayout->addWidget(lineEdit);

        buttonVerif = new QPushButton(Dechiffrer);
        buttonVerif->setObjectName(QStringLiteral("buttonVerif"));

        verticalLayout->addWidget(buttonVerif);


        retranslateUi(Dechiffrer);

        QMetaObject::connectSlotsByName(Dechiffrer);
    } // setupUi

    void retranslateUi(QWidget *Dechiffrer)
    {
        Dechiffrer->setWindowTitle(QApplication::translate("Dechiffrer", "Form", nullptr));
        label->setText(QApplication::translate("Dechiffrer", "D\303\251chiffrer la phrase...", nullptr));
        sentence->setText(QString());
        lineEdit->setText(QString());
        buttonVerif->setText(QApplication::translate("Dechiffrer", "V\303\251rifier...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dechiffrer: public Ui_Dechiffrer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DECHIFFRER_H
