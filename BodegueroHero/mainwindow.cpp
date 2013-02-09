#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFile"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QFile file(":/qss/style.qss");//

    if(file.open(QFile::ReadOnly)) {
       QString StyleSheet = QLatin1String(file.readAll());
       qApp->setStyleSheet(StyleSheet);
   }
    createConection();
    CrearTablas();
    cargarPerfil();

    //MM: ESTE ES UN TEST PARA PINTAR EL PREVIEW
    this->ui->graphicsView_Preview->setScene(new GraphicsScenePreview("asdasd"));
}

void MainWindow::cargarPerfil()
{

    ui->player1->setVisible(false);ui->player2->setVisible(false);ui->player3->setVisible(false);
                            ui->player4->setVisible(false);
                                        ui->player5->setVisible(false);
     QList<QString> jugadores =  SelectAllJugadoresL();

     QSignalMapper *signalMapper = new QSignalMapper(this);
     if(jugadores.size()>0){
        ui->player1->setVisible(true);
        ui->player1->setText(jugadores.at(0));
       connect(ui->player1, SIGNAL(clicked()), signalMapper, SLOT(map()));
       signalMapper->setMapping(ui->player1,jugadores.at(0));
   }
     if (jugadores.size()>1){
       ui->player2->setVisible(true);
       ui->player2->setText(jugadores.at(1));
       connect(ui->player2, SIGNAL(clicked()), signalMapper, SLOT(map()));
       signalMapper->setMapping(ui->player2,jugadores.at(1));
   }
     if (jugadores.size()>2){
          ui->player3->setVisible(true);
       ui->player3->setText(jugadores.at(2));
       connect(ui->player3, SIGNAL(clicked()), signalMapper, SLOT(map()));
       signalMapper->setMapping(ui->player3,jugadores.at(2));
      }

     if (jugadores.size()>3){
       ui->player4->setVisible(true);
       ui->player4->setText(jugadores.at(3));
       connect(ui->player4, SIGNAL(clicked()), signalMapper, SLOT(map()));
       signalMapper->setMapping(ui->player4,jugadores.at(3));
   }
     if(jugadores.size()>4){
       ui->player5->setVisible(true);
       ui->player5->setText(jugadores.at(4));
       connect(ui->player5, SIGNAL(clicked()), signalMapper, SLOT(map()));
       signalMapper->setMapping(ui->player5,jugadores.at(4));

   }

       connect(signalMapper, SIGNAL(mapped(const QString &)),
                 this, SIGNAL(escribir(const QString &)));


     QObject::connect(signalMapper,SIGNAL(mapped(QString)),this,SLOT(recibir(QString)));

}

MainWindow::~MainWindow()
{
    delete ui;            
}

void MainWindow::recibir(const QString & txt)
{
   this->CurrentUser=txt;
   ui->screenManager->setCurrentIndex(0);
}

void MainWindow::on_pushButton_clicked()
{
    QString nombre =ui->NewPlayer->toPlainText();
    CrearPerfil(nombre);
    ui->NewPlayer->clear();
    cargarPerfil();
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

void MainWindow::on_cmdStart_clicked()
{
    this->ui->screenManager->setCurrentIndex(1);
}

void MainWindow::on_actionHome_triggered()
{
    //EH: si esta en la pantalla de juegos preguntarle si quiere abandonar el juego.
    this->ui->screenManager->setCurrentIndex(0);
}

void MainWindow::on_actionBack_triggered()
{
    int index = this->ui->screenManager->currentIndex();

    if(index>0)
    {
        if(index == 7)// si esta en la pantalla de jugar
        {
            //EH: Preguntar si realmente quiere abandonar el juego.
        }
        else
            //EH: Validar ciertas cosas, como dejar en blanco textbox, etc
            this->ui->screenManager->setCurrentIndex(index-1);
    }
}

