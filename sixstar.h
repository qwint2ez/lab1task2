#ifndef SIXSTAR_H
#define SIXSTAR_H

#include "shape.h"
#include <QGraphicsPolygonItem>
#include <QGraphicsEllipseItem>

class SixStar : public Shape
{
public:
    SixStar(int radius);

    QGraphicsPolygonItem* getItem() override;
    QGraphicsEllipseItem* getCenterOfMass() override;
    double getArea() override;
    double getPerimeter() override;
    void moveCenterOfMass(double dx, double dy);
    void scale(double factor);
    void setRadius(int newRadius) { radius = newRadius; }

private:
    QGraphicsPolygonItem *sstar;
    QGraphicsEllipseItem *centerOfMass;
    int radius;
};

#endif // SIXSTAR_H
