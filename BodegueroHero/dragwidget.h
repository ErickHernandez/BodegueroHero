#ifndef DRAGWIDGET_H
#define DRAGWIDGET_H

#include <QFrame>
#include <QDragEnterEvent>
#include <QLabel>
#include <QMimeData>
#include <QDrag>
#include <QPainter>

class QDragEnterEvent;
class QDropEvent;

class DragWidget: public QFrame
{
public:
    //DragWidget(QWidget *parent=0);
    DragWidget(bool isOriginFrame, QWidget *parent=0);
    bool hasItem;//Determina si ese frame ya tiene alguna instruccion dentro o esta vacio.
    bool isOriginFrame;//Determina si es el frame del toolkit o es el de destino donde estan las lanes.

protected:
     void dragEnterEvent(QDragEnterEvent *event);
     void dragMoveEvent(QDragMoveEvent *event);
     void dropEvent(QDropEvent *event);
     void mousePressEvent(QMouseEvent *event);
 };

#endif // DRAGWIDGET_H
