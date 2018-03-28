#include "emconf.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QCoreApplication::setApplicationName("escapeMeApp");
    QCoreApplication::setApplicationVersion("1.2.1");
    QCoreApplication::setOrganizationName("ZobraKLab");
    QCoreApplication::setOrganizationDomain("zobrak.net");

    QApplication a(argc, argv);
    EmConf w;
    w.show();

    return a.exec();
}
