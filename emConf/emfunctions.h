#ifndef EMFUNCTIONS_H
#define EMFUNCTIONS_H
#include <QtWidgets>

class EmFunctions
{

public:
    EmFunctions();
    static QString crypt(const int &arg1, const QString &arg2);
    static QString deCrypt(const int &arg1, const QString &arg2);
    static void writeToConf(const bool &arg1, const QString &arg2, const QString &arg3);

private:

};

#endif // EMFUNCTIONS_H
