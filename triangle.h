#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QGraphicsPolygonItem>
#include <QGraphicsEllipseItem>

class Triangle
{
public:
    Triangle(int side);

    QGraphicsPolygonItem* getTriangle();
    QGraphicsEllipseItem* getCenterOfMass();
    void moveCenterOfMass(double dx, double dy);
    void scale(double factor);

private:
    QGraphicsPolygonItem *triangle;
    QGraphicsEllipseItem *centerOfMass;
};

#endif // TRIANGLE_H
