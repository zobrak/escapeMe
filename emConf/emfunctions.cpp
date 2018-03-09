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
    int strLenght = tmpStr.size();
    int value;
    QVector<QChar> tmpIn(strLenght);
    QVector<QChar> tmpOut(strLenght);
    QVector<QChar> alphabetVector(26);
    QVector<int> tmpElements(strLenght);
    QString alphabetString = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    //Tranformation du QSTring tmpStr en QVector
    for (int i(0); i<strLenght; i++)
        tmpIn.push_back(tmpStr.at(i));
    //Transformation de alphabet en Qvector
    for(int i(0); i<26 ; i++)
            alphabetVector.push_back(alphabetString.at(i));
    //Boucle de décalage. On parcourt la chaine à chiffer et on enregistre une 'value' pour chaque élément
    for (int i(0); i<strLenght; i++)
    {
        for (int j(0); j<26; j++)
        {
            if(tmpIn.at(i) == alphabetVector.at(j))
            {
                value = j - decalage;
                if(value<0)
                {
                    value = 26+value;
                }
                if(value >= 26)
                    tmpElements.replace(i, (value % 26));
                else
                    tmpElements.replace(i, value);
            }
         }
    }
    //Pour chaque valeur du tableau éléments, on enregistre le caractère correspondant dans tmpOut
    for (int i(0); i<strLenght; i++)
    {
        for(int j(0); j<26; j++)
        {
            if(tmpElements.at(i) == j)
                tmpOut.replace(i, alphabetVector.at(j));

        }
    }

    //Conversion du QVector en Qstring
    QString tmpStr2;
    for(int i(0); i<strLenght; i++)
        tmpStr2 += tmpOut.at(i);



    return tmpStr2;
}
