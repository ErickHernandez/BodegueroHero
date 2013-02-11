#ifndef GRAPHICSSCENEGAME_H
#define GRAPHICSSCENEGAME_H

#include <QGraphicsScene>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include "xmlpuzzletree.h"
#include "MyXmlHandler.h"

class graphicsscenegame: public QGraphicsScene
{
public:
    graphicsscenegame(QString puzzle, QObject *parent = 0);

private:
    void PintarPuzzle(XmlPuzzleTree *puzzleTree);
    XmlPuzzleTree *getXmlPuzzleTree(QString puzzle);
};

#endif // GRAPHICSSCENEGAME_H
