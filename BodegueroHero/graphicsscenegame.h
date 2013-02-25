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

private:
    int posActualGrua;
    int posPilaInicial, posPilaFinal;

    //ELEMTOS QUE TIENE EL GRAPHICS SCENE
    QGraphicsPixmapItem *cableDeLaGrua;
    QGraphicsPixmapItem *grua_izq;
    QGraphicsPixmapItem *grua_der;
    QVector<QVector<Caja *> > pilasDeCajas;
    Caja *cajitaDeLaGrua;

    //ELEMTOS PARA LA ANIMACION
    bool subirGrua;
    //int instruccionActual;
    QTimer *timer;
    stack<int> stackDeInstrucciones;

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
