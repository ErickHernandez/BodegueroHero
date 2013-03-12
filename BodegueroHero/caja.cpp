#include "caja.h"

Caja::Caja(XmlPuzzleTree::Colores color): QGraphicsPixmapItem()
{
    QString colorCajita = "";

    if(color == XmlPuzzleTree::AZUL)
        colorCajita = ":images/blue_box_game.png";
    else if(color == XmlPuzzleTree::VERDE)
        colorCajita = ":images/green_box_game.png";
    else if(color == XmlPuzzleTree::NARANJA)
        colorCajita = ":images/orange_box_game.png";
    else if(color == XmlPuzzleTree::ROJO)
        colorCajita = ":images/red_box_game.png";
    else if(color == XmlPuzzleTree::CAFE)
        colorCajita = ":images/coffee_box_game.png";
    else if(color == XmlPuzzleTree::AMARILLO)
        colorCajita = ":images/yellow_box_game.png";

    QPixmap *pixmap = new QPixmap(colorCajita);
    this->setPixmap(*pixmap);
    this->colorCaja = color;

    QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect();
    this->setGraphicsEffect(effect);
    effect->setOffset(2,2);
    this->setZValue(10);
}

XmlPuzzleTree::Colores Caja::getColorCaja()
{
    return this->colorCaja;
}
