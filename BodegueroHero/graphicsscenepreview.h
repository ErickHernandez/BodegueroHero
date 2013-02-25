#ifndef GRAPHICSSCENEPREVIEW_H
#define GRAPHICSSCENEPREVIEW_H

//MM: INCLUDES AGREGADOS
#include <QGraphicsScene>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include "xmlpuzzletree.h"
#include "MyXmlHandler.h"
//MM TODO: AGREGAR LOS ITEMS DE CAJA, ETC.


class GraphicsScenePreview: public QGraphicsScene
{
public:
    GraphicsScenePreview(QString puzzle, QObject *parent = 0);

private:
    void PintarPuzzle(XmlPuzzleTree *puzzleTree);
    void PintarBasesDeLasPilas(int posInicial, int posFinal);
    XmlPuzzleTree *getXmlPuzzleTree(QString puzzle);

};

#endif // GRAPHICSSCENEPREVIEW_H
