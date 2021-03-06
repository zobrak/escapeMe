#ifndef EMCONF_H
#define EMCONF_H

#include <QWidget>
#include <QMessageBox>

namespace Ui {
class EmConf;
}

class EmConf : public QWidget
{
    Q_OBJECT

public:
    explicit EmConf(QWidget *parent = 0);
    ~EmConf();

private slots:
    void on_pushButtonSave_clicked();
    void on_chngSavPlace_clicked();
    void on_buttonSaveHelpImg_clicked();
    void on_buttonSetConfToDefault_clicked();


    void on_buttonSaveDebugPlace_clicked();

    void on_buttonSetDefaultDebugPlace_clicked();

private:
    Ui::EmConf *ui;
    QString m_placeToSave;
    QString m_debugLogPlace;
    QString m_helpImg;
    int m_method;
};

#endif // EMCONF_H
