#ifndef EMWINDOW_H
#define EMWINDOW_H

#include <QWidget>

namespace Ui {
class EmWindow;
}

class EmWindow : public QWidget
{
    Q_OBJECT

public:
    explicit EmWindow(QWidget *parent = 0);
    int readConfigPinCode();
    bool readConfigIsPinActivated();
    void readConfigDecrypt();
    void readConfigScores();
    void pinDisplayHelpNr1();
    void logMessage(const QString &arg1);

    QString getConfFile();
    QString getScoreFile();
    QString getLogFile();



    ~EmWindow();

private slots:
    //Slots fenetre principale

    void on_buttonHelp_clicked();
    void about();
    void openConfig();

    //Slots fenetre pincode
    void on_buttonQuit1_clicked();
    void on_buttonContinue1_clicked();
    void on_retr_clicked();
    void on_num1_clicked();
    void on_num2_clicked();
    void on_num3_clicked();
    void on_num4_clicked();
    void on_num5_clicked();
    void on_num6_clicked();
    void on_num7_clicked();
    void on_num8_clicked();
    void on_num9_clicked();
    void on_num0_clicked();
    void validerPin();
    void viewLicense();

    //Slots fenêtre déchiffrer
    void on_buttonDecryptValid_clicked();
    void on_buttonQuit2_clicked();
    void on_stackedWidget_currentChanged(int arg1);
    void on_buttonContinue2_clicked();

    //Slots fenêtre scores
    void on_buttonQuitP3_clicked();
    void on_buttonSave_clicked();

private:
    Ui::EmWindow *ui;
    QString m_confFile;
    QString m_scoreFile;
    QString m_logFile;

    //Pincode module
    int m_confPin;
    int m_lcdValue;
    int num0 = 0;
    int num1 = 1;
    int num2 = 2;
    int num3 = 3;
    int num4 = 4;
    int num5 = 5;
    int num6 = 6;
    int num7 = 7;
    int num8 = 8;
    int num9 = 9;
    int m_count = 3;
    int help_count;
    bool m_pinFound = false;

    //Decrypt module
    QString m_secret;
    int m_decalage;
    QString m_answer;
    int m_method;
    bool m_sentenceFound = false;

    //Scores module
    int m_userCredit;
    int m_initialScore;
    int m_basicAmount;
    bool m_scoreIsActivated;
    bool m_scoreRegistered = false;

    void backgroundImage();
    void tips();
    void afficherPin(const int &number);
    void initializeUserScore();
    void spendCredit(const int &amount);
    void winCredit(const int &amount);

};

#endif // EMWINDOW_H
