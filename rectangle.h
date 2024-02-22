#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>

class Rectangle
{
public:
    Rectangle(int width, int height);

    QGraphicsRectItem* getRectangle();
    QGraphicsEllipseItem* getCenterOfMass();
    void moveCenterOfMass(double dx, double dy);

private:
    QGraphicsRectItem *rectangle;
    QGraphicsEllipseItem *centerOfMass;
};

#endif // RECTANGLE_H
