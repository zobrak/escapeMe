#ifndef DECHIFFRER_H
#define DECHIFFRER_H

#include <QDialog>

namespace Ui {
class Dechiffrer;
}

class Dechiffrer : public QDialog
{
    Q_OBJECT

public:
    explicit Dechiffrer(QWidget *parent = 0);

    ~Dechiffrer();

private slots :
    void on_buttonVerif_clicked();

private:
    Ui::Dechiffrer *ui;
    QString m_configFile;
    QString m_secret;
    QString m_verif;
    QString m_answer;
    int m_decalage;



};

#endif // DECHIFFRER_H
