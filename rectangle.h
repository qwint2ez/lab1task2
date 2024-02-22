#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>

class MyRectangle : public QGraphicsRectItem
{
public:
    MyRectangle(qreal width, qreal height) : QGraphicsRectItem(0, 0, width, height) {}

    qreal area() const {
        return rect().width() * rect().height();
    }

    qreal perimeter() const {
        return 2 * (rect().width() + rect().height());
    }
};

class Rectangle
{
public:
    Rectangle(int width, int height);

    MyRectangle* getRectangle();
    QGraphicsEllipseItem* getCenterOfMass();
    void moveCenterOfMass(double dx, double dy);
    void scale(double factor);

private:
    MyRectangle *rectangle;
    QGraphicsEllipseItem *centerOfMass;
};




#endif // RECTANGLE_H
