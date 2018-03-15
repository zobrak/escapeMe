#include "dechiffrer.h"
#include "pincode.h"
#include <QApplication>
#include <QStandardPaths>
#include <QSettings>
bool readConfig()
{
    QString confFile = QStandardPaths::locate(QStandardPaths::GenericDataLocation, "", QStandardPaths::LocateDirectory);
    confFile += "emConf.ini";
    QSettings* conf = new QSettings(confFile, QSettings::IniFormat, NULL);
    bool pinWindow = conf->value("WelcomeWindow/isActivated").toBool();
    bool isActivated=false;
    if(pinWindow)
        isActivated=true;

    delete conf;
    return isActivated;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QCoreApplication::setApplicationName("escapeMe core");
    QCoreApplication::setApplicationVersion("0.0.1");
    QCoreApplication::setOrganizationName("Damien GUEDON");
    QCoreApplication::setOrganizationDomain("zobrak.net");


       bool auth = readConfig();
       if(auth){
          // authentification requise, on fait monter la boîte d'authentification
          PinCode dlg;
          if(dlg.exec() != QDialog::Accepted){
             // c'est pas bon, fin du programme
             return a.exec();
          }
       }
       // lancement de la fenêtre principale
       Dechiffrer w;
       w.show();
       return a.exec();


    return a.exec();
}

