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
#include <windialog.h>
#include <mainwindow.h>

using namespace std;

class graphicsscenegame: public QGraphicsScene
{
    Q_OBJECT
public:
    graphicsscenegame(QString name, int level,QString puzzle, QObject *parent = 0);
    QString player;
    int level;
    void AnimarPuzzle();
    void DetenerPuzzle();
    void CambiarVelocidad();
    void ResetearPuzzle();

private:
    int posActualGrua;
    int posPilaInicial, posPilaFinal;
    bool gruaAbierta;
    int anguloActualGrua;

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
    stack<int> stackDeInstrucciones;


    //FUNCIONES GENERALES PARA HACER COSAS GENERALES
    void SiguienteInstruccion();
    bool PuzzleResuelto();
    int getCantidadInstruccionesUtilizadas();


    //LOS ARBOLES QUE DEVOLVIO EL PARSER XML
    XmlPuzzleTree *xmlTreeInicial;
    XmlPuzzleTree *xmlTreeFinal;
    void setXmlPuzzleTrees(QString puzzle);

    //MM: FUNCIONES DE PINTADO
    void ReiniciarPuzzle();
    void PintarPuzzle(XmlPuzzleTree *puzzleTree);
    void PintarBasesDeLasPilas(int posInicial, int posFinal);


private slots:
    void animar_v2();
    void terminoAnimacion();
};


#endif // GRAPHICSSCENEGAME_H
