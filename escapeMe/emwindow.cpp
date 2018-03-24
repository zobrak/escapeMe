#include "emwindow.h"
#include "ui_emwindow.h"
#include "../emConf/emfunctions.h"
#include <QStandardPaths>
#include <QSettings>
#include <QDebug>
#include <QMessageBox>
#include <QTextEdit>
#include <QFile>
#include <QKeySequence>

EmWindow::EmWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EmWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    setFixedSize(780,480);
    help_count = 3;

    //Initialisation des scores
    readConfigScores();
    if(!m_scoreIsActivated)
    {
        ui->buttonContinue2->hide();
        ui->scoreLcdNumber->hide();
        ui->scoreLbl->hide();
        ui->buttonDecryptValid->setText(tr("Valider"));
    }
    else initializeUserScore();


    //Background-image
    backgroundImage();

    //Tips
    tips();

    //Lancement conditionnel du codepin si activé dans la config.
    bool pinWindow = readConfigIsPinActivated();
    if(pinWindow)
    {
        ui->stackedWidget->setCurrentIndex(1);
        ui->stackedWidget->setCurrentIndex(0);
        ui->pinLcdNumber->display(0);
        ui->buttonContinue1->setDisabled(true);
        connect(ui->entr,SIGNAL(clicked(bool)), this, SLOT(validerPin()));
        connect(ui->buttonAbout, SIGNAL(clicked(bool)), this, SLOT(about()));
    }
    else
    {
        ui->stackedWidget->setCurrentIndex(0);
        ui->stackedWidget->setCurrentIndex(1);
    }

    QShortcut *shrtcutLaunchConf = new QShortcut(tr("Ctrl+Shift+C"), this);
    //Connections
    connect(shrtcutLaunchConf, SIGNAL(activated()), this, SLOT(openConfig()));



}
void EmWindow::afficher1()
{
    afficherPin(1);
}
void EmWindow::afficher2()
{
    afficherPin(2);
}
void EmWindow::afficher3()
{
    afficherPin(3);
}
void EmWindow::afficher4()
{
    afficherPin(4);
}
void EmWindow::afficher5()
{
    afficherPin(5);
}
void EmWindow::afficher6()
{
    afficherPin(6);
}
void EmWindow::afficher7()
{
    afficherPin(7);
}
void EmWindow::afficher8()
{
    afficherPin(8);
}
void EmWindow::afficher9()
{
    afficherPin(9);
}
void EmWindow::afficher0()
{
    afficherPin(0);
}
EmWindow::~EmWindow()
{
    delete ui;
}

//Fonctions internes
void EmWindow::openConfig()
{
    QProcess *config = new QProcess(this);
    QString programmPath = QStandardPaths::locate(QStandardPaths::AppDataLocation, "", QStandardPaths::LocateDirectory);
    programmPath +="emConf.exe";
logMessage("[openconfig()] programmPath set to :");
logMessage(programmPath);
    //QString programm = "/home/cmatic/devProjects/escapeMe/build-emConf-Desktop_Qt_5_10_1_GCC_64bit-Release/emConf";
    config->start(programmPath);
}
QString EmWindow::getConfFile()
{
    m_confFile = QStandardPaths::locate(QStandardPaths::GenericDataLocation, "escapeMe", QStandardPaths::LocateDirectory);
    m_confFile += "/emConf.ini";
logMessage("[getConfFile()] - confFile path :");
logMessage(m_confFile);
    return m_confFile;
}
QString EmWindow::getScoreFile()
{
    m_scoreFile = QStandardPaths::locate(QStandardPaths::DocumentsLocation, "", QStandardPaths::LocateDirectory);
    m_scoreFile += "escapeMeScores.txt";
logMessage("[getScoreFile() - m_scoreFile :");
logMessage(m_scoreFile);
    return m_scoreFile;
}
QString EmWindow::getLogFile()
{
    m_logFile = QStandardPaths::locate(QStandardPaths::GenericDataLocation, "escapeMe", QStandardPaths::LocateDirectory);
    m_logFile += "/debug.log";
qDebug() << "m_logfile set to : " << m_logFile;
    return m_logFile;
}
bool EmWindow::readConfigIsPinActivated()
{
    getConfFile();
    QSettings* conf = new QSettings(m_confFile, QSettings::IniFormat, this);
    bool isActivated = conf->value("WelcomeWindow/isActivated").toBool();
    delete conf;
    return isActivated;
}

int EmWindow::readConfigPinCode()
{
    getConfFile();
    QSettings* conf = new QSettings(m_confFile, QSettings::IniFormat, this);
    m_confPin= conf->value("WelcomeWindow/pinCode").toInt();
    delete conf;
    return m_confPin;
}

void EmWindow::readConfigDecrypt()
{
    getConfFile();
    QSettings* conf = new QSettings(m_confFile, QSettings::IniFormat, this);
    m_secret = conf->value("SentenceToCrypt/sentence").toString();
    m_decalage = conf->value("SentenceToCrypt/decalage").toInt();
    m_method = conf->value("SentenceToCrypt/method").toInt();
    delete conf;
    return;
}

void EmWindow::readConfigScores()
{
    getConfFile();
    QSettings* conf = new QSettings(m_confFile, QSettings::IniFormat, this);
    m_scoreIsActivated = conf->value("Scores/isActivated").toBool();
    m_initialScore = conf->value("Scores/initialScore").toInt();
    m_basicAmount = conf->value("Scores/basicAmount").toInt();
}

void EmWindow::tips()
{
    if(ui->stackedWidget->currentIndex() == 0)
        ui->emMessage->setText(tr("Entrez le code de dévérouillage...\n(code à 4 chiffres)"));
    if(ui->stackedWidget->currentIndex() == 1)
        ui->emMessage->setText(tr("Déchiffrez la phrase cryptée"));
    if(ui->stackedWidget->currentIndex() == 2)
        ui->emMessage->setText(tr("Enregistrez votre score !"));

}

void EmWindow::backgroundImage()
{
    QPalette p;
    QPixmap background;
    background.load(":/img/background.jpg");
    p = palette();
    p.setBrush(QPalette::Window, QBrush(QPixmap(background)));
    setPalette(p);
    ui->stackedWidget->setPalette(p);
}

void EmWindow::afficherPin(const int &number)
{
    int tmp;

    if(ui->pinLcdNumber->intValue() == 0)
    {
        ui->pinLcdNumber->display(number);
        return;
    }
    else
    {
        tmp = ui->pinLcdNumber->intValue();
        tmp *= 10;
        tmp += number;
        ui->pinLcdNumber->display(tmp);
    }
/* old implementation, newer is simpler
    if(ui->pinLcdNumber->intValue() < 10)
    {
        int tmp;
        tmp = ui->pinLcdNumber->intValue();
        tmp *= 10;
        tmp += number;
        ui->pinLcdNumber->display(tmp);
        return;
    }
    if(ui->pinLcdNumber->intValue() < 100)
    {
        int tmp;
        tmp = ui->pinLcdNumber->intValue();
        tmp *=10;
        tmp += number;
        ui->pinLcdNumber->display(tmp);
        return;
    }
    if(ui->pinLcdNumber->intValue() < 1000)
    {
        int tmp;
        tmp = ui->pinLcdNumber->intValue();
        tmp *=10;
        tmp += number;
        ui->pinLcdNumber->display(tmp);
        return;
    } */
}

void EmWindow::initializeUserScore()
{
    m_userCredit = m_initialScore;
    ui->scoreLcdNumber->display(m_userCredit);
    return;
}

void EmWindow::spendCredit(const int &amount)
{
    m_userCredit -= amount;
    ui->scoreLcdNumber->display(m_userCredit);
}

void EmWindow::winCredit(const int &amount)
{
    m_userCredit += amount;
    ui->scoreLcdNumber->display(m_userCredit);
}

void EmWindow::pinDisplayHelpNr1()
{
    QDialog* pinHelp1 = new QDialog(this);
    QLabel* picture = new QLabel(this);
    QPushButton* buttonClose = new QPushButton(this);
    QVBoxLayout* dlgLayout = new QVBoxLayout(this);
    picture->setPixmap(QPixmap(":/img/4x4.jpg"));
    buttonClose->setText("Ok");
    dlgLayout->addWidget(picture);
    dlgLayout->addWidget(buttonClose);
    pinHelp1->setLayout(dlgLayout);
    connect(buttonClose, SIGNAL(clicked(bool)), pinHelp1, SLOT(accept()));
    pinHelp1->exec();

}

//Slots fenêtre principale
void EmWindow::about()
{
    QDialog* aboutEscapeMe = new QDialog(this);

    aboutEscapeMe->setWindowTitle(tr("A propos de cette application..."));
    QGridLayout* dlgLayout = new QGridLayout(aboutEscapeMe);
    QLabel* appImage = new QLabel(aboutEscapeMe);
    QLabel* appName = new QLabel(aboutEscapeMe);
    QLabel* appVersion = new QLabel(aboutEscapeMe);
    QLabel* authorNameLbl = new QLabel(aboutEscapeMe);
    QLabel* authorNameValue = new QLabel(aboutEscapeMe);
    QLabel* authorURLLbl = new QLabel(aboutEscapeMe);
    QLabel* authorURLValue = new QLabel(aboutEscapeMe);
    QLabel* sourcesLbl = new QLabel(aboutEscapeMe);
    QLabel* sourcesURL = new QLabel(aboutEscapeMe);
    QPushButton* buttonAboutQt = new QPushButton(aboutEscapeMe);
    QLabel* devWith = new QLabel(aboutEscapeMe);
    QLabel* appLicense = new QLabel(aboutEscapeMe);
    QPushButton* buttonViewLicense = new QPushButton(aboutEscapeMe);
    QPushButton* buttonCloseAbout = new QPushButton(aboutEscapeMe);

    QString versionInfo;
        versionInfo = "Version : ";
        versionInfo += QCoreApplication::applicationVersion();
    QString formatedAppName;
        formatedAppName = "<strong>";
        formatedAppName += QCoreApplication::applicationName();
        formatedAppName += "</strong>";
    QString orgURL;
        orgURL ="<a href=\"https://www.";
        orgURL +=QCoreApplication::organizationDomain();
        orgURL +="/\">www.";
        orgURL +=QCoreApplication::organizationDomain();
        orgURL +="</a>";
qDebug() << orgURL;
    QString srcURL;
        srcURL = "<a href =\"https://github.com/zobrak/escapeme\">";
        srcURL += "Page github";
        srcURL += "</a>";
qDebug() << srcURL;

    appImage->setPixmap(QPixmap(":/img/escapeme.ico"));
    appName->setTextFormat(Qt::RichText);
    appName->setText(formatedAppName);
    appVersion->setText(versionInfo);
    authorNameLbl->setText(tr("Application développée par : "));
    authorNameValue->setText(QCoreApplication::organizationName());
    authorURLLbl->setText(tr("Site web de l'auteur : "));
    authorURLValue->setText(orgURL);
    authorURLValue->setTextFormat(Qt::RichText);
    authorURLValue->setTextInteractionFlags(Qt::TextBrowserInteraction);
    authorURLValue->setOpenExternalLinks(true);
    sourcesLbl->setText(tr("Page github du projet : "));
    sourcesURL->setText(srcURL);
    sourcesURL->setTextFormat(Qt::RichText);
    sourcesURL->setTextInteractionFlags(Qt::TextBrowserInteraction);
    sourcesLbl->setOpenExternalLinks(true);
    devWith->setText(tr("Application développée en C++, avec Qt"));
    buttonAboutQt->setText(tr("A propos de Qt"));
    appLicense->setText(tr("Projet open-source sous licence GNU LGPL v3.0"));
    buttonViewLicense->setText(tr("Consulter la licence"));
    buttonCloseAbout->setText(tr("Ok"));


    dlgLayout->addWidget(appImage,0,0,2,2);
    dlgLayout->addWidget(appName,0,1,1,2,Qt::AlignCenter);
    dlgLayout->addWidget(appVersion,1,1,1,2,Qt::AlignCenter);
    dlgLayout->addWidget(authorNameLbl,2,0);
    dlgLayout->addWidget(authorNameValue,2,1);
    dlgLayout->addWidget(authorURLLbl,3,0);
    dlgLayout->addWidget(authorURLValue,3,1);
    dlgLayout->addWidget(sourcesLbl,4,0);
    dlgLayout->addWidget(sourcesURL,4,1);
    dlgLayout->addWidget(devWith,5,0);
    dlgLayout->addWidget(buttonAboutQt,5,1);
    dlgLayout->addWidget(appLicense,6,0);
    dlgLayout->addWidget(buttonViewLicense,6,1,1,2);
    dlgLayout->addWidget(buttonCloseAbout,7,0,1,3);
    aboutEscapeMe->setLayout(dlgLayout);

    connect(buttonAboutQt, SIGNAL(clicked(bool)), qApp, SLOT(aboutQt()));
    connect(buttonViewLicense, SIGNAL(clicked(bool)), this, SLOT(viewLicense()));
    connect(buttonCloseAbout, SIGNAL(clicked(bool)), aboutEscapeMe, SLOT(accept()));
    aboutEscapeMe->exec();
}
void EmWindow::viewLicense()
{
    QDialog* license = new QDialog(this);
    QVBoxLayout *licLayout = new QVBoxLayout(license);
    QTextEdit* displayLicense = new QTextEdit(license);
    QPushButton* buttonCloseLicWindow = new QPushButton(license);
    QString licenseContent;
    QFile file(":/txt/LICENSE");
          if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
              return;
          QTextStream in(&file);
          while (!in.atEnd())
          {
            QString line = in.readLine();
            licenseContent += line;
            licenseContent += "\n";
          }
   displayLicense->setText(licenseContent);
   displayLicense->setReadOnly(true);
   buttonCloseLicWindow->setText(tr("Ok"));
   licLayout->addWidget(displayLicense);
   licLayout->addWidget(buttonCloseLicWindow);
   license->setLayout(licLayout);
   license->setGeometry(0,0,400,400);
   connect(buttonCloseLicWindow, SIGNAL(clicked(bool)), license, SLOT(accept()));
   license->exec();
}
void EmWindow::on_buttonHelp_clicked()
{
    if(ui->stackedWidget->currentIndex() == 2)
        QMessageBox::information(this,tr("Information"), tr("Pas d'aide spécifique pour ce module...\n"
                                                            "Enregistrez votre score pour marquer des points supplémentaires."));
    else
    {
        QString messageQuestion;
        messageQuestion += tr("Demander de l'aide vous coutera ");
        messageQuestion += QString::number(m_basicAmount);
        messageQuestion += tr(" points sur votre score ! Voulez-vous continuer ?");
        QString msgWindow;
        msgWindow += tr("Ce conseil vous a coûté ");
        msgWindow += QString::number(m_basicAmount);
        msgWindow += tr(" points");
        int confirmHelp =  QMessageBox::question(this,tr("Attention !!!"), messageQuestion);
        if(confirmHelp== QMessageBox::Yes)
        {
            help_count--;
            spendCredit(m_basicAmount);
            switch(ui->stackedWidget->currentIndex())
            {
            case 0:
               ui->emMessage->setText(msgWindow);
               pinDisplayHelpNr1();
               break;
            case 1:
                if(m_method == 1)
                {
                    if(help_count == 2)
                        {
                            QDesktopServices::openUrl(QUrl("https://fr.wikipedia.org/wiki/Chiffrement_par_d%C3%A9calage", QUrl::TolerantMode));
                            ui->emMessage->setText(msgWindow);
                            break;
                        }
                    if(help_count == 1)
                        {
                            QString msg;
                            msg = "Le décalage utilisé pour ce chiffrement est de : ";
                            msg += QString::number(m_decalage);
                            QMessageBox::information(this,"Astuce", msg);
                            break;
                        }
                    if(help_count == 0)
                        qDebug() << help_count;
                }

                if(m_method == 2)
                {
                    QString msg;
                    msg += tr("C'est un tableau, avec des lignes et des colonnes...\n");
                    msg += msgWindow;
                    ui->emMessage->setText(msg);
                    break;
                }
            case 2:
               ui->emMessage->setText(msgWindow);
               break;
            }

        }
    }
}
void EmWindow::on_stackedWidget_currentChanged(int arg1)
{
    int currentIndex = arg1;
    if(currentIndex == 0)
    {
        //Affichage dans pinLcdNumber en appuyant sur les touches
        QShortcut *shrtcut1 = new QShortcut(tr("1"), this);
        QShortcut *shrtcut2 = new QShortcut(tr("2"), this);
        QShortcut *shrtcut3 = new QShortcut(tr("3"), this);
        QShortcut *shrtcut4 = new QShortcut(tr("4"), this);
        QShortcut *shrtcut5 = new QShortcut(tr("5"), this);
        QShortcut *shrtcut6 = new QShortcut(tr("6"), this);
        QShortcut *shrtcut7 = new QShortcut(tr("7"), this);
        QShortcut *shrtcut8 = new QShortcut(tr("8"), this);
        QShortcut *shrtcut9 = new QShortcut(tr("9"), this);
        QShortcut *shrtcut0 = new QShortcut(tr("0"), this);
        connect(shrtcut1, SIGNAL(activated()), this, SLOT(afficher1()));
        connect(shrtcut2, SIGNAL(activated()), this, SLOT(afficher2()));
        connect(shrtcut3, SIGNAL(activated()), this, SLOT(afficher3()));
        connect(shrtcut4, SIGNAL(activated()), this, SLOT(afficher4()));
        connect(shrtcut5, SIGNAL(activated()), this, SLOT(afficher5()));
        connect(shrtcut6, SIGNAL(activated()), this, SLOT(afficher6()));
        connect(shrtcut7, SIGNAL(activated()), this, SLOT(afficher7()));
        connect(shrtcut8, SIGNAL(activated()), this, SLOT(afficher8()));
        connect(shrtcut9, SIGNAL(activated()), this, SLOT(afficher9()));
        connect(shrtcut0, SIGNAL(activated()), this, SLOT(afficher0()));
    }

    if(currentIndex == 1)
        readConfigDecrypt();
        ui->displaySentence->setText(m_secret);
}

//Slots fenêtre pinCode
void EmWindow::on_buttonQuit1_clicked()
{
    qApp->quit();
}
void EmWindow::on_buttonContinue1_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    tips();
}
void EmWindow::on_retr_clicked()
{
    ui->pinLcdNumber->display(0);
}
void EmWindow::on_num1_clicked()
{
    EmWindow::afficherPin(num1);
}
void EmWindow::on_num2_clicked()
{
    EmWindow::afficherPin(num2);
}
void EmWindow::on_num3_clicked()
{
    EmWindow::afficherPin(num3);
}
void EmWindow::on_num4_clicked()
{
    EmWindow::afficherPin(num4);
}
void EmWindow::on_num5_clicked()
{
    EmWindow::afficherPin(num5);
}
void EmWindow::on_num6_clicked()
{
    EmWindow::afficherPin(num6);
}
void EmWindow::on_num7_clicked()
{
    EmWindow::afficherPin(num7);
}
void EmWindow::on_num8_clicked()
{
    EmWindow::afficherPin(num8);
}
void EmWindow::on_num9_clicked()
{
    EmWindow::afficherPin(num9);
}
void EmWindow::on_num0_clicked()
{
    EmWindow::afficherPin(num0);
}
void EmWindow::validerPin()
{
    readConfigPinCode();
    m_lcdValue = ui->pinLcdNumber->value();

    if(!m_pinFound)
    {
        if(m_lcdValue == m_confPin)
        {
            int win = 3*m_basicAmount - (3-m_count)*m_basicAmount;
            QString message = tr("Bravo ! c'est le bon code !\n");
            message += QString::number(3-m_count);
            message += tr(" echec(s) = ");
            message += QString::number(win);
            message += tr(" points gagnés !");
            ui->buttonContinue1->setDisabled(false);

            winCredit(win);
            m_pinFound = true;
            ui->emMessage->setText(message);
        }
        else
        {
            if(m_scoreIsActivated)
            {
                int price = m_basicAmount*3;
                m_count--;
                QString message;
                message += tr(" Erreur !!! Ca n'est pas le bon code ! il vous reste ");
                message += QString::number(m_count);
                message += tr(" essais.\n (");
                message += QString::number(price);
                message += tr(" points retirés en cas d'echec !)");
                if(m_count>0)
                {
                    ui->pinLcdNumber->display(0);
                    ui->emMessage->setText(message);
                }
                if(m_count == 0)
                {
                    message = tr("Aïe ! 3 essais manqués :(\n");
                    message += QString::number(price);
                    message += " points débités.";
                    spendCredit(price);
                    ui->pinLcdNumber->display(0);
                    ui->emMessage->setText(message);
                    m_count = 3;
                }
            }
            else ui->emMessage->setText(tr("Erreur !!! Ca n'est pas le bon code !"));
        }
    }
    else
    {
        spendCredit(2);
        ui->emMessage->setText(tr("Vous avez déjà trouvé le code.\nInutile de chercher à gagner des points en trichant : -2 points !"));
        ui->entr->setDisabled(true);
    }


}

//Slots fenêtre déchiffrer
void EmWindow::on_buttonDecryptValid_clicked()
{
    if(!m_sentenceFound)
    {
        spendCredit(m_basicAmount);
        m_answer=ui->answerLineEdit->text();
        m_answer = EmFunctions::crypt(true, m_decalage, m_answer);
        if(m_answer == m_secret)
        {
            m_sentenceFound = true;
            ui->buttonContinue2->setDisabled(false);
            ui->emMessage->setText("Bravo ! Vous avez trouvé");
            winCredit(4*m_basicAmount);
        }
        else
        {
            ui->emMessage->setText("Mauvaise réponse, cherchez encore !");
            ui->answerLineEdit->setText("");
        }
        return;
    }
    else
    {
        spendCredit(2);
        ui->emMessage->setText(tr("Vous avez déjà trouvé la phrase.\nInutile de chercher à gagner des points en trichant :\n -2 points !"));
        ui->buttonDecryptValid->setDisabled(true);
    }
}
void EmWindow::on_buttonQuit2_clicked()
{
    qApp->quit();
}
void EmWindow::on_buttonContinue2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->finalScoreLcdNumber->display(m_userCredit);
    tips();
}

//Slots fenêtre score
void EmWindow::on_buttonQuitP3_clicked()
{
    if(m_scoreRegistered)
    qApp->quit();
    else
    {
        int reponse = QMessageBox::question(this, tr("Attention !"), tr("Vous n'avez pas enregistré votre score, "
                                                                        "si vous quittez vous allez perdre le bénéfice de vos points !\n"
                                                                        "Etes-vous certain de vouloir quitter ?"));
        if (reponse == QMessageBox::Yes)
            qApp->quit();
        else return;
    }
}

void EmWindow::on_buttonSave_clicked()
{
    if(ui->teamNameEdit->text() == "")
    {
       QMessageBox::warning(this, tr("Erreur"), tr("Vous devez entrer un nom d'équipe"));
       return;
    }
    else
    {
        getScoreFile();
        QString scoreLine;
        scoreLine += ui->teamNameEdit->text();
        scoreLine += ";";
        scoreLine += ui->className->currentText();
        scoreLine += ";";
        scoreLine += QString::number(m_userCredit);
        scoreLine += "\n";
        QFile file(m_scoreFile);
              if (!file.open(QIODevice::Append | QIODevice::Text))
                  return;
              QTextStream out(&file);
              out << scoreLine;

    m_scoreRegistered = true;
    QMessageBox::information(this, tr("Information"), tr("Votre score a été enregistré"));
    return;
    }
}
void EmWindow::logMessage(const QString &arg1)
{
    getLogFile();
    QString tmp = arg1;
    tmp += "\n";
    QFile log(m_logFile);
    if (!log.open(QIODevice::Append | QIODevice::Text))
        return;
    QTextStream out(&log);
    out << tmp;
}


