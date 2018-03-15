/********************************************************************************
** Form generated from reading UI file 'emconf.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMCONF_H
#define UI_EMCONF_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EmConf
{
public:
    QVBoxLayout *layoutMain;
    QLabel *label;
    QVBoxLayout *vlayoutvbox1;
    QLabel *label_2;
    QLabel *defaultPTSLabel;
    QPushButton *chngSavPlace;
    QGroupBox *gboxWelcomeConf;
    QWidget *layoutWidget;
    QFormLayout *formSetsWelcome;
    QLabel *codePinLabel;
    QLineEdit *codePinLineEdit;
    QGroupBox *gboxCryptConf;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *vlayoutvbox2;
    QFormLayout *formSetsCrypt;
    QRadioButton *radioButtonMethod2;
    QLabel *dCalageLabel;
    QComboBox *dCalageComboBox;
    QLabel *phraseLabel;
    QLineEdit *phraseLineEdit;
    QRadioButton *radioButtonMethod1;
    QHBoxLayout *buttonlayout;
    QSpacerItem *hSpace1;
    QPushButton *pushButtonSave;
    QPushButton *pushButtonQuit;

    void setupUi(QWidget *EmConf)
    {
        if (EmConf->objectName().isEmpty())
            EmConf->setObjectName(QStringLiteral("EmConf"));
        EmConf->resize(400, 400);
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(EmConf->sizePolicy().hasHeightForWidth());
        EmConf->setSizePolicy(sizePolicy);
        EmConf->setMinimumSize(QSize(400, 400));
        EmConf->setMaximumSize(QSize(400, 515));
        EmConf->setBaseSize(QSize(0, 0));
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/config.ico"), QSize(), QIcon::Normal, QIcon::Off);
        EmConf->setWindowIcon(icon);
        layoutMain = new QVBoxLayout(EmConf);
        layoutMain->setSpacing(13);
        layoutMain->setObjectName(QStringLiteral("layoutMain"));
        layoutMain->setSizeConstraint(QLayout::SetMinimumSize);
        label = new QLabel(EmConf);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        layoutMain->addWidget(label);

        vlayoutvbox1 = new QVBoxLayout();
        vlayoutvbox1->setObjectName(QStringLiteral("vlayoutvbox1"));
        vlayoutvbox1->setContentsMargins(10, -1, 10, -1);
        label_2 = new QLabel(EmConf);
        label_2->setObjectName(QStringLiteral("label_2"));

        vlayoutvbox1->addWidget(label_2);

        defaultPTSLabel = new QLabel(EmConf);
        defaultPTSLabel->setObjectName(QStringLiteral("defaultPTSLabel"));

        vlayoutvbox1->addWidget(defaultPTSLabel);

        chngSavPlace = new QPushButton(EmConf);
        chngSavPlace->setObjectName(QStringLiteral("chngSavPlace"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(chngSavPlace->sizePolicy().hasHeightForWidth());
        chngSavPlace->setSizePolicy(sizePolicy2);
        chngSavPlace->setFlat(false);

        vlayoutvbox1->addWidget(chngSavPlace);


        layoutMain->addLayout(vlayoutvbox1);

        gboxWelcomeConf = new QGroupBox(EmConf);
        gboxWelcomeConf->setObjectName(QStringLiteral("gboxWelcomeConf"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(gboxWelcomeConf->sizePolicy().hasHeightForWidth());
        gboxWelcomeConf->setSizePolicy(sizePolicy3);
        gboxWelcomeConf->setMinimumSize(QSize(0, 47));
        gboxWelcomeConf->setCheckable(true);
        layoutWidget = new QWidget(gboxWelcomeConf);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 20, 378, 22));
        formSetsWelcome = new QFormLayout(layoutWidget);
        formSetsWelcome->setObjectName(QStringLiteral("formSetsWelcome"));
        formSetsWelcome->setSizeConstraint(QLayout::SetNoConstraint);
        formSetsWelcome->setHorizontalSpacing(13);
        formSetsWelcome->setContentsMargins(13, 0, 0, 0);
        codePinLabel = new QLabel(layoutWidget);
        codePinLabel->setObjectName(QStringLiteral("codePinLabel"));

        formSetsWelcome->setWidget(0, QFormLayout::LabelRole, codePinLabel);

        codePinLineEdit = new QLineEdit(layoutWidget);
        codePinLineEdit->setObjectName(QStringLiteral("codePinLineEdit"));
        sizePolicy2.setHeightForWidth(codePinLineEdit->sizePolicy().hasHeightForWidth());
        codePinLineEdit->setSizePolicy(sizePolicy2);
        codePinLineEdit->setMaxLength(4);
        codePinLineEdit->setClearButtonEnabled(false);

        formSetsWelcome->setWidget(0, QFormLayout::FieldRole, codePinLineEdit);


        layoutMain->addWidget(gboxWelcomeConf);

        gboxCryptConf = new QGroupBox(EmConf);
        gboxCryptConf->setObjectName(QStringLiteral("gboxCryptConf"));
        sizePolicy1.setHeightForWidth(gboxCryptConf->sizePolicy().hasHeightForWidth());
        gboxCryptConf->setSizePolicy(sizePolicy1);
        gboxCryptConf->setMinimumSize(QSize(0, 140));
        verticalLayoutWidget_2 = new QWidget(gboxCryptConf);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 20, 361, 271));
        vlayoutvbox2 = new QVBoxLayout(verticalLayoutWidget_2);
        vlayoutvbox2->setObjectName(QStringLiteral("vlayoutvbox2"));
        vlayoutvbox2->setSizeConstraint(QLayout::SetNoConstraint);
        vlayoutvbox2->setContentsMargins(0, 0, 0, 0);
        formSetsCrypt = new QFormLayout();
        formSetsCrypt->setObjectName(QStringLiteral("formSetsCrypt"));
        formSetsCrypt->setSizeConstraint(QLayout::SetFixedSize);
        formSetsCrypt->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        radioButtonMethod2 = new QRadioButton(verticalLayoutWidget_2);
        radioButtonMethod2->setObjectName(QStringLiteral("radioButtonMethod2"));

        formSetsCrypt->setWidget(1, QFormLayout::LabelRole, radioButtonMethod2);

        dCalageLabel = new QLabel(verticalLayoutWidget_2);
        dCalageLabel->setObjectName(QStringLiteral("dCalageLabel"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(dCalageLabel->sizePolicy().hasHeightForWidth());
        dCalageLabel->setSizePolicy(sizePolicy4);

        formSetsCrypt->setWidget(2, QFormLayout::LabelRole, dCalageLabel);

        dCalageComboBox = new QComboBox(verticalLayoutWidget_2);
        dCalageComboBox->addItem(QString());
        dCalageComboBox->addItem(QString());
        dCalageComboBox->addItem(QString());
        dCalageComboBox->addItem(QString());
        dCalageComboBox->addItem(QString());
        dCalageComboBox->addItem(QString());
        dCalageComboBox->addItem(QString());
        dCalageComboBox->addItem(QString());
        dCalageComboBox->addItem(QString());
        dCalageComboBox->addItem(QString());
        dCalageComboBox->addItem(QString());
        dCalageComboBox->addItem(QString());
        dCalageComboBox->addItem(QString());
        dCalageComboBox->addItem(QString());
        dCalageComboBox->addItem(QString());
        dCalageComboBox->addItem(QString());
        dCalageComboBox->addItem(QString());
        dCalageComboBox->addItem(QString());
        dCalageComboBox->addItem(QString());
        dCalageComboBox->addItem(QString());
        dCalageComboBox->addItem(QString());
        dCalageComboBox->addItem(QString());
        dCalageComboBox->addItem(QString());
        dCalageComboBox->addItem(QString());
        dCalageComboBox->addItem(QString());
        dCalageComboBox->setObjectName(QStringLiteral("dCalageComboBox"));
        sizePolicy2.setHeightForWidth(dCalageComboBox->sizePolicy().hasHeightForWidth());
        dCalageComboBox->setSizePolicy(sizePolicy2);
        dCalageComboBox->setMinimumSize(QSize(55, 0));

        formSetsCrypt->setWidget(2, QFormLayout::FieldRole, dCalageComboBox);

        phraseLabel = new QLabel(verticalLayoutWidget_2);
        phraseLabel->setObjectName(QStringLiteral("phraseLabel"));

        formSetsCrypt->setWidget(3, QFormLayout::LabelRole, phraseLabel);

        phraseLineEdit = new QLineEdit(verticalLayoutWidget_2);
        phraseLineEdit->setObjectName(QStringLiteral("phraseLineEdit"));

        formSetsCrypt->setWidget(3, QFormLayout::FieldRole, phraseLineEdit);

        radioButtonMethod1 = new QRadioButton(verticalLayoutWidget_2);
        radioButtonMethod1->setObjectName(QStringLiteral("radioButtonMethod1"));
        radioButtonMethod1->setChecked(true);

        formSetsCrypt->setWidget(0, QFormLayout::LabelRole, radioButtonMethod1);


        vlayoutvbox2->addLayout(formSetsCrypt);


        layoutMain->addWidget(gboxCryptConf);

        buttonlayout = new QHBoxLayout();
        buttonlayout->setSpacing(10);
        buttonlayout->setObjectName(QStringLiteral("buttonlayout"));
        buttonlayout->setContentsMargins(12, -1, 10, -1);
        hSpace1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        buttonlayout->addItem(hSpace1);

        pushButtonSave = new QPushButton(EmConf);
        pushButtonSave->setObjectName(QStringLiteral("pushButtonSave"));

        buttonlayout->addWidget(pushButtonSave);

        pushButtonQuit = new QPushButton(EmConf);
        pushButtonQuit->setObjectName(QStringLiteral("pushButtonQuit"));

        buttonlayout->addWidget(pushButtonQuit);


        layoutMain->addLayout(buttonlayout);


        retranslateUi(EmConf);

        QMetaObject::connectSlotsByName(EmConf);
    } // setupUi

    void retranslateUi(QWidget *EmConf)
    {
        EmConf->setWindowTitle(QApplication::translate("EmConf", "Configuration", nullptr));
        label->setText(QApplication::translate("EmConf", "Param\303\250tres de configuration 3scape.Me", nullptr));
        label_2->setText(QApplication::translate("EmConf", "Emplacement du fichier de sauvegarde :", nullptr));
        defaultPTSLabel->setText(QString());
        chngSavPlace->setText(QApplication::translate("EmConf", "Sauvegarder..", nullptr));
        gboxWelcomeConf->setTitle(QApplication::translate("EmConf", "V\303\251rouiller par un Code PIN", nullptr));
        codePinLabel->setText(QApplication::translate("EmConf", "Code Pin (4 chiffres) :", nullptr));
        gboxCryptConf->setTitle(QApplication::translate("EmConf", "Phrase \303\240 d\303\251crypter", nullptr));
        radioButtonMethod2->setText(QApplication::translate("EmConf", "M\303\251thode de chiffrement n\302\2602", nullptr));
        dCalageLabel->setText(QApplication::translate("EmConf", "D\303\251calage : ", nullptr));
        dCalageComboBox->setItemText(0, QApplication::translate("EmConf", "1", nullptr));
        dCalageComboBox->setItemText(1, QApplication::translate("EmConf", "2", nullptr));
        dCalageComboBox->setItemText(2, QApplication::translate("EmConf", "3", nullptr));
        dCalageComboBox->setItemText(3, QApplication::translate("EmConf", "4", nullptr));
        dCalageComboBox->setItemText(4, QApplication::translate("EmConf", "5", nullptr));
        dCalageComboBox->setItemText(5, QApplication::translate("EmConf", "6", nullptr));
        dCalageComboBox->setItemText(6, QApplication::translate("EmConf", "7", nullptr));
        dCalageComboBox->setItemText(7, QApplication::translate("EmConf", "8", nullptr));
        dCalageComboBox->setItemText(8, QApplication::translate("EmConf", "9", nullptr));
        dCalageComboBox->setItemText(9, QApplication::translate("EmConf", "10", nullptr));
        dCalageComboBox->setItemText(10, QApplication::translate("EmConf", "11", nullptr));
        dCalageComboBox->setItemText(11, QApplication::translate("EmConf", "12", nullptr));
        dCalageComboBox->setItemText(12, QApplication::translate("EmConf", "13", nullptr));
        dCalageComboBox->setItemText(13, QApplication::translate("EmConf", "14", nullptr));
        dCalageComboBox->setItemText(14, QApplication::translate("EmConf", "15", nullptr));
        dCalageComboBox->setItemText(15, QApplication::translate("EmConf", "16", nullptr));
        dCalageComboBox->setItemText(16, QApplication::translate("EmConf", "17", nullptr));
        dCalageComboBox->setItemText(17, QApplication::translate("EmConf", "18", nullptr));
        dCalageComboBox->setItemText(18, QApplication::translate("EmConf", "19", nullptr));
        dCalageComboBox->setItemText(19, QApplication::translate("EmConf", "20", nullptr));
        dCalageComboBox->setItemText(20, QApplication::translate("EmConf", "21", nullptr));
        dCalageComboBox->setItemText(21, QApplication::translate("EmConf", "22", nullptr));
        dCalageComboBox->setItemText(22, QApplication::translate("EmConf", "23", nullptr));
        dCalageComboBox->setItemText(23, QApplication::translate("EmConf", "24", nullptr));
        dCalageComboBox->setItemText(24, QApplication::translate("EmConf", "25", nullptr));

        phraseLabel->setText(QApplication::translate("EmConf", "Phrase", nullptr));
        radioButtonMethod1->setText(QApplication::translate("EmConf", "M\303\251thode de chiffrement n\302\2601", nullptr));
        pushButtonSave->setText(QApplication::translate("EmConf", "Enregistrer", nullptr));
        pushButtonQuit->setText(QApplication::translate("EmConf", "Quitter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EmConf: public Ui_EmConf {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMCONF_H
