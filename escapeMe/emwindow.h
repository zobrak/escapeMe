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
    void initializeScore();
    void pinDisplayHelpNr1();
    QString getConfFile();

    ~EmWindow();

private slots:
    //Slots fenetre principale

    void on_buttonHelp_clicked();
    void about();

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

private:
    Ui::EmWindow *ui;
    QString m_confFile;
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
    //Decrypt module
    QString m_secret;
    int m_decalage;
    QString m_answer;

    //Scores module
    int m_userCredit;

    void backgroundImage();
    void tips();
    void afficherPin(const int &number);

    void spendCredit(const int &amount);
    void winCredit(const int &amount);

};

#endif // EMWINDOW_H
