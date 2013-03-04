#ifndef DRAGWIDGET_H
#define DRAGWIDGET_H
#include <QFrame>
#include <QDragEnterEvent>
#include <QLabel>
#include <QMimeData>
#include <QDrag>
#include <QPainter>
#include <action.h>


class QDragEnterEvent;
class QDropEvent;

class DragWidget: public QFrame
{

public:
    //DragWidget(QWidget *parent=0);
    DragWidget(bool isOriginFrame, int id, QWidget *parent=0);
    bool hasItem;//Determina si ese frame ya tiene alguna instruccion dentro o esta vacio.
    bool isOriginFrame;//Determina si es el frame del toolkit o es el de destino donde estan las lanes.
    int action, id;
    //QLabel *newIcon;

protected:
     void dragEnterEvent(QDragEnterEvent *event);
     void dragMoveEvent(QDragMoveEvent *event);
     void dropEvent(QDropEvent *event);
     void mousePressEvent(QMouseEvent *event);     
private:
     int parsingActions(QString action);     
 };

#endif // DRAGWIDGET_H
