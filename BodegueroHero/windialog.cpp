#include "windialog.h"
#include "ui_windialog.h"

WinDialog::WinDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WinDialog)
{
    ui->setupUi(this);
}

WinDialog::~WinDialog()
{

    delete ui;
}
void WinDialog::setTexto(QString texto)
{
    ui->lbl_texto->setText(texto);
}
void WinDialog::closeEvent(QCloseEvent *e)
{
    responder(this->windowTitle());
}

void WinDialog::on_pushButton_clicked()
{
    this->hide();
    responder(this->windowTitle());
}
