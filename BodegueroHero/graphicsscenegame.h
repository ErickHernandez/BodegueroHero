#ifndef GRAPHICSSCENEGAME_H
#define GRAPHICSSCENEGAME_H

#include <QGraphicsScene>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QVector>
#include "xmlpuzzletree.h"
#include "MyXmlHandler.h"
#include "caja.h"
//#include "grua.h"
#include <QGraphicsItemAnimation>
#include <QTimeLine>
#include <QTimer>
#include <QThread>
#include "action.h"
#include <math.h>
#include <stack>
#include <QMessageBox>
#include <mainwindow.h>
using namespace std;

class graphicsscenegame: public QGraphicsScene
{
    Q_OBJECT
public:
    graphicsscenegame(QString puzzle, QObject *parent = 0);
    void AnimarPuzzle();
    void DetenerPuzzle();
    void CambiarVelocidad();
    void ResetearPuzzle();
    void EjecutarSiguienteInstruccion();
    int getInstruccionActual();

private:
    int posActualGrua;
    int posPilaInicial, posPilaFinal;
    bool gruaAbierta;
    int anguloActualGrua;
    bool stepByStep;
    int velocidadActual;

    //ELEMTOS QUE TIENE EL GRAPHICS SCENE
    QGraphicsPixmapItem *cableDeLaGrua;
    QGraphicsPixmapItem *grua_izq;
    QGraphicsPixmapItem *grua_der;
    QVector<QVector<Caja *> > pilasDeCajas;
    Caja *cajitaDeLaGrua;

    //ELEMENTOS PARA LA ANIMACION
    bool subirGrua;
    //int instruccionActual;
    QTimer *timer;
    QTimer *timer_nubes;
    stack<int> stackDeInstrucciones;


    //FUNCIONES GENERALES PARA HACER COSAS GENERALES
    void SiguienteInstruccion();
    bool PuzzleResuelto();
    int getCantidadInstruccionesUtilizadas();
    int instruccionActual;
    QGraphicsPixmapItem *cable_CentroDeMando_izq;
    QGraphicsPixmapItem *cable_CentroDeMando_der;
    QGraphicsPixmapItem *nube1, *nube2, *nube3, *nube4;
    QGraphicsPixmapItem *nube1_2, *nube2_2, *nube3_2, *nube4_2;


    //LOS ARBOLES QUE DEVOLVIO EL PARSER XML
    XmlPuzzleTree *xmlTreeInicial;
    XmlPuzzleTree *xmlTreeFinal;
    void setXmlPuzzleTrees(QString puzzle);

    //MM: FUNCIONES DE PINTADO
    void ReiniciarPuzzle();
    void PintarBackgroud();
    void PintarPuzzle(XmlPuzzleTree *puzzleTree);
    void PintarBasesDeLasPilas(int posInicial, int posFinal);


private slots:
    void animar_v2();
    void terminoAnimacion();
    void animar_Nubes();

signals:
    void PuzzleFinalizado(const int &);
    void Error_FueraDeRango();
    void Error_CantidadMaximaCajas();
    void CambioDeInstruccion();

};


#endif // GRAPHICSSCENEGAME_H
