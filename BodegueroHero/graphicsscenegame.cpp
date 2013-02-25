#include "graphicsscenegame.h"

#define Pos_X_Inicial  180
#define Pos_Y_Inicial  324  - 12
#define Size_Caja      36
#define Pos_Grua_Inicial 167.5

graphicsscenegame::graphicsscenegame(QString puzzle, QObject *parent): QGraphicsScene(parent)
{
    QPixmap *pixmap = new QPixmap(":images/background_game.png");
    QGraphicsPixmapItem *background = new QGraphicsPixmapItem();
    background->setPixmap(*pixmap);
    this->addItem(background);

    pixmap = new QPixmap(":images/Centro de Mando.png");
    background = new QGraphicsPixmapItem();
    background->setPixmap(*pixmap);
    background->setPos(10, 285);
    this->addItem(background);



    pixmap = new QPixmap(":images/Cables_game.png");
    background = new QGraphicsPixmapItem();
    background->setPixmap(*pixmap);
    background->setPos(20, 0);
    this->addItem(background);

    pixmap = new QPixmap(":images/Cables_game.png");
    background = new QGraphicsPixmapItem();
    background->setPixmap(*pixmap);
    background->setPos(38, 0);
    this->addItem(background);

    XmlPuzzleTree *tree = this->getXmlPuzzleTree(puzzle);
    this->PintarPuzzle(tree);

}

XmlPuzzleTree* graphicsscenegame::getXmlPuzzleTree(QString puzzle)
{
    //INTANCIA DEL PARSER
    QXmlSimpleReader* xmlReader = new QXmlSimpleReader();


    //SE DEFINE EL FILE
    QFile *file = new QFile(puzzle);

    //SE LE SETEA UN HANDLER
    MyXmlHandler *handler = new MyXmlHandler();
    xmlReader->setContentHandler(handler);

    bool ok = xmlReader->parse(file);
    XmlPuzzleTree *tree = handler->getArbolEstadoInicial();

    file->close();

    return handler->getArbolEstadoInicial();
}

void graphicsscenegame::PintarPuzzle(XmlPuzzleTree *puzzleTree)
{
    int posPilaInicial = puzzleTree->getIdStackInicial();
    int posPilaFinal   = puzzleTree->getIdStackFinal();
    int posTenazaInicial = puzzleTree->getPosicionInicialGrua();

    this->PintarBasesDeLasPilas(posPilaInicial, posPilaFinal);

    for(int i=posPilaInicial; i<=posPilaFinal; i++)
    {
        QVector<enum Colores> colores = puzzleTree->getPilaDeCajitas(i);
        for(int j=0; j<colores.size(); j++)
        {
            int posX = Pos_X_Inicial + Size_Caja * i + 20*i;
            int posY = Pos_Y_Inicial - (Size_Caja * j) ;



            QString colorCajita = "";

            if(colores[j] == AZUL)
                colorCajita = ":images/blue_box_game.png";
            else if(colores[j] == VERDE)
                colorCajita = ":images/green_box_game.png";
            else if(colores[j] == NARANJA)
                colorCajita = ":images/orange_box_game.png";
            else if(colores[j] == ROJO)
                colorCajita = ":images/red_box_game.png";
            else if(colores[j] == CAFE)
                colorCajita = ":images/coffee_box_game.png";
            else if(colores[j] == AMARILLO)
                colorCajita = ":images/yellow_box_game.png";


            QPixmap *pixmap = new QPixmap(colorCajita);
            QGraphicsPixmapItem *cajita = new QGraphicsPixmapItem();
            cajita->setPixmap(*pixmap);
            cajita->setPos(posX , posY);
            this->addItem(cajita);

        }
    }

    QPixmap *pixmap = new QPixmap(":images/Tenaza_game.png");
    QGraphicsPixmapItem *grua = new QGraphicsPixmapItem();
    grua->setPixmap(*pixmap);
    grua->setPos(Pos_Grua_Inicial + 56 * puzzleTree->getPosicionInicialGrua(),15);
    this->addItem(grua);

    pixmap = new QPixmap(":images/Cables_small_game.png");
    grua = new QGraphicsPixmapItem();
    grua->setPixmap(*pixmap);
    grua->setPos(Pos_Grua_Inicial +24 + 56 * puzzleTree->getPosicionInicialGrua(), 0);
    this->addItem(grua);

}

void graphicsscenegame::PintarBasesDeLasPilas(int posInicial, int posFinal)
{
    for(int i=posInicial; i<=posFinal; i++)
    {
        int posX = (Pos_X_Inicial + Size_Caja * i + 20*i) - 5;
        int posY = 357.5 - 12 ;

        QPixmap *pixmap = new QPixmap(":images/base_pila_game.png");
        QGraphicsPixmapItem *base_pila = new QGraphicsPixmapItem();
        base_pila->setPixmap(*pixmap);
        base_pila->setPos(posX,posY);
        this->addItem(base_pila);

    }
}
