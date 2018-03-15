#include "emmain.h"
#include "ui_emmain.h"

emMain::emMain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::emMain)
{
    ui->setupUi(this);
}

emMain::~emMain()
{
    delete ui;
}
