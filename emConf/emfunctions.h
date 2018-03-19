#ifndef EMFUNCTIONS_H
#define EMFUNCTIONS_H
#include <QtWidgets>

class EmFunctions
{

public:
    EmFunctions();
    static QString setPlaceToSave(const QString &arg1);
    static QString crypt(bool const &way, const int &arg1, const QString &arg2);
    static QString crypt2(const QString &arg1);
    static void writeToConf(const bool &arg1, const QString &arg2, const int &arg3, const int &arg4, const QString &arg5, const int &arg6, const bool &arg7,
                            const int &arg8, const int &arg9);

private:

};

#endif // EMFUNCTIONS_H
