#include "dragwidget.h"
#include <QLabel>

DragWidget::DragWidget(bool isOriginFrame, QWidget *parent): QFrame(parent)
{
    setMinimumSize(200, 200);
    setFrameStyle(QFrame::Sunken | QFrame::StyledPanel);
    setAcceptDrops(true);

    if(isOriginFrame)
    {
        QLabel *down_arrow = new QLabel(this);
        down_arrow->setPixmap(QPixmap(":/images/down_arrow.png"));
        down_arrow->move(24, 20);
        down_arrow->show();
        down_arrow->setAttribute(Qt::WA_DeleteOnClose);

        QLabel *up_arrow = new QLabel(this);
        up_arrow->setPixmap(QPixmap(":/images/up_arrow.png"));
        up_arrow->move(74, 20);
        up_arrow->show();
        up_arrow->setAttribute(Qt::WA_DeleteOnClose);

        QLabel *left_arrow = new QLabel(this);
        left_arrow->setPixmap(QPixmap(":/images/left_arrow.png"));
        left_arrow->move(124, 20);
        left_arrow->show();
        left_arrow->setAttribute(Qt::WA_DeleteOnClose);

        QLabel *right_arrow = new QLabel(this);
        right_arrow->setPixmap(QPixmap(":/images/right_arrow.png"));
        right_arrow->move(174, 20);
        right_arrow->show();
        right_arrow->setAttribute(Qt::WA_DeleteOnClose);

        QLabel *lane_1 = new QLabel(this);
        lane_1->setPixmap(QPixmap(":/images/lane_1.png"));
        lane_1->move(24, 80);
        lane_1->show();
        lane_1->setAttribute(Qt::WA_DeleteOnClose);

        QLabel *lane_2 = new QLabel(this);
        lane_2->setPixmap(QPixmap(":/images/lane_2.png"));
        lane_2->move(74, 80);
        lane_2->show();
        lane_2->setAttribute(Qt::WA_DeleteOnClose);

        QLabel *lane_3 = new QLabel(this);
        lane_3->setPixmap(QPixmap(":/images/lane_3.png"));
        lane_3->move(124, 80);
        lane_3->show();
        lane_3->setAttribute(Qt::WA_DeleteOnClose);

        QLabel *lane_4 = new QLabel(this);
        lane_4->setPixmap(QPixmap(":/images/lane_4.png"));
        lane_4->move(174, 80);
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
         } else {
             event->acceptProposedAction();
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
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}


void DragWidget::dropEvent(QDropEvent *event)
 {
     if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
         QByteArray itemData = event->mimeData()->data("application/x-dnditemdata");
         QDataStream dataStream(&itemData, QIODevice::ReadOnly);

         QPixmap pixmap;
         QPoint offset;
         dataStream >> pixmap >> offset;

         QLabel *newIcon = new QLabel(this);
         newIcon->setPixmap(pixmap);
         newIcon->move(event->pos() - offset);
         newIcon->show();
         newIcon->setAttribute(Qt::WA_DeleteOnClose);

         if (event->source() == this) {
             event->setDropAction(Qt::MoveAction);
             event->accept();
         } else {
             event->acceptProposedAction();
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
     dataStream << pixmap << QPoint(event->pos() - child->pos());

     QMimeData *mimeData = new QMimeData();//////
     mimeData->setData("application/x-dnditemdata", itemData);

     QDrag *drag = new QDrag(this);
     drag->setMimeData(mimeData);
     drag->setPixmap(pixmap);
     drag->setHotSpot(event->pos() - child->pos());

     QPixmap tempPixmap = pixmap;
     QPainter painter;
     painter.begin(&tempPixmap);
     painter.fillRect(pixmap.rect(), QColor(127, 127, 127, 127));
     painter.end();

     child->setPixmap(tempPixmap);

     if (drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction) == Qt::MoveAction)
         child->close();
     else {
         child->show();
         child->setPixmap(pixmap);
     }
 }
