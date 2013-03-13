#ifndef CAJA_H
#define CAJA_H
//INCLUDES AGREGADOS
#include <QGraphicsItem>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include "xmlpuzzletree.h"
#include <QGraphicsDropShadowEffect>

class Caja: public QGraphicsPixmapItem
{
public:
    Caja(XmlPuzzleTree::Colores color);
    XmlPuzzleTree::Colores getColorCaja();

private:
    XmlPuzzleTree::Colores colorCaja;
    QGraphicsPixmapItem *pixmapItem;
};

#endif // CAJA_H
