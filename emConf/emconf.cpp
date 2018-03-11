#include "emconf.h"
#include "ui_emconf.h"
#include "emfunctions.h"


EmConf::EmConf(QWidget *parent) : QWidget(parent), ui(new Ui::EmConf)
{
    ui->setupUi(this);
//Paramètres d'initialisation de la fenêtre et des widgets
    ui->codePinLineEdit->setText("0000");
    ui->phraseLineEdit->setText("Le chien a l'air d'avoir faim");
    QObject::connect(ui->pushButtonQuit, SIGNAL(clicked(bool)), qApp, SLOT(quit()));
    QString defaultPlaceToSave = QStandardPaths::displayName(QStandardPaths::GenericDataLocation);

    ui->defaultPTSLabel->setText(defaultPlaceToSave);
    m_placeToSave = defaultPlaceToSave;
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
    cryptedChain=EmFunctions::crypt(decalage, ui->phraseLineEdit->text());
    QMessageBox::information(this, "Debug", ("La chaine chiffrée est : " + cryptedChain));
//debug :: appel pour test de la fonction deCrypt()
    QString deCryptedChain=EmFunctions::deCrypt(decalage, cryptedChain);
    QMessageBox::information(this, "Debug", ("La chaine déchiffrée est : " + deCryptedChain));

//Appel de la fonction writeToConf()
    bool gbox1 = ui->gboxWelcomeConf->isChecked();
    QString pinCode = ui->codePinLineEdit->text();
    QString phrase = ui->phraseLineEdit->text();
    EmFunctions::writeToConf(gbox1, pinCode, cryptedChain);

}

EmConf::~EmConf()
{
    delete ui;
}
