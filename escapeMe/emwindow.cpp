#include "emwindow.h"
#include "ui_emwindow.h"

emWindow::emWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::emWindow)
{
    ui->setupUi(this);
}

emWindow::~emWindow()
{
    delete ui;
}
