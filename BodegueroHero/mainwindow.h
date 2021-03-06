#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <dbConnection.h>
#include "QSignalMapper"
#include "QGridLayout"
#include <QMainWindow>
#include <QTableView>
//MM: AGREGADO INCLUDE
#include "graphicsscenepreview.h"
#include "graphicsscenegame.h"
#include "dragwidget.h"


namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    int UsuariosDisponibles;
    QString temp;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void cargarPerfil();
    QString CurrentUser;    
    int SelectLevel;
    void winer(int puntos);
    // QString CurrentLevel;

private:
    Ui::MainWindow *ui;
    int CurrentLevel;
    int currentAction;
    int currentSpeed;
    bool gameRunning;

    void callHS();
    QList<score> PUNTOS;
    QGridLayout* getNewLayout(int id);
    DragWidget** laneBlocks;
    QFrame** frames;
    QLabel *user;
    void setHighScore(QList<score> puntos);
    void initializeLanes();        
    void resetPuzzle();
    void lockLanes();
    void unlockLanes();    
 private slots:
    void on_btn_StepByStep_clicked();
    void on_player1_clicked();
    void on_btn_ClearGame_clicked();
    void on_btn_ConfigurarVelocidad_clicked();
    void on_btn_StopGame_clicked();
    void on_btn_PlayGame_clicked();
    void on_bnt_lvl6_clicked();
    void on_bnt_lvl4_clicked();
    void on_bnt_lvl2_clicked();
    void on_bnt_lvl5_clicked();
    void on_bnt_lvl3_clicked();
    void on_btn_HighScore6_clicked();
    void on_btn_HighScore5_clicked();
    void on_btn_HighScore4_clicked();
    void on_btn_HighScore3_clicked();
    void on_btn_HighScore2_clicked();
    void on_btn_HighScore1_clicked();
    void on_btn_lvl1_clicked();
    void on_btnAvanzado_clicked();
    void on_btnTutorial_clicked();
    void on_btn_ir_CrearPerfil_clicked();
    void on_label_26_linkActivated(QString link);
    void on_btn_CrearPerfil_clicked();
    void on_actionBack_triggered();
    void on_actionHome_triggered();
    void on_cmdStart_clicked();
    void on_btJugar_clicked();
    void on_btCrear_clicked();
    void on_btSeleccionar_clicked();
    void on_pushButton_clicked();
    void recibir(const QString &);
    void respuesta(const QString &);    
    void resetInstruction(int);
public slots:
    void findeljuego(const int &);
    void muxascajas();
    void salido();
    void DibujarInstruccionActual();

signals:
void escribir(const QString &);

};

#endif // MAINWINDOW_H
