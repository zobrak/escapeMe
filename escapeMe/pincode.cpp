#include "pincode.h"
#include "ui_pincode.h"
#include "../emConf/emfunctions.h"
#include "dechiffrer.h"

PinCode::PinCode(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PinCode)
{
    ui->setupUi(this);
    connect(ui->entr,SIGNAL(clicked(bool)), this, SLOT(valider()));

}

void PinCode::on_retr_clicked()
{
    ui->lcdNumber->display(0);
}
void PinCode::on_num1_clicked()
{
    PinCode::afficher(num1);
}
void PinCode::on_num2_clicked()
{
    PinCode::afficher(num2);
}
void PinCode::on_num3_clicked()
{
    PinCode::afficher(num3);
}
void PinCode::on_num4_clicked()
{
    PinCode::afficher(num4);
}
void PinCode::on_num5_clicked()
{
    PinCode::afficher(num5);
}
void PinCode::on_num6_clicked()
{
    PinCode::afficher(num6);
}
void PinCode::on_num7_clicked()
{
    PinCode::afficher(num7);
}
void PinCode::on_num8_clicked()
{
    PinCode::afficher(num8);
}
void PinCode::on_num9_clicked()
{
    PinCode::afficher(num9);
}
void PinCode::on_num0_clicked()
{
    PinCode::afficher(num0);
}
/*void PinCode::on_entr_clicked()
{
    m_configFile = QStandardPaths::locate(QStandardPaths::GenericDataLocation, "", QStandardPaths::LocateDirectory);
    m_configFile += "emConf.ini";
    QSettings* confFile = new QSettings(m_configFile, QSettings::IniFormat, this);
    m_ConfPin= confFile->value("WelcomeWindow/pinCode").toInt();
    qDebug() << "m_confPin : " << m_lcdPinCode;
    m_lcdPinCode = ui->lcdNumber->value();
    qDebug() << "m_lcdPinCode : " << m_lcdPinCode;
    m_lcdPinCode = ui->lcdNumber->value();
        QMessageBox::information(NULL, "Info !", "Code OK");
    else QMessageBox::critical(NULL, "Info !", "Code faux");
    ui->lcdNumber->display(0);
}*/
void PinCode::valider()
{
    m_configFile = QStandardPaths::locate(QStandardPaths::GenericDataLocation, "", QStandardPaths::LocateDirectory);
    m_configFile += "emConf.ini";
    QSettings* confFile = new QSettings(m_configFile, QSettings::IniFormat, this);

    m_confPin= confFile->value("WelcomeWindow/pinCode").toInt();
    m_lcdPinCode = ui->lcdNumber->value();
    if(m_lcdPinCode == m_confPin)
    {
        this->accept();
    }
    else this->reject();


}

void PinCode::afficher(const int &number)
{
    if(ui->lcdNumber->intValue() == 0)
    {
        ui->lcdNumber->display(number);
        return;
    }
    if(ui->lcdNumber->intValue() < 10)
    {
        int tmp;
        tmp = ui->lcdNumber->intValue();
        tmp *= 10;
        tmp += number;
        ui->lcdNumber->display(tmp);
        return;
    }
    if(ui->lcdNumber->intValue() < 100)
    {
        int tmp;
        tmp = ui->lcdNumber->intValue();
        tmp *=10;
        tmp += number;
        ui->lcdNumber->display(tmp);
        return;
    }
    if(ui->lcdNumber->intValue() < 1000)
    {
        int tmp;
        tmp = ui->lcdNumber->intValue();
        tmp *=10;
        tmp += number;
        ui->lcdNumber->display(tmp);
        return;
    }
}

PinCode::~PinCode()
{
    delete ui;
}
