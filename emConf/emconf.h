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

private:
    Ui::EmConf *ui;
};

#endif // EMCONF_H
