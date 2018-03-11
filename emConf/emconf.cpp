#include "emconf.h"
#include "ui_emconf.h"
#include "emfunctions.h"


EmConf::EmConf(QWidget *parent) : QWidget(parent), ui(new Ui::EmConf)
{
    ui->setupUi(this);
    QIntValidator* validPin = new QIntValidator(0,9999,ui->codePinLineEdit);
//Paramètres d'initialisation de la fenêtre et des widgets
    ui->codePinLineEdit->setValidator(validPin);
    ui->codePinLineEdit->setText("0000");
    ui->phraseLineEdit->setText("Le chien a l'air d'avoir faim");
    //Paramétrage et affichage de l'emplacement de sauvegarde par défaut
    m_placeToSave = QStandardPaths::locate(QStandardPaths::GenericDataLocation, "escapeme", QStandardPaths::LocateDirectory);
    ui->defaultPTSLabel->setText(m_placeToSave);
    //Choix de la méthode de chiffrement
    if(ui->radioButtonMethod1)
        m_method = 1;
    if(ui->radioButtonMethod2)
        m_method = 2;

//Connections
    QObject::connect(ui->pushButtonQuit, SIGNAL(clicked(bool)), qApp, SLOT(quit()));
}

void EmConf::on_chngSavPlace_clicked()
{

   QString tmpStr = m_placeToSave;
   tmpStr = EmFunctions::setPlaceToSave(tmpStr);
   m_placeToSave = tmpStr;
   ui->defaultPTSLabel->setText(m_placeToSave);

}
void EmConf::on_pushButtonSave_clicked()
{

    int decalage = ui->dCalageComboBox->currentText().toInt();
    QString cryptedChain;
//appel de la fonction crypt()
    if (m_method == 1)
    {
        cryptedChain=EmFunctions::crypt(decalage, ui->phraseLineEdit->text());
        QMessageBox::information(this, "Debug", ("La chaine chiffrée est : " + cryptedChain));
    }
    if(m_method==2)
    {
        cryptedChain=EmFunctions::crypt2(ui->phraseLineEdit->text());
        QMessageBox::information(this, "Debug", ("La chaine chiffrée est : " + cryptedChain));
    }
//debug :: appel pour test de la fonction deCrypt()
    if(m_method = 1)
    {
        QString deCryptedChain=EmFunctions::deCrypt(decalage, cryptedChain);
        QMessageBox::information(this, "Debug", ("La chaine déchiffrée est : " + deCryptedChain));
    }

//Appel de la fonction writeToConf(gbox1, QString )
    bool gbox1 = ui->gboxWelcomeConf->isChecked();
    QString pinCode = ui->codePinLineEdit->text();
    int pinCodeInt = pinCode.toInt();
    qDebug() << "pinCodeInt : " + pinCodeInt;
    int method = 1;
    QString phrase = ui->phraseLineEdit->text();

    EmFunctions::writeToConf(gbox1, m_placeToSave, pinCodeInt, method, cryptedChain, decalage);

}

EmConf::~EmConf()
{
    delete ui;
}
