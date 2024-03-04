#ifndef HEXAGON_H
#define HEXAGON_H

#include "shape.h"
#include <QGraphicsPolygonItem>
#include <QGraphicsEllipseItem>

class Hexagon : public Shape
{
public:
    Hexagon(int sideHexagon);

    QGraphicsPolygonItem* getItem() override;
    QGraphicsEllipseItem* getCenterOfMass() override;
    QGraphicsLineItem* getLine1() override { return nullptr; }
    QGraphicsLineItem* getLine2() override { return nullptr; }
    double getArea() override;
    double getPerimeter() override;
    void moveCenterOfMass(double dx, double dy);
    void scale(double factor);
    void setSideHexagon(int newSideHexagon) { sideHexagon = newSideHexagon; }

private:
    QGraphicsPolygonItem *hexagon;
    QGraphicsEllipseItem *centerOfMass;
    int sideHexagon;
};

#endif // HEXAGON_H
