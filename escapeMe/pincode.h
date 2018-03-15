#ifndef PINCODE_H
#define PINCODE_H

#include <QDialog>

namespace Ui {
class PinCode;
}

class PinCode : public QDialog
{
    Q_OBJECT

public:
    explicit PinCode(QWidget *parent = 0);
    void afficher(const int &number);


    ~PinCode();

private slots:
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
     void valider();

private:
    Ui::PinCode *ui;
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
    int m_lcdPinCode;
    int m_confPin;
    QString m_configFile;
};

#endif // PINCODE_H
