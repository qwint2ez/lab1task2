#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"
#include <QGraphicsPolygonItem>
#include <QGraphicsEllipseItem>

class Triangle : public Shape
{
public:
    Triangle(int side);

    QGraphicsPolygonItem* getItem() override;
    QGraphicsEllipseItem* getCenterOfMass() override;
    double getArea() override;
    double getPerimeter() override;
    void moveCenterOfMass(double dx, double dy);
    void scale(double factor);

private:
    QGraphicsPolygonItem *triangle;
    QGraphicsEllipseItem *centerOfMass;
    int side;
};

#endif // TRIANGLE_H
