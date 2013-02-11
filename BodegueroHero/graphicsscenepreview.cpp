#include "graphicsscenepreview.h"

#define Pos_X_Inicial  25
#define Pos_Y_Inicial  160.6 - 6
#define Size_Caja      18
//MM: NOTES TO SELF
//21.4 tamanio del suelo
//diferencia 160.6

GraphicsScenePreview::GraphicsScenePreview(QString puzzle, QObject *parent): QGraphicsScene(parent)
{
    this->setSceneRect(0,0,280,200);

    QPixmap *pixmap = new QPixmap(":images/background_preview.png");
    QGraphicsPixmapItem *background = new QGraphicsPixmapItem();
    background->setPixmap(*pixmap);
    //background->setPos(0,0);
    background->setZValue(-20);
    this->addItem(background);


    XmlPuzzleTree *tree = this->getXmlPuzzleTree(puzzle);
    this->PintarPuzzle(tree);
}

XmlPuzzleTree* GraphicsScenePreview::getXmlPuzzleTree(QString puzzle)
{
    //INTANCIA DEL PARSER
    QXmlSimpleReader* xmlReader = new QXmlSimpleReader();


    //SE DEFINE EL FILE
    QFile *file = new QFile(puzzle);
    //QXmlInputSource *source = new QXmlInputSource(file);

    //SE LE SETEA UN HANDLER
    MyXmlHandler *handler = new MyXmlHandler();
    xmlReader->setContentHandler(handler);
    //xmlReader->setContentHandler(new QXmlDefaultHandler());

    bool ok = xmlReader->parse(file);
    XmlPuzzleTree *tree = handler->getArbolEstadoFinal();

    file->close();

    return handler->getArbolEstadoFinal();
}

void GraphicsScenePreview::PintarPuzzle(XmlPuzzleTree *puzzleTree)
{
    int posPilaInicial = puzzleTree->getIdStackInicial();
    int posPilaFinal   = puzzleTree->getIdStackFinal();

    //MM: PINTAR LAS BASES DE LAS PILAS
    this->PintarBasesDeLasPilas(posPilaInicial, posPilaFinal);



    for(int i=posPilaInicial; i<=posPilaFinal; i++)
    {
        QVector<enum Colores> colores = puzzleTree->getPilaDeCajitas(i);
        for(int j=0; j<colores.size(); j++)
        {
            int posX = Pos_X_Inicial + (1.7 * Size_Caja * i);
            int posY = Pos_Y_Inicial - (Size_Caja * j);
//            int posX = Pos_X_Inicial;
//            int posY = Pos_Y_Inicial;


            QString colorCajita = "";

            if(colores[j] == AZUL)
                colorCajita = ":images/blue_box_preview.png";
            else if(colores[j] == VERDE)
                colorCajita = ":images/green_box_preview.png";
            else if(colores[j] == NARANJA)
                colorCajita = ":images/orange_box_preview.png";
            else if(colores[j] == ROJO)
                colorCajita = ":images/red_box_preview.png";
            else if(colores[j] == CAFE)
                colorCajita = ":images/coffee_box_preview.png";
            else if(colores[j] == AMARILLO)
                colorCajita = ":images/yellow_box_preview.png";


            QPixmap *pixmap = new QPixmap(colorCajita);
            QGraphicsPixmapItem *cajita = new QGraphicsPixmapItem();
            cajita->setPixmap(*pixmap);
            cajita->setPos(posX , posY);
            //cajita->setZValue(-20);
            this->addItem(cajita);
        }
    }
}

void GraphicsScenePreview::PintarBasesDeLasPilas(int posInicial, int posFinal)
{
    for(int i=posInicial; i<=posFinal; i++)
    {
        int posX = Pos_X_Inicial + (1.7 * Size_Caja * i) - 3;
        int posY = 172;

        QPixmap *pixmap = new QPixmap(":images/base_pila_preview.png");
        QGraphicsPixmapItem *base_pila = new QGraphicsPixmapItem();
        base_pila->setPixmap(*pixmap);
        base_pila->setPos(posX,posY);
        this->addItem(base_pila);

    }
}
