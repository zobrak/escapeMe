#ifndef DECHIFFRER_H
#define DECHIFFRER_H

#include <QWidget>

namespace Ui {
class Dechiffrer;
}

class Dechiffrer : public QWidget
{
    Q_OBJECT

public:
    explicit Dechiffrer(QWidget *parent = 0);
    ~Dechiffrer();

private:
    Ui::Dechiffrer *ui;
};

#endif // DECHIFFRER_H
