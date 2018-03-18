#ifndef EMWINDOW_H
#define EMWINDOW_H

#include <QWidget>

namespace Ui {
class emWindow;
}

class emWindow : public QWidget
{
    Q_OBJECT

public:
    explicit emWindow(QWidget *parent = 0);
    ~emWindow();

private:
    Ui::emWindow *ui;
};

#endif // EMWINDOW_H
