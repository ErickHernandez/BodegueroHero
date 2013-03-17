#include "graphicsscenegame.h"

#define Pos_X_Inicial  180
#define Pos_Y_Inicial  324  - 12
#define Size_Caja      36
#define Pos_Grua_Inicial 167 + 26
#define Velocidad_Normal    10
#define Velocidad_Rapida    4
#define Size_Nube1       103
#define Size_Nube2       83
#define Size_Nube3       82
#define Size_Nube4       159

graphicsscenegame::graphicsscenegame(QString puzzle, QObject *parent): QGraphicsScene(parent)
{
    this->setXmlPuzzleTrees(puzzle);
    this->PintarBackgroud();
    this->PintarPuzzle(this->xmlTreeInicial);

    this->timer = new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(animar_v2()));

    this->timer_nubes = new QTimer;
    connect(timer_nubes,SIGNAL(timeout()),this,SLOT(animar_Nubes()));
    this->timer_nubes->start(40);
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

void graphicsscenegame::PintarBackgroud()
{
    //PRIMERO DIBUJO EL BACKGROUND
    //MM: IMAGENES DEL GRAPHICS SCENE QUE SE USAN PARA ARMAR EL BACKGROUND
    this->setSceneRect(0,0,700,400);

    QPixmap *pixmap = new QPixmap(":images/Background_game_simple.png");
    QGraphicsPixmapItem *background = new QGraphicsPixmapItem();
    background->setPixmap(*pixmap);
    this->addItem(background);

    pixmap = new QPixmap(":images/Centro de Mando.png");
    background = new QGraphicsPixmapItem();
    background->setPixmap(*pixmap);
    background->setPos(10, 285);
    background->setZValue(20);
    this->addItem(background);

    pixmap = new QPixmap(":images/Suelo_game.png");
    background = new QGraphicsPixmapItem();
    background->setPixmap(*pixmap);
    background->setPos(0, 355);
//    background->setPos(0, 354.97);
    background->setZValue(20);
    this->addItem(background);

    //CABLES QUE SALEN DEL CENTRO DE MANDO
    pixmap = new QPixmap(":images/Cable_largo.png");
    cable_CentroDeMando_izq = new QGraphicsPixmapItem();
    cable_CentroDeMando_izq->setPixmap(*pixmap);
    cable_CentroDeMando_izq->setPos(20, -300);
    cable_CentroDeMando_izq->setZValue(10);
    this->addItem(cable_CentroDeMando_izq);


    pixmap = new QPixmap(":images/Cable_largo.png");
    cable_CentroDeMando_der = new QGraphicsPixmapItem();
    cable_CentroDeMando_der->setPixmap(*pixmap);
    cable_CentroDeMando_der->setPos(38, -300);
    cable_CentroDeMando_der->setZValue(10);
    this->addItem(cable_CentroDeMando_der);

    //AGREGADO LO DE LAS NUBES EN MOVIMIENTO
    QPointF posNube1(195,125);
    QPointF posNube2(560,25);
    QPointF posNube3(390,75);
    QPointF posNube4(20,50);

    //INSTANCIAS DE LAS NUBES Y SU COPIAS
    //NUBE1
    pixmap = new QPixmap(":images/Nube1_game.png");
    nube1 = new QGraphicsPixmapItem();
    nube1->setPixmap(*pixmap);
    nube1->setPos(posNube1);
    nube1->setZValue(5);
    nube1->setTransformationMode(Qt::SmoothTransformation);
    this->addItem(nube1);
    //COPIA DE LA NUBE1
    pixmap = new QPixmap(":images/Nube1_game.png");
    nube1_2 = new QGraphicsPixmapItem();
    nube1_2->setPixmap(*pixmap);
    nube1_2->setPos(posNube1.x() - 700, posNube1.y());
    nube1_2->setZValue(5);
    nube1_2->setTransformationMode(Qt::SmoothTransformation);
    this->addItem(nube1_2);

    //NUBE2
    pixmap = new QPixmap(":images/Nube2_game.png");
    nube2 = new QGraphicsPixmapItem();
    nube2->setPixmap(*pixmap);
    nube2->setPos(posNube2);
    nube2->setZValue(5);
    nube2->setTransformationMode(Qt::SmoothTransformation);
    this->addItem(nube2);
    //COPIA DE LA NUBE2
    pixmap = new QPixmap(":images/Nube2_game.png");
    nube2_2 = new QGraphicsPixmapItem();
    nube2_2->setPixmap(*pixmap);
    nube2_2->setPos(posNube2.x() - 700, posNube2.y());
    nube2_2->setZValue(5);
    nube2_2->setTransformationMode(Qt::SmoothTransformation);
    this->addItem(nube2_2);

    //NUBE3
    pixmap = new QPixmap(":images/Nube3_game.png");
    nube3 = new QGraphicsPixmapItem();
    nube3->setPixmap(*pixmap);
    nube3->setPos(posNube3);
    nube3->setZValue(5);
    nube3->setTransformationMode(Qt::SmoothTransformation);
    this->addItem(nube3);
    //COPIA DE LA NUBE3
    pixmap = new QPixmap(":images/Nube3_game.png");
    nube3_2 = new QGraphicsPixmapItem();
    nube3_2->setPixmap(*pixmap);
    nube3_2->setPos(posNube3.x() - 700, posNube3.y());
    nube3_2->setZValue(5);
    nube3_2->setTransformationMode(Qt::SmoothTransformation);
    this->addItem(nube3_2);

    //NUBE4
    pixmap = new QPixmap(":images/Nube4_game.png");
    nube4 = new QGraphicsPixmapItem();
    nube4->setPixmap(*pixmap);
    nube4->setPos(posNube4);
    nube4->setZValue(5);
    nube4->setTransformationMode(Qt::SmoothTransformation);
    this->addItem(nube4);
    //COPIA DE LA NUBE4
    pixmap = new QPixmap(":images/Nube4_game.png");
    nube4_2 = new QGraphicsPixmapItem();
    nube4_2->setPixmap(*pixmap);
    nube4_2->setPos(posNube4.x() - 700, posNube4.y());
    nube4_2->setZValue(5);
    nube4_2->setTransformationMode(Qt::SmoothTransformation);
    this->addItem(nube4_2);

}

void graphicsscenegame::PintarPuzzle(XmlPuzzleTree *puzzleTree)
{
    this->stackDeInstrucciones.push(0);
    this->stepByStep = false;
    this->cajitaDeLaGrua = 0;
    this->velocidadActual = Velocidad_Normal;

    for(int i=0; i<8; i++)
    {
        QVector<Caja *> temp;
        this->pilasDeCajas.push_back(temp);
    }

    this->posPilaInicial = puzzleTree->getIdStackInicial();
    this->posPilaFinal   = puzzleTree->getIdStackFinal();
    int posTenazaInicial = puzzleTree->getPosicionInicialGrua();

    this->PintarBasesDeLasPilas(posPilaInicial, posPilaFinal);

    for(int i=posPilaInicial; i<=posPilaFinal; i++)
    {
        QVector<XmlPuzzleTree::Colores > colores = puzzleTree->getPilaDeCajitas(i);
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
    this->cableDeLaGrua->setZValue(20);
    this->addItem(this->cableDeLaGrua);

    QPixmap *grua_izq = new QPixmap(":images/grua_izq.png");
    this->grua_izq = new QGraphicsPixmapItem();
    this->grua_izq->setPixmap(*grua_izq);
    this->grua_izq->setPos(Pos_Grua_Inicial + (posActualGrua*(Size_Caja + 20)) - 13 - 14, 50);
    this->grua_izq->setZValue(20);
    this->addItem(this->grua_izq);

    QPixmap *grua_der = new QPixmap(":images/grua_der.png");
    this->grua_der = new QGraphicsPixmapItem();
    this->grua_der->setPixmap(*grua_der);
    this->grua_der->setPos(Pos_Grua_Inicial + (posActualGrua*(Size_Caja + 20)) - 13 + 14, 50);
    this->grua_der->setZValue(20);
    this->addItem(this->grua_der);

    //PARA QUE LA ROTACION SE MIRE SMOOTH
    this->grua_izq->setTransformationMode(Qt::SmoothTransformation);
    this->grua_der->setTransformationMode(Qt::SmoothTransformation);

//    this->grua_izq->setTransformOriginPoint(this->grua_izq->boundingRect().center());
//    this->grua_der->setTransformOriginPoint(this->grua_der->boundingRect().center());


    //ROTACION
    this->grua_izq->setTransform(QTransform().translate(36,0).rotate(20).translate(-36,0));
    this->grua_der->setTransform(QTransform().translate(0,0).rotate(-20).translate(0,0));
    this->gruaAbierta = true;
    this->anguloActualGrua = 20;

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

    this->ReiniciarPuzzle();
}

void graphicsscenegame::ReiniciarPuzzle()
{
    //REMOVER GRAPHICS ITEMS
    this->removeItem(this->cableDeLaGrua);
    this->removeItem(this->grua_der);
    this->removeItem(this->grua_izq);

    if(this->cajitaDeLaGrua != 0)
        this->removeItem(this->cajitaDeLaGrua);


    for(int i=this->posPilaInicial; i<=this->posPilaFinal; i++)
    {
        for(int j=0; j<this->pilasDeCajas[i].size(); j++)
        {
            this->removeItem(this->pilasDeCajas[i][j]);
        }
        this->pilasDeCajas[i].clear();
    }

    //RESETEAR VARIABLES
    this->instruccionActual = 0;
    this->subirGrua = false;
    while(!this->stackDeInstrucciones.empty())
        this->stackDeInstrucciones.pop();
    this->cajitaDeLaGrua = 0;
    this->stepByStep = false;

    //POR ULTIMO PINTAR EL PUZZLE OTRA VEZ
    this->PintarPuzzle(this->xmlTreeInicial);
}

void graphicsscenegame::DetenerPuzzle()
{
    if(timer->isActive())
    {
        this->timer->stop();
    }
    this->ReiniciarPuzzle();
}

void graphicsscenegame::animar_Nubes()
{
    if(this->nube1->x() == 700-Size_Nube1)
        this->nube1_2->setX(-Size_Nube1);
    if(this->nube1_2->x() == 700-Size_Nube1)
        this->nube1->setX(-Size_Nube1);


    if(this->nube2->x() == 700-Size_Nube2)
        this->nube2_2->setX(-Size_Nube2);
    if(this->nube2_2->x() == 700-Size_Nube2)
        this->nube2->setX(-Size_Nube2);


    if(this->nube3->x() == 700-Size_Nube3)
        this->nube3_2->setX(-Size_Nube3);
    if(this->nube3_2->x() == 700-Size_Nube3)
        this->nube3->setX(-Size_Nube3);


    if(this->nube4->x() == 700-Size_Nube4)
        this->nube4_2->setX(-Size_Nube4);
    if(this->nube4_2->x() == 700-Size_Nube4)
        this->nube4->setX(-Size_Nube4);


    this->nube1->setX(nube1->x()+1);
    this->nube1_2->setX(nube1_2->x()+1);

    this->nube2->setX(nube2->x()+1);
    this->nube2_2->setX(nube2_2->x()+1);

    this->nube3->setX(nube3->x()+1);
    this->nube3_2->setX(nube3_2->x()+1);

    this->nube4->setX(nube4->x()+1);
    this->nube4_2->setX(nube4_2->x()+1);
}


void graphicsscenegame::AnimarPuzzle()
{
    this->timer->start(this->velocidadActual);

}

void graphicsscenegame::animar_v2()
{
    if(this->stackDeInstrucciones.empty())
    {
        this->timer->stop();
        return;
    }

    int instruccionActual = this->stackDeInstrucciones.top();

    //INSTRUCCION VACIA
    if(Action::Actions[instruccionActual] == 0)
    {
        this->SiguienteInstruccion();
        return;
    }

    //DOWN
    if(Action::Actions[instruccionActual] == 1)
    {


        if(this->cajitaDeLaGrua != 0 && this->pilasDeCajas[posActualGrua].size() == 6)
        {
            this->timer->stop();
            while(!this->stackDeInstrucciones.empty())
                this->stackDeInstrucciones.pop();

            emit Error_CantidadMaximaCajas();

            return;
        }


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

            //ACTUALIZAR LA POSICION 'Y' DE LA GRUA Y DE LA CAJA QUE TIENE
            this->cableDeLaGrua->setPos(this->cableDeLaGrua->x(), this->cableDeLaGrua->y()+1);
            this->grua_izq->setPos(this->grua_izq->x(), this->grua_izq->y()+1);
            this->grua_der->setPos(this->grua_der->x(), this->grua_der->y()+1);
            if(this->cajitaDeLaGrua != 0)
                this->cajitaDeLaGrua->setY(this->cajitaDeLaGrua->y() + 1);


            //HACER EL MOVIENTO DE LAS CUERDAS QUE SALEN DEL CENTRO DE MANDO
            if(posY_gruaActual%2 == 0)
            {
                this->cable_CentroDeMando_izq->setY(this->cable_CentroDeMando_izq->y() + 1);
                this->cable_CentroDeMando_der->setY(this->cable_CentroDeMando_der->y() - 1);
            }


            //RELIZAR LA ANIMACION SI LA GRUA VA A AGARRAR UNA CAJA
            if(this->gruaAbierta == true)
            {

                if(posY_gruaActual>(posY_grua - 65) &&  posY_gruaActual%3 == 0)
                {
                    if(this->anguloActualGrua != 0)
                    {
                        int anguloGrua = this->anguloActualGrua - 1;
                        this->grua_izq->setTransform(QTransform().translate(36,0).rotate(anguloGrua).translate(-36,0));
                        this->grua_der->setTransform(QTransform().translate(0,0).rotate((anguloGrua) * -1).translate(0,0));

                        this->anguloActualGrua--;
                    }
                }
            }
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

            //SI LA GRUA LLEGO A SU PUNTO MAS BAJO, DEJO UNA CAJA O NO HAY CAJAS POR LEVANTAR, ENTONCES ABRO LA GRUA
            if(this->cajitaDeLaGrua == 0)
                this->gruaAbierta = true;
            else
                this->gruaAbierta = false;

            if(this->cableDeLaGrua->y() == posY_grua &&
                    (this->cajitaDeLaGrua == 0 || this->pilasDeCajas[posActualGrua].size()==0))
            {
                 this->gruaAbierta = true;
            }

            if(this->gruaAbierta && posY_gruaActual%3 == 0)
            {
                if(this->anguloActualGrua <= 20)
                {
                    this->anguloActualGrua++;

                    int anguloGrua = this->anguloActualGrua + 1;
                    this->grua_izq->setTransform(QTransform().translate(36,0).rotate(anguloGrua).translate(-36,0));
                    this->grua_der->setTransform(QTransform().translate(0,0).rotate((anguloGrua)*-1).translate(0,0));
                }
            }

            this->cableDeLaGrua->setY(this->cableDeLaGrua->y()-1);
            this->grua_izq->setY(this->grua_izq->y()-1);
            this->grua_der->setY(this->grua_der->y()-1);
            if(this->cajitaDeLaGrua != 0)
                this->cajitaDeLaGrua->setY(this->cajitaDeLaGrua->y()-1);


            //HACER EL MOVIENTO DE LAS CUERDAS QUE SALEN DEL CENTRO DE MANDO
            if(posY_gruaActual%2 == 0)
            {
                this->cable_CentroDeMando_izq->setY(this->cable_CentroDeMando_izq->y() - 1);
                this->cable_CentroDeMando_der->setY(this->cable_CentroDeMando_der->y() + 1);
            }


            //SI LLEGUE A LA PARTE MAS ALTA, SEGUIR CON LA OTRA INSTRUCCION
            if(this->cableDeLaGrua->y() == -453 + 50)
            {
                this->SiguienteInstruccion();
                this->subirGrua = false;
            }

        }
        return;
    }



    //LEFT
    if(Action::Actions[instruccionActual] == 2)
    {

        if(this->posActualGrua == this->posPilaInicial)
        {
            this->timer->stop();
            while(!this->stackDeInstrucciones.empty())
                this->stackDeInstrucciones.pop();

            emit Error_FueraDeRango();

            return;
        }

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
            this->posActualGrua--;
            this->SiguienteInstruccion();
        }
        return;
    }

    //RIGHT
    if(Action::Actions[instruccionActual] == 3)
    {

        if(this->posActualGrua == this->posPilaFinal)
        {
            this->timer->stop();
            while(!this->stackDeInstrucciones.empty())
                this->stackDeInstrucciones.pop();


            emit Error_FueraDeRango();

            return;
        }


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
            this->posActualGrua++;
            this->SiguienteInstruccion();
        }
        return;
    }



    //NUMBER JUAN (1)
    if(Action::Actions[instruccionActual] == 4)
    {
        this->SiguienteInstruccion();
        this->stackDeInstrucciones.push(0);

        return;
    }


    //NUMBER TU (2)
    if(Action::Actions[instruccionActual] == 5)
    {
        this->SiguienteInstruccion();
        this->stackDeInstrucciones.push(8);

        return;
    }


    //NUMBER TREE (3)
    if(Action::Actions[instruccionActual] == 6)
    {
        this->SiguienteInstruccion();
        this->stackDeInstrucciones.push(16);

        return;
    }


    //NUMBER FOR (4)
    if(Action::Actions[instruccionActual] == 7)
    {
        this->SiguienteInstruccion();
        this->stackDeInstrucciones.push(24);

        return;
    }



}

void graphicsscenegame::CambiarVelocidad()
{
    //BEFORE
//    if(this->timer->interval() == Velocidad_Normal)
//        this->timer->setInterval(Velocidad_Rapida);
//    else
//        this->timer->setInterval(Velocidad_Normal);

    //AFTER
    if(this->timer->interval() == Velocidad_Normal)
        this->timer->setInterval(Velocidad_Rapida);
    else
        this->timer->setInterval(Velocidad_Normal);

    if(this->velocidadActual == Velocidad_Normal)
        this->velocidadActual = Velocidad_Rapida;
    else
        this->velocidadActual = Velocidad_Normal;

}

void graphicsscenegame::terminoAnimacion()
{


}

void graphicsscenegame::SiguienteInstruccion()
{
    if((stackDeInstrucciones.top()+1) % 8 == 0 || stackDeInstrucciones.top() == 27)
    {
        this->stackDeInstrucciones.pop();
        if(this->stackDeInstrucciones.empty())
            return;
    }
    else
    {
        int instruccionActual = this->stackDeInstrucciones.top() + 1;
        this->stackDeInstrucciones.pop();
        this->stackDeInstrucciones.push(instruccionActual);
    }

    //MM: agregado
    if(Action::Actions[this->stackDeInstrucciones.top()] != 0)
    {
        this->instruccionActual = this->stackDeInstrucciones.top();
        if(this->timer->isActive() && this->stepByStep)
            this->timer->stop();

        emit CambioDeInstruccion();
    }

    if(PuzzleResuelto())
    {
        this->timer->stop();
        while(!this->stackDeInstrucciones.empty())
            this->stackDeInstrucciones.pop();
        int puntos = getCantidadInstruccionesUtilizadas();
        emit PuzzleFinalizado(puntos);
    }
}

bool graphicsscenegame::PuzzleResuelto()
{
    //PROCEDIMIENTO LOCO :E
    QVector<QVector<XmlPuzzleTree::Colores > > cajitas;
    for(int i=0; i<8; i++)
    {
        QVector<XmlPuzzleTree::Colores > temp;
        cajitas.push_back(temp);
    }

    for(int i=posPilaInicial; i<=posPilaFinal; i++)
    {
        for(int j=0; j<this->pilasDeCajas[i].size(); j++)
        {
            cajitas[i].push_back(pilasDeCajas[i][j]->getColorCaja());
        }
    }

    bool puzzleResuelto = true;

    for(int i=posPilaInicial; i<=posPilaFinal; i++)
    {
        if(cajitas[i] != this->xmlTreeFinal->getPilaDeCajitas(i))
        {
            puzzleResuelto = false;
            break;
        }
    }

    return puzzleResuelto;
}

int graphicsscenegame::getCantidadInstruccionesUtilizadas()
{
    int count = 0;
    for(int i=0; i<28; i++)
    {
        if(Action::Actions[i] != 0)
            count++;
    }
    return count;
}


int graphicsscenegame::getInstruccionActual()
{
    return this->instruccionActual;
}

void graphicsscenegame::EjecutarSiguienteInstruccion()
{
    if(!this->stepByStep)
        this->stepByStep = true;

    if(!this->timer->isActive())
        this->AnimarPuzzle();
}
