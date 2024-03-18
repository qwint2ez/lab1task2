#ifndef SHAPE_H
#define SHAPE_H

#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>

class Shape : public QGraphicsItem
{
public:
    virtual ~Shape() {}

    virtual QGraphicsItem* getItem() = 0;
    virtual QGraphicsEllipseItem* getCenterOfMass() = 0;
    virtual QGraphicsLineItem* getLine1() = 0;
    virtual QGraphicsLineItem* getLine2() = 0;
    virtual double getArea() = 0;
    virtual double getPerimeter() = 0;

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override
    {
        if (event->button() == Qt::LeftButton)
            startPos = event->pos();
    }

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override
    {
        if (event->buttons() & Qt::LeftButton) {
            int distance = (event->pos() - startPos).manhattanLength();
            if (distance >= startDragDistance)
                performDrag(event);
        }
    }

    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override
    {
        if (event->button() == Qt::LeftButton && (event->pos() - startPos).manhattanLength() < startDragDistance) {
            // обработка клика
        }
    }

private:
    void performDrag(QGraphicsSceneMouseEvent *event)
    {
        QPointF newPos = event->pos() + this->pos();
        this->setPos(newPos);
    }

    QPointF startPos;
    const int startDragDistance = 10; // Задайте своё значение для минимального расстояния перед началом перетаскивания
};

#endif // SHAPE_H
