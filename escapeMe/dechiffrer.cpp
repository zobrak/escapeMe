#include "dechiffrer.h"
#include "ui_dechiffrer.h"
#include "pincode.h"
#include "../emConf/emfunctions.h"
#include <QStandardPaths>
#include <QSettings>
#include <QDebug>

Dechiffrer::Dechiffrer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dechiffrer)
{
    ui->setupUi(this);
    QPixmap image(":/img/background.jpg");

    m_configFile = QStandardPaths::locate(QStandardPaths::GenericDataLocation, "", QStandardPaths::LocateDirectory);
    m_configFile += "emConf.ini";
    QSettings* confFile = new QSettings(m_configFile, QSettings::IniFormat, this);

    m_secret += confFile->value("SentenceToCrypt/sentence").toString();
    m_decalage = confFile->value("SentenceToCrypt/decalage").toInt();
    ui->sentence->setText(m_secret);
}

void Dechiffrer::on_buttonVerif_clicked()
{
    m_answer = ui->lineEdit->text();
    m_answer = EmFunctions::crypt(true, m_decalage, m_answer);
    if(m_answer == m_secret)
            ui->label->setText("Bravo ! Vous avez trouvé");
    else ui->label->setText("Mauvaise réponse, cherchez encore !");
    return;
}

Dechiffrer::~Dechiffrer()
{
    delete ui;
}
