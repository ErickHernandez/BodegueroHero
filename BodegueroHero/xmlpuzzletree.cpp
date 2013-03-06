#include "xmlpuzzletree.h"


XmlPuzzleTree::XmlPuzzleTree()
{
    this->posicionInicialGrua = 0;
    this->idStackInicial = 0;
    this->idStackFinal = 7;
    this->sizeCaja = 0;

    //MM: CREAR LOS VECTORES VACIOS (8 es la cantidad maxima)
    for(int i=0; i<8; i++)
    {
        QVector<enum Colores> temp;
        this->pilasDeCajitas.push_back(temp);
    }
}

void XmlPuzzleTree::agregarCajitaPila(int posicionPila, enum Colores cajita)
{
    this->pilasDeCajitas[posicionPila].push_back(cajita);
}

void XmlPuzzleTree::setIdStackFinal(int idStackFinal)
{
    this->idStackFinal = idStackFinal;
}

void XmlPuzzleTree::setIdStackInicial(int idStackInicial)
{
    this->idStackInicial = idStackInicial;
}

void XmlPuzzleTree::setPosicionInicialGrua(int posisionGrua)
{
    this->posicionInicialGrua = posisionGrua;
}

void XmlPuzzleTree::setSizeCaja(int sizeCaja)
{
    this->sizeCaja = sizeCaja;
}

int XmlPuzzleTree::getIdStackFinal()
{
    return this->idStackFinal;
}

int XmlPuzzleTree::getIdStackInicial()
{
    return idStackInicial;
}

QVector<XmlPuzzleTree::Colores > XmlPuzzleTree::getPilaDeCajitas(int posicionPila)
{
    return this->pilasDeCajitas[posicionPila];
}

int XmlPuzzleTree::getPosicionInicialGrua()
{
    return this->posicionInicialGrua;
}

int XmlPuzzleTree::getSizeCaja()
{
    return this->sizeCaja;
}
