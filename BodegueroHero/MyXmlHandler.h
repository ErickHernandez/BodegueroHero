#ifndef MYXMLHANDLER_H
#define MYXMLHANDLER_H

//MM: INCLUDES AGREGADOS
#include <QtCore>
#include <QtXml>
#include <iostream>
#include "xmlpuzzletree.h"
#include <QString>

class MyXmlHandler: public QXmlDefaultHandler
{
public:
    MyXmlHandler():QXmlDefaultHandler()
    {
        this->arbolDelPreview = new XmlPuzzleTree();
        this->arbolEstadoInicial = new XmlPuzzleTree();
        this->currentContextDelTag = "";
        this->currentPila = 0;
    };
    XmlPuzzleTree* getArbolEstadoInicial()
    {
        return arbolEstadoInicial;
    };
    XmlPuzzleTree* getArbolEstadoFinal()
    {
        return arbolDelPreview;
    };


    ~MyXmlHandler(){
    };

    virtual bool startElement(const QString &namespaceURI, const QString &localName, const QString &qName, const QXmlAttributes &atts)
    {

        if(localName == "Informacion")
        {
            this->currentContextDelTag = "Informacion";
        }

        if(localName == "Preview")
        {
            this->currentContextDelTag = "Preview";
        }

        if(localName == "EstadoInicialPuzzle")
        {
            this->currentContextDelTag = "EstadoInicialPuzzle";
        }

        if(localName == "SizeCajaPreview")
        {
            if(this->currentContextDelTag == "Informacion")
            {
                int sizeCaja = atts.value(0).toInt();
                this->arbolDelPreview->setSizeCaja(sizeCaja);
            }
            else
                return false;
        }

        if(localName == "SizeCajaEstadoInicial")
        {
            if(this->currentContextDelTag == "Informacion")
            {
                int sizeCaja = atts.value(0).toInt();
                this->arbolEstadoInicial->setSizeCaja(sizeCaja);
            }
            else
                return false;
        }

        if(localName == "StackInicial")
        {
            if(this->currentContextDelTag == "Informacion")
            {
                int stackInicial = atts.value(0).toInt();
                this->arbolEstadoInicial->setIdStackInicial(stackInicial);
                this->arbolDelPreview->setIdStackInicial(stackInicial);
            }
            else
                return false;
        }

        if(localName == "StackFinal")
        {
            if(this->currentContextDelTag == "Informacion")
            {
                int stackFinal = atts.value(0).toInt();
                this->arbolEstadoInicial->setIdStackFinal(stackFinal);
                this->arbolDelPreview->setIdStackFinal(stackFinal);
            }
            else
                return false;
        }

        if(localName == "PosicionInicialGrua")
        {
            if(this->currentContextDelTag == "Informacion")
            {
                int posGrua = atts.value(0).toInt();
                this->arbolEstadoInicial->setPosicionInicialGrua(posGrua);
                this->arbolDelPreview->setPosicionInicialGrua(posGrua);
            }
            else
                return false;
        }

        if(localName == "Pila")
        {
            if(this->currentContextDelTag != "Preview" && this->currentContextDelTag!="EstadoInicialPuzzle")
                return false;

            this->currentPila = atts.value(0).toInt();
        }

        if(localName == "Caja")
        {
            QString caja = atts.value(0).toLower();
            int posPila = this->currentPila;


            if(this->currentContextDelTag == "Preview")
            {
                if(caja == "azul")
                    this->arbolDelPreview->agregarCajitaPila(posPila,AZUL);
                else if(caja == "verde")
                    this->arbolDelPreview->agregarCajitaPila(posPila,VERDE);
                else if(caja == "naranja")
                    this->arbolDelPreview->agregarCajitaPila(posPila,NARANJA);
                else if(caja == "rojo")
                    this->arbolDelPreview->agregarCajitaPila(posPila,ROJO);
                else if(caja == "cafe")
                    this->arbolDelPreview->agregarCajitaPila(posPila,CAFE);
                else if(caja == "amarillo")
                    this->arbolDelPreview->agregarCajitaPila(posPila ,AMARILLO);
                else
                    return false;

            }

            if(this->currentContextDelTag == "EstadoInicialPuzzle")
            {
                if(caja == "azul")
                    this->arbolEstadoInicial->agregarCajitaPila(posPila,AZUL);
                else if(caja == "verde")
                    this->arbolEstadoInicial->agregarCajitaPila(posPila,VERDE);
                else if(caja == "naranja")
                    this->arbolEstadoInicial->agregarCajitaPila(posPila,NARANJA);
                else if(caja == "rojo")
                    this->arbolEstadoInicial->agregarCajitaPila(posPila,ROJO);
                else if(caja == "cafe")
                    this->arbolEstadoInicial->agregarCajitaPila(posPila,CAFE);
                else if(caja == "amarillo")
                    this->arbolEstadoInicial->agregarCajitaPila(posPila ,AMARILLO);
                else
                    return false;

            }



        }


        return true;
    };

    virtual bool endElement(const QString &namespaceURI, const QString &localName, const QString &qName)
    {

        if(localName == "Preview" || localName == "EstadoInicialPuzzle" || localName == "Informacion")
            this->currentContextDelTag = "";

        return true;
    }

private:
    XmlPuzzleTree *arbolEstadoInicial;
    XmlPuzzleTree *arbolDelPreview;
    QString currentContextDelTag;
    int currentPila;
};

#endif // MYXMLHANDLER_H
