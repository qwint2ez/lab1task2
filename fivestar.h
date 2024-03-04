#ifndef FIVESTAR_H
#define FIVESTAR_H

#include "shape.h"
#include <QGraphicsPolygonItem>
#include <QGraphicsEllipseItem>

class FiveStar : public Shape
{
public:
    FiveStar(int fradius);

    QGraphicsPolygonItem* getItem() override;
    QGraphicsEllipseItem* getCenterOfMass() override;
    QGraphicsLineItem* getLine1() override { return nullptr; }
    QGraphicsLineItem* getLine2() override { return nullptr; }
    double getArea() override;
    double getPerimeter() override;
    void moveCenterOfMass(double dx, double dy);
    void scale(double factor);
    void setRadius(int newFRadius) { fradius = newFRadius; }

private:
    QGraphicsPolygonItem *fstar;
    QGraphicsEllipseItem *centerOfMass;
    int fradius;
};

#endif // FIVESTAR_H
