#include "mygraphicsview.h"
#include <QMouseEvent>

MyGraphicsView::MyGraphicsView(QWidget *parent)
    : QGraphicsView(parent)
    , m_mousePressed(false)
    , rectangle(nullptr)
{
    setScene(new QGraphicsScene(this));
}

void MyGraphicsView::mousePressEvent(QMouseEvent *event)
{
    m_origin = event->pos();
    rectangle = new QGraphicsRectItem(QRect(m_origin, QSize()));
    scene()->addItem(rectangle);
    m_mousePressed = true;
}

void MyGraphicsView::mouseMoveEvent(QMouseEvent *event)
{
    if (m_mousePressed) {
        QRect rect(m_origin, event->pos());
        rectangle->setRect(rect.normalized());
    }
}

void MyGraphicsView::mouseReleaseEvent(QMouseEvent *event)
{
    m_mousePressed = false;
}
