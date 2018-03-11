#include "emfunctions.h"



EmFunctions::EmFunctions()
{

}

QString EmFunctions::setPlaceToSave(const QString &arg1)
{
    QString placeToSave =  QFileDialog::getExistingDirectory(NULL, "Choisir l'emplacement de sauvegarde");
    if(placeToSave == "")
    {
         QMessageBox::warning(NULL, "Attention !", "L'emplacement de sauvegarde n'a pas été modifié");
                 return arg1;

    }
    QMessageBox::information(NULL, "Emplacement de sauvegarde", "Vous avez sélectionné :\n" + placeToSave);
    return placeToSave;
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

    tmpStr.remove(QRegExp("\\W")); //Suppression des ponctuations et symboles
    tmpStr.replace(QRegExp("[éèëêËÊ]"),"e"); // Remplacement des accents
    tmpStr.replace(QRegExp("[àâäÄÂ]"), "a");
    tmpStr.replace(QRegExp("[iïîÏÎ]"), "i");
    tmpStr.replace(QRegExp("[ùüÜûÛ]"), "u");
    tmpStr.replace(QRegExp("[ôöÔÖ]"), "o");
    tmpStr.replace(QRegExp("[ç]"),"c");
    tmpStr = tmpStr.toUpper();

    QString alphabetString = QObject::tr("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    int strLenght = tmpStr.size();
    int value;
    int alphabetLenght = alphabetString.size();



    QVector<QChar> tmpIn(strLenght);
    QVector<QChar> tmpOut(strLenght);
    QVector<QChar> alphabetVector(alphabetLenght);
    QVector<int> tmpElements(strLenght);

//Tranformation du QSTring tmpStr en QVector
    for (int i(0); i<strLenght; i++)
        tmpIn.insert(i, tmpStr.at(i));

//Transformation de alphabet en QVector
    for(int i(0); i<alphabetLenght ; i++)
        alphabetVector.insert(i, alphabetString.at(i));

//Boucle de décalage. On parcourt la chaine à chiffer et on enregistre une 'value' pour chaque élément
    for (int i(0); i<strLenght; i++)
    {
        for (int j(0); j<alphabetLenght; j++)
        {
            if(tmpIn.at(i) == alphabetVector.at(j))
            {
                value = j + decalage;

                if(value >= (alphabetLenght-value))
                    tmpElements.insert(i, (value %alphabetLenght));
                else
                    tmpElements.insert(i, value);
            }
         }
    }
//Pour chaque valeur du tableau éléments, on enregistre le caractère correspondant dans tmpOut
    for (int i(0); i<strLenght; i++)
    {
        for(int j(0); j<alphabetLenght; j++)
        {
            if(tmpElements.at(i) == j)
                tmpOut.insert(i, alphabetVector.at(j));

        }
    }

//Conversion du QVector en Qstring
    QString tmpStr2;
    for(int i(0); i<strLenght; i++)
        tmpStr2 += tmpOut.at(i);



    return tmpStr2;
}

QString EmFunctions::crypt2(const QString &arg1)
{
    QString tmpStr = arg1;
    tmpStr.remove(QRegExp("\\W")); //Suppression des ponctuations et symboles
    tmpStr.replace(QRegExp("[éèëêËÊ]"),"e"); // Remplacement des accents
    tmpStr.replace(QRegExp("[àâäÄÂ]"), "a");
    tmpStr.replace(QRegExp("[iïîÏÎ]"), "i");
    tmpStr.replace(QRegExp("[ùüÜûÛ]"), "u");
    tmpStr.replace(QRegExp("[ôöÔÖ]"), "o");
    tmpStr.replace(QRegExp("[ç]"),"c");
    tmpStr = tmpStr.toUpper();
qDebug() << "tmpStr :";
qDebug() << tmpStr;
    int strLenght = tmpStr.size();
qDebug() << " strLenght";
qDebug() << strLenght;
    int nbBlocks = 0;

    for (double i=strLenght; i>=(qFloor(strLenght/5)); i--)
    {
        if(strLenght%5 == 0)
        nbBlocks = i;
qDebug("nbBlocks");
qDebug() << nbBlocks;
    }
    QVector<QString> cryptedBlocks(nbBlocks);
    for(int i(0); i<strLenght; i++)
    {
        for (int j(0); j==nbBlocks; j++)
        {
            if(i%nbBlocks == j)
            cryptedBlocks.insert(j ,tmpStr.at(i));
        }
    }
    QString tmpOut;
    for(int i(0); i<nbBlocks; i++)
        tmpOut+=cryptedBlocks.at(i);
    return tmpOut;
}
QString EmFunctions::deCrypt(const int &arg1, const QString &arg2)
{
    QString tmpStr(arg2);
    int decalage(arg1);
    //Commme on décrypt on passe le décalage opposé dans la fonction.
    decalage -= 2*decalage;


    QString alphabetString = QObject::tr("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    int strLenght = tmpStr.size();
    int value;
    int alphabetLenght = alphabetString.size();



    QVector<QChar> tmpIn(strLenght);
    QVector<QChar> tmpOut(strLenght);
    QVector<QChar> alphabetVector(alphabetLenght);
    QVector<int> tmpElements(strLenght);

//Tranformation du QSTring tmpStr en QVector
    for (int i(0); i<strLenght; i++)
        tmpIn.insert(i, tmpStr.at(i));

//Transformation de alphabet en QVector
    for(int i(0); i<alphabetLenght ; i++)
        alphabetVector.insert(i, alphabetString.at(i));

//Boucle de décalage. On parcourt la chaine à chiffer et on enregistre une 'value' pour chaque élément
    for (int i(0); i<strLenght; i++)
    {
        for (int j(0); j<alphabetLenght; j++)
        {
            if(tmpIn.at(i) == alphabetVector.at(j))
            {
                value = j + decalage;

                if(value >= (alphabetLenght-value))
                    tmpElements.insert(i, (value %alphabetLenght));
                else
                    tmpElements.insert(i, value);
            }
         }
    }
//Pour chaque valeur du tableau éléments, on enregistre le caractère correspondant dans tmpOut
    for (int i(0); i<strLenght; i++)
    {
        for(int j(0); j<alphabetLenght; j++)
        {
            if(tmpElements.at(i) == j)
                tmpOut.insert(i, alphabetVector.at(j));

        }
    }

//Conversion du QVector en Qstring
    QString tmpStr2;
    for(int i(0); i<strLenght; i++)
        tmpStr2 += tmpOut.at(i);



    return tmpStr2;
}

void EmFunctions::writeToConf(const bool &arg1, // Est ce que la fenetre d'accueil est activée ?
                              const QString &arg2, //Dossier de sauvegarde
                              const int &arg3, // Code PIN
                              const int &arg4, // méthode de chiffrement
                              const QString &arg5, // Phrase à chiffrer
                              const int &arg6) // Valeur du décalage
{
/* Fonction ayant pour objet de récupérer les paramètres enregistrés par la fenêtre EmConf
 *  et de les écrire dans un fichier .ini */

//Emplacement de sauvegarde
    QString fileToSave = arg2;
    fileToSave+="/emConf.ini";
    QSettings* confFile = new QSettings(fileToSave, QSettings::IniFormat);

//Ecriture de la configuration
    //Création du groupe [WelcomeWindow]
       confFile->beginGroup("WelcomeWindow");
    //Ecriture des paramètres
       if(arg1)
       {
           confFile->setValue("isActivated", true);
           confFile->setValue("pinCode", arg3);
       }
       else
       {
           confFile->setValue("isActivated", false);
           confFile->setValue("pinCode","0000");
       }
       confFile->endGroup();
    // Groupe [SentencetoCrypt] -- les phrases sont stockées chiffrées dans le fichier
       confFile->beginGroup("SentenceToCrypt");

           confFile->setValue("method", arg4);
           confFile->setValue("decalage", arg6);
           confFile->setValue("sentence", arg5);

       confFile->endGroup();
    return;
}
