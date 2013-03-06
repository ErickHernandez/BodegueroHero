#include "dragwidget.h"
#include <QLabel>
#include <QDebug>


DragWidget::DragWidget(bool isOriginFrame, int id, QWidget *parent): QFrame(parent)
{
    this->action = Action::Empty();
    this->id = id;
    setMinimumSize(200, 200);
    setFrameStyle(QFrame::Sunken | QFrame::StyledPanel);
    setAcceptDrops(true);
    this->isOriginFrame = isOriginFrame;    



    if(isOriginFrame)
    {
        QLabel *down_arrow = new QLabel(this);
        down_arrow->setPixmap(QPixmap(":/images/down_arrow.png"));
        down_arrow->move(24, 80);
        down_arrow->setObjectName("down");
        down_arrow->show();
        down_arrow->setAttribute(Qt::WA_DeleteOnClose);

        QLabel *left_arrow = new QLabel(this);
        left_arrow->setPixmap(QPixmap(":/images/left_arrow.png"));
        left_arrow->move(74, 80);
        left_arrow->setObjectName("left");
        left_arrow->show();
        left_arrow->setAttribute(Qt::WA_DeleteOnClose);

        QLabel *right_arrow = new QLabel(this);
        right_arrow->setPixmap(QPixmap(":/images/right_arrow.png"));
        right_arrow->move(124, 80);
        right_arrow->setObjectName("right");
        right_arrow->show();
        right_arrow->setAttribute(Qt::WA_DeleteOnClose);

        QLabel *lane_1 = new QLabel(this);
        lane_1->setPixmap(QPixmap(":/images/lane_1.png"));
        lane_1->move(24, 20);
        lane_1->setObjectName("1");
        lane_1->show();
        lane_1->setAttribute(Qt::WA_DeleteOnClose);

        QLabel *lane_2 = new QLabel(this);
        lane_2->setPixmap(QPixmap(":/images/lane_2.png"));
        lane_2->move(74, 20);
        lane_2->setObjectName("2");
        lane_2->show();
        lane_2->setAttribute(Qt::WA_DeleteOnClose);

        QLabel *lane_3 = new QLabel(this);
        lane_3->setPixmap(QPixmap(":/images/lane_3.png"));
        lane_3->move(124, 20);
        lane_3->setObjectName("3");
        lane_3->show();
        lane_3->setAttribute(Qt::WA_DeleteOnClose);

        QLabel *lane_4 = new QLabel(this);
        lane_4->setPixmap(QPixmap(":/images/lane_4.png"));
        lane_4->move(174, 20);
        lane_4->setObjectName("4");
        lane_4->show();
        lane_4->setAttribute(Qt::WA_DeleteOnClose);

    }
}

void DragWidget::dragEnterEvent(QDragEnterEvent *event)
 {
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
            //EH: Cuando entra aqui es porque esta entrando al mismo layout de origen
            return;
        } else {
            event->acceptProposedAction();
            return;//EH: Cuando entra aqui es porque esta entrando a un layout diferente al de origen
        }
    } else {       
        event->ignore();
    }
 }

void DragWidget::dragMoveEvent(QDragMoveEvent *event)
{

    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        if (event->source() == this) {
           event->setDropAction(Qt::MoveAction);
            event->accept();
            //Aqui debe hacer empty la posicion array y la action
            return;//
        } else {
           event->acceptProposedAction();
           return;//
        }
    } else {
        event->ignore();
    }
}


void DragWidget::dropEvent(QDropEvent *event)
 {       

    if(this->action != Action::Empty()){// OK OK OK pero funciona
        event->ignore();
        return;
    }

     if (event->mimeData()->hasFormat("application/x-dnditemdata")) {

         if(this == event->source())
             return;

//event->source() != this &&
         if ( this->isOriginFrame == false){//VALIDAR SI EL ACION ES EMPTY

             QByteArray itemData = event->mimeData()->data("application/x-dnditemdata");
             QDataStream dataStream(&itemData, QIODevice::ReadOnly);

             QPixmap pixmap;
             QPoint offset;
             QString _Action;//EH: Esta variable almacena el tipo de instruccion
             dataStream >> pixmap >> offset>>_Action;


             //AQUI INSERTAR EN EL ARREGLO EL VALOR
             //SETEARLE LA ACTION AL THIS.ACTION
             int act = parsingActions(_Action);             
             this->action = act;
             Action::Actions[this->id] = act;

             this->newIcon = new QLabel(this);
             newIcon->setPixmap(pixmap);             
             offset.setX(0);
             offset.setY(0);
             newIcon->move(offset);
             newIcon->show();
             newIcon->setAttribute(Qt::WA_DeleteOnClose);
             newIcon->setObjectName(_Action);

             //if(((DragWidget*)event->source())->isOriginFrame)//Aqui me quede
             //{
                 event->setDropAction(Qt::MoveAction);
                 event->accept();                 
                 //return;
             //}
             //else
             //{
                 //event->ignore();
                 return;
             //}

         } else {
              event->ignore();
              return;
             //event->acceptProposedAction();
         }
     } else {         
         event->ignore();
     }
 }


void DragWidget::mousePressEvent(QMouseEvent *event)
 {
     QLabel *child = static_cast<QLabel*>(childAt(event->pos()));
     if (!child)
         return;

     QPixmap pixmap = *child->pixmap();

     QByteArray itemData;
     QDataStream dataStream(&itemData, QIODevice::WriteOnly);
     dataStream << pixmap << QPoint(event->pos() - child->pos())<<QString(child->objectName());

     QMimeData *mimeData = new QMimeData();
     mimeData->setData("application/x-dnditemdata", itemData);

     QDrag *drag = new QDrag(this);
     drag->setMimeData(mimeData);     
     drag->setPixmap(pixmap);
     drag->setHotSpot(event->pos() - child->pos());


    // QPixmap tempPixmap = pixmap;
    // QPainter painter;
    // painter.begin(&tempPixmap);
    // painter.fillRect(pixmap.rect(), QColor(127, 127, 127, 127));
    // painter.end();

    // child->setPixmap(tempPixmap);



     if (drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction) == Qt::MoveAction) {
         if(this->isOriginFrame == false){
            child->close(); // OK OK OK cuando le un bloque ya tiene imagen y se le da click este evento se dispara,
                            // tambien se dispara cuando se mueve de un bloque a otro.
            this->action = Action::Empty();
            Action::Actions[this->id] = Action::Empty();
           child->close();
         } else {
            event->ignore();//Origin Frame a un Bloque (Lo normal)
         }
         return;
     } else {
         if(this->isOriginFrame == false){
             this->action = Action::Empty();// OK OK OK aqui es cuando se elimina una imagen con drag and drop
             Action::Actions[this->id] = Action::Empty();
            child->close();
         } else {
            event->ignore();
         }
        //child->close();
        //malo child->show();
        //malo child->setPixmap(pixmap);
     }
 }

int DragWidget::parsingActions(QString action)
{
    if(action == "1")
        return Action::One();
    else if(action == "2")
        return Action::Two();
    else if(action == "3")
        return Action::Three();
    else if(action == "4")
        return Action::Four();
    else if(action == "down")
        return Action::Down();
    else if(action == "left")
        return Action::Left();
    else if(action == "right")
        return Action::Right();
}


