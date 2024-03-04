#ifndef EIGHTSTAR_H
#define EIGHTSTAR_H

#include "shape.h"
#include <QGraphicsPolygonItem>
#include <QGraphicsEllipseItem>

class EightStar : public Shape
{
public:
    EightStar(int eradius);

    QGraphicsPolygonItem* getItem() override;
    QGraphicsEllipseItem* getCenterOfMass() override;
    QGraphicsLineItem* getLine1() override { return nullptr; }
    QGraphicsLineItem* getLine2() override { return nullptr; }
    double getArea() override;
    double getPerimeter() override;
    void moveCenterOfMass(double dx, double dy);
    void scale(double factor);
    void setRadius(int newERadius) { eradius = newERadius; }

private:
    QGraphicsPolygonItem *estar;
    QGraphicsEllipseItem *centerOfMass;
    int eradius;
};

#endif // EIGHTSTAR_H
