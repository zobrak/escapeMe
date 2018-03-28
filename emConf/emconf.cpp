#include "emconf.h"
#include "ui_emconf.h"
#include "emfunctions.h"


EmConf::EmConf(QWidget *parent) : QWidget(parent), ui(new Ui::EmConf)
{
    ui->setupUi(this);

    //As far as the crypt method nr 2 isn't operational we disable possibiliy to choose it
    ui->radioButtonMethod2->setDisabled(true);

    //Appel de EmFunctions::findConfPlace() pour obtenir l'emplacement par défaut du fichier de sauvegarde :
    m_placeToSave = EmFunctions::findConfPlace();

    QIntValidator* validPin = new QIntValidator(0,9999,ui->codePinLineEdit);
    //Paramètres d'initialisation de la fenêtre et des widgets
    ui->codePinLineEdit->setValidator(validPin);
    ui->codePinLineEdit->setText("0000");
    ui->phraseLineEdit->setText("Le chien a l'air d'avoir faim");
    ui->initialScore->setText("100");
    ui->basicCost->setText("5");
    //Paramétrage et affichage dans la fenêtre de l'emplacement de sauvegarde par défaut
    //m_placeToSave = QStandardPaths::locate(QStandardPaths::GenericDataLocation, "escapeMe", QStandardPaths::LocateDirectory);
    m_helpImg =  QStandardPaths::locate(QStandardPaths::AppDataLocation, "img/helpImg.jpg", QStandardPaths::LocateFile);
    ui->defaultPTSLabel->setText(m_placeToSave);
    ui->defaultHlpImgLabel->setText(m_helpImg);

    //Connections
    QObject::connect(ui->pushButtonQuit, SIGNAL(clicked(bool)), qApp, SLOT(quit()));
}
void EmConf::on_buttonSaveHelpImg_clicked()
{
    QString tmpstr = m_helpImg;
    tmpstr = EmFunctions::setHelpImg(tmpstr);
    m_helpImg = tmpstr;
    ui->defaultHlpImgLabel->setText(m_helpImg);

}
void EmConf::on_chngSavPlace_clicked()
{
    m_placeToSave = EmFunctions::setPlaceToSave(m_placeToSave);


    /* QString tmpStr = m_placeToSave;
    tmpStr = EmFunctions::setPlaceToSave(tmpStr);
    m_placeToSave = tmpStr;*/
    ui->defaultPTSLabel->setText(m_placeToSave);

}

void EmConf::on_pushButtonSave_clicked()
{

    //Choix de la méthode de chiffrement
    if(ui->radioButtonMethod1->isChecked())
        m_method = 1;
    if(ui->radioButtonMethod2->isChecked())
        m_method = 2;

    int decalage = ui->dCalageComboBox->currentText().toInt();
    QString cryptedChain;
    //appel de la fonction crypt()
    if(m_method == 1)
    {
        cryptedChain=EmFunctions::crypt(true, decalage, ui->phraseLineEdit->text());
        QMessageBox::information(this, "Debug", ("La chaine chiffrée est : " + cryptedChain));
        QString deCryptedChain=EmFunctions::crypt(false, decalage, cryptedChain);
        QMessageBox::information(this, "Debug", ("La chaine déchiffrée est : " + deCryptedChain));
        //QString deCryptedChain2=EmFunctions::deCrypt(decalage, cryptedChain);
        //QMessageBox::information(this, "Debug", ("La chaine déchiffrée est : " + deCryptedChain2));
    }
    if(m_method==2)
    {
        qDebug("m_method set to 2");
        cryptedChain=EmFunctions::crypt2(ui->phraseLineEdit->text());
        QMessageBox::information(this, "Debug", ("La chaine chiffrée est : " + cryptedChain));
    }

    //Appel de la fonction writeToConf(gbox1, QString )
    bool gbox1 = ui->gboxWelcomeConf->isChecked();
    bool gbox2 = ui->gboxHelpImage->isChecked();
    QString pinCode = ui->codePinLineEdit->text();
    int pinCodeInt = pinCode.toInt();
    qDebug() << pinCodeInt;
    int method = 1;
    bool scoresActivated = ui->groupBox->isChecked();
    int score = ui->initialScore->text().toInt();
    int cost = ui->basicCost->text().toInt();

    EmFunctions::writeToConf(gbox1, m_placeToSave, pinCodeInt, method, cryptedChain, decalage, scoresActivated, score, cost, gbox2, m_helpImg);

}

EmConf::~EmConf()
{
    delete ui;
}

void EmConf::on_buttonSetConfToDefault_clicked()
{
    QSettings conf;
    conf.setValue("config/isNotDefault", false);
    m_placeToSave = EmFunctions::findConfPlace();
    ui->defaultPTSLabel->setText(m_placeToSave);
}
