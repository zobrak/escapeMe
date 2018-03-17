#ifndef EMCORE_H
#define EMCORE_H

#include <QWidget>

namespace Ui {
class EmCore;
}

class EmCore : public QWidget
{
    Q_OBJECT

public:
    explicit EmCore(QWidget *parent = 0);
    ~EmCore();

private:
    Ui::EmCore *ui;
};

#endif // EMCORE_H
