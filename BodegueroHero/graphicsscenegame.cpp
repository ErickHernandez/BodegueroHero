#include "graphicsscenegame.h"

#define Pos_X_Inicial  180
#define Pos_Y_Inicial  324  - 12
#define Size_Caja      36
#define Pos_Grua_Inicial 167 + 26
#define Velocidad_Normal    10
#define Velocidad_Rapida    4

graphicsscenegame::graphicsscenegame(QString puzzle, QObject *parent): QGraphicsScene(parent)
{
    //LA GRUA NO TIENE UN CAJA INCIALMENTE
    this->cajitaDeLaGrua = 0;
//    this->instruccionActual = 0;

    this->setXmlPuzzleTrees(puzzle);
    this->PintarPuzzle(this->xmlTreeInicial);

//    this->thread = new QThread;
//    connect(thread,SIGNAL(started()),this,SLOT(animar_v2()));

    this->timer = new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(animar_v2()));

}

void graphicsscenegame::setXmlPuzzleTrees(QString puzzle)
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

    this->xmlTreeInicial = handler->getArbolEstadoInicial();
    this->xmlTreeFinal = handler->getArbolEstadoFinal();
}

void graphicsscenegame::PintarPuzzle(XmlPuzzleTree *puzzleTree)
{
    for(int i=0; i<8; i++)
    {
        QVector<Caja *> temp;
        this->pilasDeCajas.push_back(temp);
    }


    //MM: MOVI LAS OPCIONES DE DIBUJADO QUE HABIAN EN EL CONSTRUCTOR HACIA ESTA FUNCION

    //MM: IMAGENES DEL GRAPHICS SCENE QUE SE USAN PARA ARMAR EL BACKGROUND
    this->setSceneRect(0,0,700,400);

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

            Caja *cajita = new Caja(colores[j]);
            cajita->setPos(posX , posY);
            this->addItem(cajita);

            this->pilasDeCajas[i].push_back(cajita);
        }
    }

    int posInicialGrua = puzzleTree->getPosicionInicialGrua();
    this->posActualGrua = posInicialGrua;

    QPixmap *cable_grua = new QPixmap(":images/Cables.png");
    this->cableDeLaGrua = new QGraphicsPixmapItem();
    this->cableDeLaGrua->setPixmap(*cable_grua);//Size_Caja * posInicialGrua + 20*posInicialGrua
    this->cableDeLaGrua->setPos(Pos_Grua_Inicial + (posActualGrua*(Size_Caja + 20)) , -453 + 50);
    this->addItem(this->cableDeLaGrua);

    QPixmap *grua_izq = new QPixmap(":images/grua_izq.png");
    this->grua_izq = new QGraphicsPixmapItem();
    this->grua_izq->setPixmap(*grua_izq);
    this->grua_izq->setPos(Pos_Grua_Inicial + (posActualGrua*(Size_Caja + 20)) - 13 - 14, 50);
    this->addItem(this->grua_izq);

    QPixmap *grua_der = new QPixmap(":images/grua_der.png");
    this->grua_der = new QGraphicsPixmapItem();
    this->grua_der->setPixmap(*grua_der);
    this->grua_der->setPos(Pos_Grua_Inicial + (posActualGrua*(Size_Caja + 20)) - 13 + 14, 50);
    this->addItem(this->grua_der);

    //PARA QUE LA ROTACION SE MIRE SMOOTH
    this->grua_izq->setTransformationMode(Qt::SmoothTransformation);
    this->grua_der->setTransformationMode(Qt::SmoothTransformation);

    this->grua_izq->setTransformOriginPoint(this->grua_izq->boundingRect().center());
    this->grua_der->setTransformOriginPoint(this->grua_der->boundingRect().center());

//    this->grua_izq->rotate(30);
//    this->grua_der->rotate(-30);

//    //TIMELINE DE LA ANIMACION
//    QTimeLine *timeline = new QTimeLine(2000);

//    //ANIMACION PARA LA PARTE IZQUIERDA DE LA GRUA
//    QGraphicsItemAnimation *animation_izq = new QGraphicsItemAnimation;
//    animation_izq->setItem(this->grua_izq);
//    animation_izq->setTimeLine(timeline);
//    animation_izq->setRotationAt(0.5, 30);

//    //ANIMACION PARA LA PARTE DERECAH DE LA GRUA
//    QGraphicsItemAnimation *animation_der = new QGraphicsItemAnimation;
//    animation_der->setItem(this->grua_der);
//    animation_der->setTimeLine(timeline);
//    animation_der->setRotationAt(0.5, -30);


//    timeline->start();


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

void graphicsscenegame::ResetearPuzzle()
{
    if(this->timer->isActive())
        this->timer->stop();

    this->ReiniciarPuzzle();
}

void graphicsscenegame::ReiniciarPuzzle()
{
    this->clear();
    this->pilasDeCajas.clear();
    this->PintarPuzzle(this->xmlTreeInicial);
}

void graphicsscenegame::DetenerPuzzle()
{
    if(timer->isActive())
    {
        this->timer->stop();
        this->ReiniciarPuzzle();
    }
}


void graphicsscenegame::AnimarPuzzle()
{

    if(this->timer->isActive())
        this->timer->stop();



    this->subirGrua = false;
    this->ReiniciarPuzzle();
//    this->instruccionActual = 0;
    this->stackDeInstrucciones.push(0);
    this->cajitaDeLaGrua = 0;
    this->timer->start(Velocidad_Normal);

}

void graphicsscenegame::animar_v2()
{
    if(this->stackDeInstrucciones.empty())
        this->timer->stop();

    int instruccionActual = this->stackDeInstrucciones.top();

    //INSTRUCCION VACIA
    if(Action::Actions[instruccionActual] == 0)
    {
        if((instruccionActual+1) % 8 == 0 || instruccionActual == 27)
            this->timer->stop();
        else
        {
            instruccionActual++;
            this->stackDeInstrucciones.pop();
            this->stackDeInstrucciones.push(instruccionActual);
        }
        return;
    }

    //DOWN
    if(Action::Actions[instruccionActual] == 1)
    {
        //SI LA GRUA NO TIENE CAJA, Y ESTA EN SU PUNTO MAS ALTO, QUE HAGA LA ANIMACION
//        if(this->cableDeLaGrua->y()== (-453 + 50) && this->cajitaDeLaGrua==0)
//        {
//            this->grua_izq->setTransformOriginPoint(this->grua_izq->boundingRect().center());
//            this->grua_der->setTransformOriginPoint(this->grua_der->boundingRect().center());

//            //TIMELINE DE LA ANIMACION
//            QTimeLine *timeline = new QTimeLine(2000);

//            //ANIMACION PARA LA PARTE IZQUIERDA DE LA GRUA
//            QGraphicsItemAnimation *animation_izq = new QGraphicsItemAnimation;
//            animation_izq->setItem(this->grua_izq);
//            animation_izq->setTimeLine(timeline);
//            animation_izq->setRotationAt(0.5, 30);

//            //ANIMACION PARA LA PARTE DERECAH DE LA GRUA
//            QGraphicsItemAnimation *animation_der = new QGraphicsItemAnimation;
//            animation_der->setItem(this->grua_der);
//            animation_der->setTimeLine(timeline);
//            animation_der->setRotationAt(0.5, -30);


//            timeline->start();
//        }


        int posY_grua = 0;

        //A LA DIRRECION BASE LE SUMA UN SIZE DE CAJA AL FINAL, PORQUE LA GRUA SE PONE POR ENCIMA
        if(this->cajitaDeLaGrua != 0)
            posY_grua = -453 + Size_Caja*6 + 74 -(Size_Caja*pilasDeCajas[posActualGrua].size());
        else
            posY_grua = -453 + Size_Caja*6 + 74 -(Size_Caja*pilasDeCajas[posActualGrua].size()) + Size_Caja;
        //EN CASO DE NO HABER CAJAS EN LA PILA, Y SI LA GRUA NO TIENE UNA CAJA, SE VA HASTA ABAJO xD
        if(pilasDeCajas[posActualGrua].size() == 0 && this->cajitaDeLaGrua == 0)
            posY_grua = -453 + Size_Caja*6 + 74 ;



        int posY_gruaActual = this->cableDeLaGrua->y();

        int x = 10;
        int suma = x + 2;


        if(posY_grua != this->cableDeLaGrua->y() && !subirGrua)
        {
            this->cableDeLaGrua->setPos(this->cableDeLaGrua->x(), this->cableDeLaGrua->y()+1);
            this->grua_izq->setPos(this->grua_izq->x(), this->grua_izq->y()+1);
            this->grua_der->setPos(this->grua_der->x(), this->grua_der->y()+1);
            if(this->cajitaDeLaGrua != 0)
                this->cajitaDeLaGrua->setY(this->cajitaDeLaGrua->y() + 1);
        }
        else
        {
            this->subirGrua = true;

            //SI LA GRUA ESTA LLEGO A SU PUNTO MAS BAJO, ENCONTRE UNA CAJA Y LA GRUA NO TIENE UNA, LA LEVANTO
            if(this->cableDeLaGrua->y() == posY_grua &&
                    this->cajitaDeLaGrua == 0 && this->pilasDeCajas[posActualGrua].size()!=0)
            {
                 this->cajitaDeLaGrua = pilasDeCajas[posActualGrua].last();
                 this->pilasDeCajas[posActualGrua].pop_back();
            }
            //SI LA GRUA ESTA LLEGO A SU PUNTO MAS BAJO Y LA GRUA TIENE UNA CAJA, LA DEJO EN LA PILA
            else if(this->cableDeLaGrua->y() == posY_grua && this->cajitaDeLaGrua != 0)
            {
                 this->pilasDeCajas[posActualGrua].push_back(this->cajitaDeLaGrua);
                 this->cajitaDeLaGrua = 0;
            }

            this->cableDeLaGrua->setY(this->cableDeLaGrua->y()-1);
            this->grua_izq->setY(this->grua_izq->y()-1);
            this->grua_der->setY(this->grua_der->y()-1);
            if(this->cajitaDeLaGrua != 0)
                this->cajitaDeLaGrua->setY(this->cajitaDeLaGrua->y()-1);



            //#####################################################################################################
            //#                       TODO: MOSTRAR ERROR AL PONER MAS DE SEIS CAJAS                              #
            //#####################################################################################################



            //SI LLEGUE A LA PARTE MAS ALTA, SEGUIR CON LA OTRA INSTRUCCION
            if(this->cableDeLaGrua->y() == -453 + 50)
            {
                if((instruccionActual+1) % 8 == 0 || instruccionActual == 27)
                    this->stackDeInstrucciones.pop();
                else
                {
                    this->subirGrua = false;
                    instruccionActual++;
                    this->stackDeInstrucciones.pop();
                    this->stackDeInstrucciones.push(instruccionActual);
                }
            }




        }
    }


    //#####################################################################################################
    //#                  TODO: MOSTRAR ERROR SI SE QUIERE SALIR DEL RANGO DE PILAS                        #
    //#####################################################################################################



    //LEFT
    if(Action::Actions[instruccionActual] == 2)
    {
        //la posicion X que deberia de tener
        int posX_grua = Pos_Grua_Inicial + ((posActualGrua-1) * (Size_Caja + 20));
        int posX_gruaActual = this->cableDeLaGrua->x();


        if(posX_grua != this->cableDeLaGrua->x())
        {
            this->cableDeLaGrua->setPos(this->cableDeLaGrua->x()-1, this->cableDeLaGrua->y());
            this->grua_izq->setPos(this->grua_izq->x()-1, this->grua_izq->y());
            this->grua_der->setPos(this->grua_der->x()-1, this->grua_der->y());
            if(this->cajitaDeLaGrua != 0)
                this->cajitaDeLaGrua->setX(this->cajitaDeLaGrua->x() - 1);
        }
        else
        {
            posActualGrua--;
            if((instruccionActual+1) % 8 == 0 || instruccionActual == 27)
                this->stackDeInstrucciones.pop();
            else
            {
                instruccionActual++;
                this->stackDeInstrucciones.pop();
                this->stackDeInstrucciones.push(instruccionActual);
            }
            return;
        }
    }

    //RIGHT
    if(Action::Actions[instruccionActual] == 3)
    {
        //la posicion X que deberia de tener
        int posX_grua = Pos_Grua_Inicial + ((posActualGrua+1) * (Size_Caja + 20));
        int posX_gruaActual = this->cableDeLaGrua->x();


        if(posX_grua != this->cableDeLaGrua->x())
        {
            this->cableDeLaGrua->setPos(this->cableDeLaGrua->x()+1, this->cableDeLaGrua->y());
            this->grua_izq->setPos(this->grua_izq->x()+1, this->grua_izq->y());
            this->grua_der->setPos(this->grua_der->x()+1, this->grua_der->y());
            if(this->cajitaDeLaGrua != 0)
                this->cajitaDeLaGrua->setX(this->cajitaDeLaGrua->x() + 1);
        }
        else
        {
            posActualGrua++;
            if((instruccionActual+1) % 8 == 0 || instruccionActual == 27)
                this->stackDeInstrucciones.pop();
            else
            {
                instruccionActual++;
                this->stackDeInstrucciones.pop();
                this->stackDeInstrucciones.push(instruccionActual);
            }
            return;
        }
    }



    //NUMBER JUAN (1)
    if(Action::Actions[instruccionActual] == 4)
    {
        this->stackDeInstrucciones.push(0);
    }


    //NUMBER TU (2)
    if(Action::Actions[instruccionActual] == 5)
    {
        this->stackDeInstrucciones.push(8);
    }


    //NUMBER TREE (3)
    if(Action::Actions[instruccionActual] == 6)
    {
        this->stackDeInstrucciones.push(16);
    }


    //NUMBER FOR (4)
    if(Action::Actions[instruccionActual] == 7)
    {
        this->stackDeInstrucciones.push(24);
    }



}

void graphicsscenegame::CambiarVelocidad()
{
    if(this->timer->interval() == Velocidad_Normal)
        this->timer->setInterval(Velocidad_Rapida);
    else
        this->timer->setInterval(Velocidad_Normal);
}

void graphicsscenegame::terminoAnimacion()
{


}


