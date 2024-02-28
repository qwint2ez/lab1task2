#include "triangle.h"
#include <QBrush>
#include <QPolygonF>

Triangle::Triangle(int side)
{
    QPolygonF polygon;
    polygon << QPointF(0, 0) << QPointF(side, 0) << QPointF(side / 2, sqrt(3) * side / 2);
    triangle = new QGraphicsPolygonItem(polygon);
    triangle->setPos(-triangle->boundingRect().width()/2, -triangle->boundingRect().height()/2);
    centerOfMass = new QGraphicsEllipseItem(0, 0, 10, 10);
    centerOfMass->setPos(-5, -5);
    centerOfMass->setBrush(QBrush(Qt::red));
}

QGraphicsPolygonItem* Triangle::getTriangle()
{
    return triangle;
}

QGraphicsEllipseItem* Triangle::getCenterOfMass()
{
    return centerOfMass;
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
