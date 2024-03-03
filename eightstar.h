#ifndef EIGHTSTAR_H
#define EIGHTSTAR_H

#include "shape.h"
#include <QGraphicsPolygonItem>
#include <QGraphicsEllipseItem>

class EightStar : public Shape
{
public:
    EightStar(int radius);

    QGraphicsPolygonItem* getItem() override;
    QGraphicsEllipseItem* getCenterOfMass() override;
    double getArea() override;
    double getPerimeter() override;
    void moveCenterOfMass(double dx, double dy);
    void scale(double factor);
    void setRadius(int newRadius) { radius = newRadius; }

private:
    QGraphicsPolygonItem *estar;
    QGraphicsEllipseItem *centerOfMass;
    int radius;
};

#endif // EIGHTSTAR_H
