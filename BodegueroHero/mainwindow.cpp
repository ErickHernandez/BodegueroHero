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


     QList<QString> jugadores =  SelectAllJugadoresL();
     UsuariosDisponibles=5-jugadores.size();
     if(UsuariosDisponibles<0){UsuariosDisponibles=0;}
     QSignalMapper *signalMapper = new QSignalMapper(this);
     if(jugadores.size()>0){

   }
     if (jugadores.size()>1){

   }
     if (jugadores.size()>2){

      }

     if (jugadores.size()>3){

   }
     if(jugadores.size()>4){


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
   ui->screenManager->setCurrentIndex(4);
}

void MainWindow::on_pushButton_clicked()
{


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


void MainWindow::on_btn_CrearPerfil_clicked()
{
    cargarPerfil();
    if(UsuariosDisponibles>0){
        QString nombre =ui->NewPlayer->toPlainText();
        CrearPerfil(nombre);
        ui->NewPlayer->clear();
        CurrentUser=nombre;
        cargarPerfil();
    }else
    {
         QMessageBox msgBox;
          msgBox.setText("Si continua borrará el jugador mas antiguo en este menu \n ¿Desea Continuar?");
          QPushButton *connectButton = msgBox.addButton(tr("Si"), QMessageBox::ActionRole);
          QPushButton *abortButton = msgBox.addButton(QMessageBox::No);
          msgBox.exec();

        if (msgBox.clickedButton() == connectButton) {
            QString nombre =ui->NewPlayer->toPlainText();
            CrearPerfil(nombre);
            ui->NewPlayer->clear();
            CurrentUser=nombre;
            cargarPerfil();
            ui->screenManager->setCurrentIndex(3);
        } else if (msgBox.clickedButton() == abortButton) {
          ui->screenManager->setCurrentIndex(2);
        }
    }
}


void MainWindow::on_label_26_linkActivated(QString link)
{

}

void MainWindow::on_btn_ir_CrearPerfil_clicked()
{
    ui->screenManager->setCurrentIndex(3);
}

void MainWindow::on_btnTutorial_clicked()
{
     this->CurrentLevel="Tutorial";
    ui->screenManager->setCurrentIndex(4);

}


void MainWindow::on_btnAvanzado_clicked()
{
    this->CurrentLevel="Avanzado";
    ui->screenManager->setCurrentIndex(4);

}
