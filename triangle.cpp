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

    double centerX = (polygon[0].x() + polygon[1].x() + polygon[2].x()) / 3;
    double centerY = (polygon[0].y() + polygon[1].y() + polygon[2].y()) / 3;

    triangle->setPos(-centerX, -centerY);

    centerOfMass = new QGraphicsEllipseItem(0, 0, 10, 10, triangle);
    centerOfMass->setPos(centerX - 5, centerY - 5);
    centerOfMass->setBrush(QBrush(Qt::red));
    centerOfMass->hide();

    triangle->setTransformOriginPoint(centerX, centerY);
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
