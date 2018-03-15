#include "dechiffrer.h"
#include "ui_dechiffrer.h"

Dechiffrer::Dechiffrer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Dechiffrer)
{
    ui->setupUi(this);
}

Dechiffrer::~Dechiffrer()
{
    delete ui;
}
