#include "emconf.h"
#include "ui_emconf.h"
#include "emfunctions.h"


EmConf::EmConf(QWidget *parent) : QWidget(parent), ui(new Ui::EmConf)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButtonQuit, SIGNAL(clicked(bool)), qApp, SLOT(quit()));
}

void EmConf::on_pushButtonSave_clicked()
{
    QMessageBox::information(this, "Info !", "Le bouton Save a été cliqué");
    int decalage = ui->dCalageComboBox->currentText().toInt();
    EmFunctions::crypt(decalage, ui->phraseLineEdit->text());
}

EmConf::~EmConf()
{
    delete ui;
}
