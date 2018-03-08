#include "emconf.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    EmConf w;
    w.show();

    return a.exec();
}
