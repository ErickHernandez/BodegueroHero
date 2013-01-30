#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFile"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QFile file(":/qss/style.qss");
    if(file.open(QFile::ReadOnly)) {
       QString StyleSheet = QLatin1String(file.readAll());
       qApp->setStyleSheet(StyleSheet);
    }

    ui->setupUi(this);    
}

MainWindow::~MainWindow()
{
    delete ui;            
}


void MainWindow::on_btSeleccionar_clicked()
{
    ui->screenManager->setCurrentIndex(2);
}

void MainWindow::on_btCrear_clicked()
{
    ui->screenManager->setCurrentIndex(3);
}

void MainWindow::on_btJugar_clicked()
{
    ui->screenManager->setCurrentIndex(4);
}

void MainWindow::on_btBack_clicked()
{
     ui->screenManager->setCurrentIndex(0);
}

void MainWindow::on_btnBackFromP4_clicked()
{
    //!!Comment: Moises
    //Presione Back en la pagina4 (pantalla de dificultades)
    //Regreso a la pantalla del menu de opciones (pagina1)
    this->ui->screenManager->setCurrentIndex(1);
}
