#include "triangle.h"
#include <QBrush>
#include <QPolygonF>
#include <cmath>

Triangle::Triangle(int side)
    : side(side)
{
    QPolygonF polygon;
    polygon << QPointF(0, 0) << QPointF(side, 0) << QPointF(side / 2, sqrt(3) * side / 2);
    triangle = new QGraphicsPolygonItem(polygon);

    double centerX = polygon.boundingRect().center().x();
    double centerY = polygon.boundingRect().center().y();

    triangle->setPos(-centerX, -centerY);

    centerOfMass = new QGraphicsEllipseItem(0, 0, 10, 10);
    centerOfMass->setPos(-5, -5);
    centerOfMass->setBrush(QBrush(Qt::red));
}

QGraphicsPolygonItem* Triangle::getItem()
{
    return triangle;
}

QGraphicsEllipseItem* Triangle::getCenterOfMass()
{
    return centerOfMass;
}

double Triangle::getArea()
{
    return sqrt(3) / 4 * side * side;
}

double Triangle::getPerimeter()
{
    return 3 * side;
}

void Triangle::moveCenterOfMass(double dx, double dy)
{
    triangle->moveBy(dx, dy);
    centerOfMass->moveBy(dx, dy);
}

void Triangle::scale(double factor)
{
    triangle->setScale(triangle->scale() * factor);
    centerOfMass->setScale(centerOfMass->scale() * factor);
}
