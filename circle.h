#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"
#include <QGraphicsEllipseItem>

class Circle : public Shape
{
public:
    Circle(int diameter);

    QGraphicsEllipseItem* getItem() override;
    QGraphicsEllipseItem* getCenterOfMass() override;
    double getArea() override;
    double getPerimeter() override;
    void moveCenterOfMass(double dx, double dy);
    void scale(double factor);
    void setDiameter(int newDiameter) { diameter = newDiameter; }

private:
    QGraphicsEllipseItem *circle;
    QGraphicsEllipseItem *centerOfMass;
    int diameter;
};

#endif // CIRCLE_H
