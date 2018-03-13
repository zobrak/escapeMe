#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMdiArea>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->centralWidget->setFixedSize(800,560);
    QBrush arrierePlan; // un QBrush
    QPixmap backgroud;
    backgroud.load(":/img/background.jpg");
    arrierePlan.setTexture(backgroud); // on lui attribue une image (qui ici, devra se trouver dans le dossier de l'exe
    ui->mdiArea->setBackground(arrierePlan);
    ui->subwindow->setAttribute(Qt::WA_TranslucentBackground, true);
    ui->subwindow_2->setAttribute(Qt::WA_TranslucentBackground, true);
}

MainWindow::~MainWindow()
{
    delete ui;
}
