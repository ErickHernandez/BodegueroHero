#include "caja.h"

Caja::Caja(enum Colores color): QGraphicsPixmapItem()
{
    QString colorCajita = "";

    if(color == AZUL)
        colorCajita = ":images/blue_box_game.png";
    else if(color == VERDE)
        colorCajita = ":images/green_box_game.png";
    else if(color == NARANJA)
        colorCajita = ":images/orange_box_game.png";
    else if(color == ROJO)
        colorCajita = ":images/red_box_game.png";
    else if(color == CAFE)
        colorCajita = ":images/coffee_box_game.png";
    else if(color == AMARILLO)
        colorCajita = ":images/yellow_box_game.png";

    QPixmap *pixmap = new QPixmap(colorCajita);
    this->setPixmap(*pixmap);

}

enum Colores Caja::getColorCaja()
{
    return this->colorCaja;
}
