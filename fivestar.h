#ifndef FIVESTAR_H
#define FIVESTAR_H

#include "shape.h"
#include <QGraphicsPolygonItem>
#include <QGraphicsEllipseItem>

class FiveStar : public Shape
{
public:
    FiveStar(int radius);

    QGraphicsPolygonItem* getItem() override;
    QGraphicsEllipseItem* getCenterOfMass() override;
    double getArea() override;
    double getPerimeter() override;
    void moveCenterOfMass(double dx, double dy);
    void scale(double factor);
    void setRadius(int newRadius) { radius = newRadius; }

private:
    QGraphicsPolygonItem *fstar;
    QGraphicsEllipseItem *centerOfMass;
    int radius;
};

#endif // FIVESTAR_H
