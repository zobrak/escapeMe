#include "emcore.h"
#include "ui_emcore.h"

EmCore::EmCore(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EmCore)
{
    ui->setupUi(this);
}

EmCore::~EmCore()
{
    delete ui;
}
