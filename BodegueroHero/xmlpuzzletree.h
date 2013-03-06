#ifndef XMLPUZZLETREE_H
#define XMLPUZZLETREE_H

//MM: El parser genera esta clase
#include <QVector>


class XmlPuzzleTree
{
public:
    enum Colores {AZUL = 0, VERDE = 1, NARANJA = 2, ROJO = 3, CAFE = 4, AMARILLO = 5};
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
