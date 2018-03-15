#ifndef EMMAIN_H
#define EMMAIN_H

#include <QMainWindow>

namespace Ui {
class emMain;
}

class emMain : public QMainWindow
{
    Q_OBJECT

public:
    explicit emMain(QWidget *parent = 0);
    ~emMain();

private:
    Ui::emMain *ui;
};

#endif // EMMAIN_H
