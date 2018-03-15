/********************************************************************************
** Form generated from reading UI file 'pincode.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PINCODE_H
#define UI_PINCODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_PinCode
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QLCDNumber *lcdNumber;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout;
    QPushButton *num0;
    QPushButton *num9;
    QPushButton *retr;
    QPushButton *num2;
    QPushButton *num4;
    QPushButton *num5;
    QPushButton *num7;
    QPushButton *num3;
    QPushButton *num1;
    QPushButton *num6;
    QPushButton *entr;
    QPushButton *num8;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *PinCode)
    {
        if (PinCode->objectName().isEmpty())
            PinCode->setObjectName(QStringLiteral("PinCode"));
        PinCode->resize(191, 233);
        verticalLayout = new QVBoxLayout(PinCode);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        label = new QLabel(PinCode);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        lcdNumber = new QLCDNumber(PinCode);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setMinimumSize(QSize(120, 60));
        lcdNumber->setMaximumSize(QSize(16777215, 80));
        QPalette palette;
        QBrush brush(QColor(138, 226, 52, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        QBrush brush2(QColor(0, 0, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
        QBrush brush3(QColor(190, 190, 190, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush2);
        lcdNumber->setPalette(palette);

        horizontalLayout_2->addWidget(lcdNumber);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        num0 = new QPushButton(PinCode);
        num0->setObjectName(QStringLiteral("num0"));
        num0->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(num0, 3, 1, 1, 1);

        num9 = new QPushButton(PinCode);
        num9->setObjectName(QStringLiteral("num9"));
        num9->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(num9, 2, 2, 1, 1);

        retr = new QPushButton(PinCode);
        retr->setObjectName(QStringLiteral("retr"));
        retr->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(retr, 3, 0, 1, 1);

        num2 = new QPushButton(PinCode);
        num2->setObjectName(QStringLiteral("num2"));
        num2->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(num2, 0, 1, 1, 1);

        num4 = new QPushButton(PinCode);
        num4->setObjectName(QStringLiteral("num4"));
        num4->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(num4, 1, 0, 1, 1);

        num5 = new QPushButton(PinCode);
        num5->setObjectName(QStringLiteral("num5"));
        num5->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(num5, 1, 1, 1, 1);

        num7 = new QPushButton(PinCode);
        num7->setObjectName(QStringLiteral("num7"));
        num7->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(num7, 2, 0, 1, 1);

        num3 = new QPushButton(PinCode);
        num3->setObjectName(QStringLiteral("num3"));
        num3->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(num3, 0, 2, 1, 1);

        num1 = new QPushButton(PinCode);
        num1->setObjectName(QStringLiteral("num1"));
        num1->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(num1, 0, 0, 1, 1);

        num6 = new QPushButton(PinCode);
        num6->setObjectName(QStringLiteral("num6"));
        num6->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(num6, 1, 2, 1, 1);

        entr = new QPushButton(PinCode);
        entr->setObjectName(QStringLiteral("entr"));
        entr->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(entr, 3, 2, 1, 1);

        num8 = new QPushButton(PinCode);
        num8->setObjectName(QStringLiteral("num8"));
        num8->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(num8, 2, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(PinCode);

        QMetaObject::connectSlotsByName(PinCode);
    } // setupUi

    void retranslateUi(QDialog *PinCode)
    {
        PinCode->setWindowTitle(QApplication::translate("PinCode", "Dialog", nullptr));
        label->setText(QString());
        num0->setText(QApplication::translate("PinCode", "0", nullptr));
        num9->setText(QApplication::translate("PinCode", "9", nullptr));
        retr->setText(QApplication::translate("PinCode", "<-", nullptr));
        num2->setText(QApplication::translate("PinCode", "2", nullptr));
        num4->setText(QApplication::translate("PinCode", "4", nullptr));
        num5->setText(QApplication::translate("PinCode", "5", nullptr));
        num7->setText(QApplication::translate("PinCode", "7", nullptr));
        num3->setText(QApplication::translate("PinCode", "3", nullptr));
        num1->setText(QApplication::translate("PinCode", "1", nullptr));
        num6->setText(QApplication::translate("PinCode", "6", nullptr));
        entr->setText(QApplication::translate("PinCode", "Enter", nullptr));
        num8->setText(QApplication::translate("PinCode", "8", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PinCode: public Ui_PinCode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PINCODE_H
