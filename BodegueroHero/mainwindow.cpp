#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFile"
#include <QGridLayout>

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
    ui->screenManager->setCurrentIndex(0);
    //MM: ESTE ES UN TEST PARA PINTAR EL PREVIEW
    //this->ui->graphicsView_Game->setScene(new graphicsscenegame("asdasd"));
    this->ui->graphicsView_Preview->setScene(new GraphicsScenePreview("asdasd"));


    //EH: Carga del toolbox
    QGridLayout *toolboxLayout = new QGridLayout(this);
    toolboxLayout->addWidget(new DragWidget(true,this->parentWidget()));
    this->ui->toolbox_frame->setLayout(toolboxLayout);
    this->ui->screenManager->setCurrentIndex(7);// Por test nada mas

    initializeLanes();

}

void MainWindow::cargarPerfil()
{

    ui->player1->setVisible(false);
    ui->player2->setVisible(false);
    ui->player3->setVisible(false);
    ui->player4->setVisible(false);
    ui->player5->setVisible(false);

    QList<QString> jugadores =  SelectAllJugadoresL();
    UsuariosDisponibles=5-jugadores.size();
    if(UsuariosDisponibles<0){UsuariosDisponibles=0;}
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
        ui->screenManager->setCurrentIndex(4);
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
            ui->screenManager->setCurrentIndex(4);
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
    this->CurrentLevel=0;
   PUNTOS=getScores(CurrentUser,CurrentLevel);//piden los scores del nivel tutorial con este usuario
    setHighScore(PUNTOS);
    ui->screenManager->setCurrentIndex(5);

}

void MainWindow::setHighScore(QList<score> PUNTOS)
{
    this->ui->lbl_level1->setText(0);
      this->ui->lbl_level2->setText(0);
       this->ui->lbl_level3->setText(0);
        this->ui->lbl_level4->setText(0);
         this->ui->lbl_level5->setText(0);
          this->ui->lbl_level6->setText(0);


    if(!PUNTOS.isEmpty()){//si la lista viene vacia
    for(int x=0;x<PUNTOS.size();x++)
     {
        QString highscore;
         switch(PUNTOS.at(x).nivel)
         {
         case 1:
         case 7:
             highscore="";
              highscore.setNum(PUNTOS.at(x).puntaje);
             this->ui->lbl_level1->setText(highscore);
         break;

         case 2:
         case 8:
             highscore="";
             highscore.setNum(PUNTOS.at(x).puntaje);
             this->ui->lbl_level2->setText(highscore);
         break;
         case 3:
         case 9:
             highscore="";
             highscore.setNum(PUNTOS.at(x).puntaje);
             this->ui->lbl_level3->setText(highscore);
         break;
         case 4:
         case 10:
             highscore="";
             highscore.setNum(PUNTOS.at(x).puntaje);
             this->ui->lbl_level4->setText(highscore);
         break;
         case 5:
         case 11:
             highscore="";
             highscore.setNum(PUNTOS.at(x).puntaje);
             this->ui->lbl_level5->setText(highscore);
         break;
         case 6:
         case 12:
             highscore="";
             highscore.setNum(PUNTOS.at(x).puntaje);
             this->ui->lbl_level6->setText(highscore);
         break;

         }

     }

 }
}

void MainWindow::on_btnAvanzado_clicked()
{

    this->CurrentLevel=6;
    PUNTOS=getScores(CurrentUser,CurrentLevel);//piden los scores del nivel tutorial con este usuario

    setHighScore(PUNTOS);
    ui->screenManager->setCurrentIndex(5);
}

void MainWindow::on_btn_lvl1_clicked()
{
    ui->screenManager->setCurrentIndex(7);
    if(CurrentLevel==0)
    {
        ui->graphicsView_Preview->setScene(new GraphicsScenePreview("tutorial_1"));
        ui->graphicsView_Game->setScene(new graphicsscenegame(":puzzles/tutorial_1.txt"));
    }else
    {
         ui->graphicsView_Preview->setScene(new GraphicsScenePreview("avanzado_1"));
    }
}

void MainWindow::on_btn_HighScore1_clicked()
{

QSqlQueryModel * model=SelectTop5(1+CurrentLevel);
model->setHeaderData(0, Qt::Horizontal, tr("Nombre"));
model->setHeaderData(1, Qt::Horizontal, tr("Puntaje"));
QTableView *view = new QTableView;
 view->setModel(model);
 view->show();
}

void MainWindow::on_btn_HighScore2_clicked()
{
    QSqlQueryModel * model=SelectTop5(2+CurrentLevel);
    model->setHeaderData(0, Qt::Horizontal, tr("Nombre"));
    model->setHeaderData(1, Qt::Horizontal, tr("Puntaje"));
    QTableView *view = new QTableView;
     view->setModel(model);
     view->show();

}


void MainWindow::on_btn_HighScore3_clicked()
{
    QSqlQueryModel * model=SelectTop5(3+CurrentLevel);
    model->setHeaderData(0, Qt::Horizontal, tr("Nombre"));
    model->setHeaderData(1, Qt::Horizontal, tr("Puntaje"));
    QTableView *view = new QTableView;
     view->setModel(model);
     view->show();
}

void MainWindow::on_btn_HighScore4_clicked()
{
    QSqlQueryModel * model=SelectTop5(4+CurrentLevel);
    model->setHeaderData(0, Qt::Horizontal, tr("Nombre"));
    model->setHeaderData(1, Qt::Horizontal, tr("Puntaje"));
    QTableView *view = new QTableView;
     view->setModel(model);
     view->show();
}

void MainWindow::on_btn_HighScore5_clicked()
{
    QSqlQueryModel * model=SelectTop5(5+CurrentLevel);
    model->setHeaderData(0, Qt::Horizontal, tr("Nombre"));
    model->setHeaderData(1, Qt::Horizontal, tr("Puntaje"));
    QTableView *view = new QTableView;
     view->setModel(model);
     view->show();
}


void MainWindow::on_btn_HighScore6_clicked()
{
    QSqlQueryModel * model=SelectTop5(6+CurrentLevel);
    model->setHeaderData(0, Qt::Horizontal, tr("Nombre"));
    model->setHeaderData(1, Qt::Horizontal, tr("Puntaje"));
    QTableView *view = new QTableView;
     view->setModel(model);
     view->show();
}

void MainWindow::on_bnt_lvl3_clicked()
{
    ui->screenManager->setCurrentIndex(7);
    if(CurrentLevel==0)
    {
        ui->graphicsView_Preview->setScene(new GraphicsScenePreview("tutorial_3"));
        ui->graphicsView_Game->setScene(new graphicsscenegame("tutorial_3"));
    }else
    {
         ui->graphicsView_Preview->setScene(new GraphicsScenePreview("avanzado_3"));
         ui->graphicsView_Game->setScene(new graphicsscenegame("avanzado_3"));
    }
}

void MainWindow::on_bnt_lvl5_clicked()
{
    ui->screenManager->setCurrentIndex(7);
    if(CurrentLevel==0)
    {
        ui->graphicsView_Preview->setScene(new GraphicsScenePreview("tutorial_5"));
        ui->graphicsView_Game->setScene(new graphicsscenegame("tutorial_5"));
    }else
    {
         ui->graphicsView_Preview->setScene(new GraphicsScenePreview("avanzado_5"));
         ui->graphicsView_Game->setScene(new graphicsscenegame("avanzado_5"));
    }
}

void MainWindow::on_bnt_lvl2_clicked()
{
    ui->screenManager->setCurrentIndex(7);
    if(CurrentLevel==0)
    {
        ui->graphicsView_Preview->setScene(new GraphicsScenePreview("tutorial_2"));
        ui->graphicsView_Game->setScene(new graphicsscenegame("tutorial_2"));
    }else
    {
         ui->graphicsView_Preview->setScene(new GraphicsScenePreview("avanzado_2"));
         ui->graphicsView_Game->setScene(new graphicsscenegame("avanzado_2"));
    }
}

void MainWindow::on_bnt_lvl4_clicked()
{
    ui->screenManager->setCurrentIndex(7);
    if(CurrentLevel==0)
    {
        ui->graphicsView_Preview->setScene(new GraphicsScenePreview("tutorial_4"));
        ui->graphicsView_Game->setScene(new graphicsscenegame("tutorial_4"));
    }else
    {
         ui->graphicsView_Preview->setScene(new GraphicsScenePreview("avanzado_4"));
         ui->graphicsView_Game->setScene(new graphicsscenegame("avanzado_4"));
    }
}

void MainWindow::on_bnt_lvl6_clicked()
{
    ui->screenManager->setCurrentIndex(7);
    if(CurrentLevel==0)
    {
        ui->graphicsView_Preview->setScene(new GraphicsScenePreview("tutorial_6"));
        ui->graphicsView_Game->setScene(new graphicsscenegame("tutorial_6"));
    }else
    {
         ui->graphicsView_Preview->setScene(new GraphicsScenePreview("avanzado_6"));
         ui->graphicsView_Game->setScene(new graphicsscenegame("avanzado_6"));
    }
}

void MainWindow::initializeLanes()
{

//    for(int i=0; i<8; i++)
//    {
//        //EH: Carga de los lanes
//        DragWidget *dw = new DragWidget(false, parentWidget());
//        dw->setFrameRect(QRect(0,0,2,2));
//        lanesLayout->addWidget(dw);

//        //this->ui->lanes_frame->layout()->addWidget(dw);
//        lanesLayout->addWidget(dw);

//        this->laneBlocks.append(dw);
//        this->ui->lanes_frame->setLayout(lanesLayout);
//    }
    this->ui->block0->setLayout(getNewLayout());
    this->ui->block1->setLayout(getNewLayout());
    this->ui->block2->setLayout(getNewLayout());
    this->ui->block3->setLayout(getNewLayout());
    this->ui->block4->setLayout(getNewLayout());
    this->ui->block5->setLayout(getNewLayout());
    this->ui->block6->setLayout(getNewLayout());
    this->ui->block7->setLayout(getNewLayout());
    this->ui->block8->setLayout(getNewLayout());
    this->ui->block9->setLayout(getNewLayout());
    this->ui->block10->setLayout(getNewLayout());
    this->ui->block11->setLayout(getNewLayout());
    this->ui->block12->setLayout(getNewLayout());
    this->ui->block13->setLayout(getNewLayout());
    this->ui->block14->setLayout(getNewLayout());
    this->ui->block15->setLayout(getNewLayout());
    this->ui->block16->setLayout(getNewLayout());
    this->ui->block17->setLayout(getNewLayout());
    this->ui->block18->setLayout(getNewLayout());
    this->ui->block19->setLayout(getNewLayout());
    this->ui->block20->setLayout(getNewLayout());
    this->ui->block21->setLayout(getNewLayout());
    this->ui->block22->setLayout(getNewLayout());
    this->ui->block23->setLayout(getNewLayout());
    this->ui->block24->setLayout(getNewLayout());
    this->ui->block25->setLayout(getNewLayout());
    this->ui->block26->setLayout(getNewLayout());
    this->ui->block27->setLayout(getNewLayout());
}

QGridLayout* MainWindow::getNewLayout()
{
    QGridLayout *layout = new QGridLayout(this);
    DragWidget * dw = new DragWidget(false, this->parentWidget());
    layout->addWidget(dw);
    layout->setMargin(0);
    return layout;
}

