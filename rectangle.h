#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>

class Rectangle : public Shape
{
public:
    Rectangle(int width, int height);

    QGraphicsRectItem* getItem() override;
    QGraphicsEllipseItem* getCenterOfMass() override;
    double getArea() override;
    double getPerimeter() override;

private:
    QGraphicsRectItem *rectangle;
    QGraphicsEllipseItem *centerOfMass;
    int width;
    int height;
};

#endif // RECTANGLE_H
