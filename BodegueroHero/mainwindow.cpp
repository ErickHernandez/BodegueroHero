#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFile"
#include <QGridLayout>
#include <windialog.h>


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

    for(int i=0; i<28; i++)
        Action::Actions[i] = Action::Empty();


    laneBlocks = new DragWidget*[28];
    createConection();
    CrearTablas();
    cargarPerfil();
    ui->screenManager->setCurrentIndex(0);
    //MM: ESTE ES UN TEST PARA PINTAR EL PREVIEW
    //this->ui->graphicsView_Game->setScene(new graphicsscenegame("asdasd"));
    this->ui->graphicsView_Preview->setScene(new GraphicsScenePreview("asdasd"));


    //EH: Carga del toolbox
    QGridLayout *toolboxLayout = new QGridLayout(this);
    toolboxLayout->setObjectName("originLayout");
    toolboxLayout->addWidget(new DragWidget(true, -1, this->parentWidget()));
    this->ui->toolbox_frame->setLayout(toolboxLayout);
    //this->ui->screenManager->setCurrentIndex(7);// Por test nada mas

    initializeLanes();

    //WinDialog *w = new WinDialog(this->parentWidget());
    //w->show();

    //EH: Esto solo va a manejar visualmente quien es el current user.
    user = new QLabel(this->parentWidget());
    QFont font;
    font.setPointSize(20);
    font.setBold(true);
    user->setFont(font);
    this->ui->mainToolBar->addWidget(user);
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

   //EH:Set current User to UI
   QString a = "<font color=white>";
   QString b = "</font>";
   user->setText(a+txt+b);
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
    int index = this->ui->screenManager->currentIndex();
    //EH: si esta en la pantalla de juegos preguntarle si quiere abandonar el juego.
    if(index == 7)
        this->resetPuzzle();

    this->ui->screenManager->setCurrentIndex(0);
}

void MainWindow::on_actionBack_triggered()
{
    int index = this->ui->screenManager->currentIndex();

    if(index>0)
    {
        if(index == 4 || index == 3)
            this->ui->screenManager->setCurrentIndex(index-2);
        else if(index == 7)// si esta en la pantalla de jugar
        {
            //EH: Preguntar si realmente quiere abandonar el juego.
             this->ui->screenManager->setCurrentIndex(index-2);
             this->resetPuzzle();
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

            //EH:Set current User to UI
            QString a = "<font color=white>";
            QString b = "</font>";
            user->setText(a+nombre+b);
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
        ui->graphicsView_Preview->setScene(new GraphicsScenePreview(":puzzles/tutorial_1.txt"));
        ui->graphicsView_Game->setScene(new graphicsscenegame(":puzzles/tutorial_1.txt"));
    }else
    {
         ui->graphicsView_Preview->setScene(new GraphicsScenePreview(":puzzles/avanzado_1.txt"));
         ui->graphicsView_Game->setScene(new graphicsscenegame(":puzzles/avanzado_1.txt"));
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
        ui->graphicsView_Preview->setScene(new GraphicsScenePreview(":puzzles/tutorial_3.txt"));
        ui->graphicsView_Game->setScene(new graphicsscenegame(":puzzles/tutorial_3.txt"));
    }else
    {
         ui->graphicsView_Preview->setScene(new GraphicsScenePreview(":puzzles/avanzado_3.txt"));
         ui->graphicsView_Game->setScene(new graphicsscenegame(":puzzles/avanzado_3.txt"));
    }
}

void MainWindow::on_bnt_lvl5_clicked()
{
    ui->screenManager->setCurrentIndex(7);
    if(CurrentLevel==0)
    {
        ui->graphicsView_Preview->setScene(new GraphicsScenePreview(":puzzles/tutorial_5.txt"));
        ui->graphicsView_Game->setScene(new graphicsscenegame(":puzzles/tutorial_5.txt"));
    }else
    {
         ui->graphicsView_Preview->setScene(new GraphicsScenePreview(":puzzles/avanzado_5.txt"));
         ui->graphicsView_Game->setScene(new graphicsscenegame(":puzzles/avanzado_5.txt"));
    }
}

void MainWindow::on_bnt_lvl2_clicked()
{
    ui->screenManager->setCurrentIndex(7);
    if(CurrentLevel==0)
    {
        ui->graphicsView_Preview->setScene(new GraphicsScenePreview(":puzzles/tutorial_2.txt"));
        ui->graphicsView_Game->setScene(new graphicsscenegame(":puzzles/tutorial_2.txt"));
    }else
    {
         ui->graphicsView_Preview->setScene(new GraphicsScenePreview(":puzzles/avanzado_2.txt"));
         ui->graphicsView_Game->setScene(new graphicsscenegame(":puzzles/avanzado_2.txt"));
    }
}

void MainWindow::on_bnt_lvl4_clicked()
{
    ui->screenManager->setCurrentIndex(7);
    if(CurrentLevel==0)
    {
        ui->graphicsView_Preview->setScene(new GraphicsScenePreview(":puzzles/tutorial_4.txt"));
        ui->graphicsView_Game->setScene(new graphicsscenegame(":puzzles/tutorial_4.txt"));
    }else
    {
         ui->graphicsView_Preview->setScene(new GraphicsScenePreview(":puzzles/avanzado_4.txt"));
         ui->graphicsView_Game->setScene(new graphicsscenegame(":puzzles/avanzado_4.txt"));
    }
}

void MainWindow::on_bnt_lvl6_clicked()
{
    ui->screenManager->setCurrentIndex(7);
    if(CurrentLevel==0)
    {
        ui->graphicsView_Preview->setScene(new GraphicsScenePreview(":puzzles/tutorial_6.txt"));
        ui->graphicsView_Game->setScene(new graphicsscenegame(":puzzles/tutorial_6.txt"));
    }else
    {
         ui->graphicsView_Preview->setScene(new GraphicsScenePreview(":puzzles/avanzado_6.txt"));
         ui->graphicsView_Game->setScene(new graphicsscenegame(":puzzles/avanzado_6.txt"));
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
    this->ui->block0->setLayout(getNewLayout(0));
    this->ui->block1->setLayout(getNewLayout(1));
    this->ui->block2->setLayout(getNewLayout(2));
    this->ui->block3->setLayout(getNewLayout(3));
    this->ui->block4->setLayout(getNewLayout(4));
    this->ui->block5->setLayout(getNewLayout(5));
    this->ui->block6->setLayout(getNewLayout(6));
    this->ui->block7->setLayout(getNewLayout(7));
    this->ui->block8->setLayout(getNewLayout(8));
    this->ui->block9->setLayout(getNewLayout(9));
    this->ui->block10->setLayout(getNewLayout(10));
    this->ui->block11->setLayout(getNewLayout(11));
    this->ui->block12->setLayout(getNewLayout(12));
    this->ui->block13->setLayout(getNewLayout(13));
    this->ui->block14->setLayout(getNewLayout(14));
    this->ui->block15->setLayout(getNewLayout(15));
    this->ui->block16->setLayout(getNewLayout(16));
    this->ui->block17->setLayout(getNewLayout(17));
    this->ui->block18->setLayout(getNewLayout(18));
    this->ui->block19->setLayout(getNewLayout(19));
    this->ui->block20->setLayout(getNewLayout(20));
    this->ui->block21->setLayout(getNewLayout(21));
    this->ui->block22->setLayout(getNewLayout(22));
    this->ui->block23->setLayout(getNewLayout(23));
    this->ui->block24->setLayout(getNewLayout(24));
    this->ui->block25->setLayout(getNewLayout(25));
    this->ui->block26->setLayout(getNewLayout(26));
    this->ui->block27->setLayout(getNewLayout(27));
}

QGridLayout* MainWindow::getNewLayout(int id)
{
    QGridLayout *layout = new QGridLayout(this);
    DragWidget * dw = new DragWidget(false, id,this->parentWidget());
    layout->addWidget(dw);
    layout->setMargin(0);
    this->laneBlocks[id] = dw;//OK OK OK
    return layout;
}

void MainWindow::on_btn_PlayGame_clicked()
{
    graphicsscenegame *scene = (graphicsscenegame*) this->ui->graphicsView_Game->scene();
    scene->AnimarPuzzle();
}

void MainWindow::on_btn_StopGame_clicked()
{
    graphicsscenegame *scene = (graphicsscenegame*) this->ui->graphicsView_Game->scene();
    scene->DetenerPuzzle();
}

void MainWindow::on_btn_ConfigurarVelocidad_clicked()
{
    graphicsscenegame *scene = (graphicsscenegame*) this->ui->graphicsView_Game->scene();
    scene->CambiarVelocidad();
}

void MainWindow::resetPuzzle()
{
    for(int i=0; i<28; i++)
    {
        if(Action::Actions[i] != Action::Empty())
        {
            this->laneBlocks[i]->newIcon->close();
            this->laneBlocks[i]->action = Action::Empty();
        }

        Action::Actions[i] = Action::Empty();
    }
}

void MainWindow::on_btn_ClearGame_clicked()
{
    this->resetPuzzle();
}

void MainWindow::on_player1_clicked()
{

}
