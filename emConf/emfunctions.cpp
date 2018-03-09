#include "emfunctions.h"
#include <QDebug>

EmFunctions::EmFunctions()
{

}

QString EmFunctions::crypt(const int &arg1, const QString &arg2)
{
    QString tmpStr(arg2);
    int decalage(arg1);

/* Traitement de la chaine reçue en argument et passée dans la variable tmpStr
 * - Suppression des espaces et ponctuations.
 * - Remplacement des accents.
 * - Passage en majuscule.
 */
    tmpStr.remove(QRegExp("\\W"));
    tmpStr.replace(QRegExp("[éèëêËÊ]"),"e");
    tmpStr.replace(QRegExp("[àâäÄÂ]"), "a");
    tmpStr.replace(QRegExp("[iïîÏÎ]"), "i");
    tmpStr.replace(QRegExp("[ùüÜûÛ]"), "u");
    tmpStr.replace(QRegExp("[ôöÔÖ]"), "o");
    tmpStr.replace(QRegExp("[ç]"),"c");
    tmpStr = tmpStr.toUpper();

/*//Conversion de la chaine tmpStr en QByteArray
   const char* tmpChar = tmpStr.toStdString().c_str();
   QByteArray outChain;
   outChain=tmpChar;
   qDebug() << outChain;
   outChain=tmpStr.toLocal8Bit();
   qDebug() << outChain;
   QByteArray alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
   qDebug() << alphabet;
   QByteArray alphabetCrypted;
   alphabetCrypted.resize(26);
   qDebug() << alphabetCrypted;
//   for(int i(0); i<alphabetCrypted.end(); i++)
//        alphabetCrypted.at(i) =alphabet.at(i+decalage);
//    qDebug() << alphabet;
//    qDebug() << alphabetCrypted;
*/

    return tmpStr;
}
