#ifndef CAJA_H
#define CAJA_H
//INCLUDES AGREGADOS
#include <QGraphicsItem>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include "xmlpuzzletree.h"

class Caja: public QGraphicsPixmapItem
{
public:
    Caja(enum Colores color);
    enum Colores getColorCaja();

private:
    enum Colores colorCaja;
    QGraphicsPixmapItem *pixmapItem;
};

#endif // CAJA_H
