#include "circle.h"
#include <QBrush>
#include <cmath>

Circle::Circle(int diameter)
    : diameter(diameter)
{
    circle = new QGraphicsEllipseItem(0, 0, diameter, diameter);

    double centerX = diameter / 2;
    double centerY = diameter / 2;

    circle->setPos(-centerX, -centerY);

    centerOfMass = new QGraphicsEllipseItem(0, 0, 10, 10, circle);
    centerOfMass->setPos(centerX - 5, centerY - 5);
    centerOfMass->setBrush(QBrush(Qt::red));
    centerOfMass->hide();

    circle->setTransformOriginPoint(centerX, centerY);
}

QGraphicsEllipseItem* Circle::getItem()
{
    return circle;
}

QGraphicsEllipseItem* Circle::getCenterOfMass()
{
    return centerOfMass;
}

double Circle::getArea()
{
    return M_PI * pow(diameter / 2, 2);
}

double Circle::getPerimeter()
{
    return M_PI * diameter;
}

void Circle::moveCenterOfMass(double dx, double dy)
{
    circle->moveBy(dx, dy);
    centerOfMass->moveBy(dx, dy);
}

