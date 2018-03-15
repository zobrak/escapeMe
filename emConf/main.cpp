#include "emconf.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QCoreApplication::setApplicationName("escapeMe config");
    QCoreApplication::setApplicationVersion("1.0.1");
    QCoreApplication::setOrganizationName("Damien GUEDON");
    QCoreApplication::setOrganizationDomain("zobrak.net");

    QApplication a(argc, argv);
    EmConf w;
    w.show();

    return a.exec();
}
