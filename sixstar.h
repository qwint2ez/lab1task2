#ifndef SIXSTAR_H
#define SIXSTAR_H

#include "shape.h"
#include <QGraphicsPolygonItem>
#include <QGraphicsEllipseItem>

class SixStar : public Shape
{
public:
    SixStar(int sradius);

    QGraphicsPolygonItem* getItem() override;
    QGraphicsEllipseItem* getCenterOfMass() override;
    QGraphicsLineItem* getLine1() override { return nullptr; }
    QGraphicsLineItem* getLine2() override { return nullptr; }
    double getArea() override;
    double getPerimeter() override;
    void moveCenterOfMass(double dx, double dy);
    void scale(double factor);
    void setRadius(int newSRadius) { sradius = newSRadius; }

private:
    QGraphicsPolygonItem *sstar;
    QGraphicsEllipseItem *centerOfMass;
    int sradius;
};

#endif // SIXSTAR_H
