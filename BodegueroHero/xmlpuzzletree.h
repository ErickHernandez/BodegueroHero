#ifndef XMLPUZZLETREE_H
#define XMLPUZZLETREE_H

//MM: El parser genera esta clase
#include <QVector>

enum Colores {AZUL, VERDE, NARANJA, ROJO, CAFE, AMARILLO};

class XmlPuzzleTree
{
public:
    XmlPuzzleTree();
    ~XmlPuzzleTree(){};
    void agregarCajitaPila(int posicionPila, enum Colores cajita);

    //MM: Funciones SETS
    void setSizeCaja(int sizeCaja);
    void setIdStackInicial(int idStackInicial);
    void setIdStackFinal(int idStackFinal);
    void setPosicionInicialGrua(int posisionGrua);

    //MM: Funciones GETS
    int getIdStackInicial();
    int getIdStackFinal();
    int getSizeCaja();
    int getPosicionInicialGrua();
    QVector<enum Colores> getPilaDeCajitas(int posicionPila);

private:
    int idStackInicial;
    int idStackFinal;
    int sizeCaja;
    int posicionInicialGrua;
    QVector<QVector<enum Colores> > pilasDeCajitas;
};
#endif // XMLPUZZLETREE_H
