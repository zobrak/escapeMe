#include "emwindow.h"
#include <QApplication>
#include <QStandardPaths>
#include <QSettings>
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>


int main(int argc, char *argv[])
{
    QCoreApplication::setApplicationName("escape.Me");
    QCoreApplication::setApplicationVersion("0.6.0");
    QCoreApplication::setOrganizationName("ZobraK");
    QCoreApplication::setOrganizationDomain("zobrak.net");
    QApplication a(argc, argv);

    QString locale = QLocale::system().name().section('_', 0, 0);
    QTranslator translator;
       translator.load(QString("qt_") + locale, QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    a.installTranslator(&translator);

    EmWindow w;
    w.show();
    return a.exec();
}

