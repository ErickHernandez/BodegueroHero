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

void WinDialog::on_WinDialog_accepted()
{

}

void WinDialog::setText(QString texto)
{
    ui->lbl_Message->setText(texto);

}

void WinDialog::on_pushButton_2_clicked()
{

    this->hide();

}

void WinDialog::on_pushButton_3_clicked()
{

}
