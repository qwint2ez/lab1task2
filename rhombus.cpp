#include "rhombus.h"
#include <QBrush>
#include <QPolygonF>
#include <cmath>

Rhombus::Rhombus(int diagonal1, int diagonal2)
    : diagonal1(diagonal1), diagonal2(diagonal2)
{
    QPolygonF polygon;
    polygon << QPointF(0, 0) << QPointF(diagonal1 / 2, diagonal2 / 2) << QPointF(diagonal1, 0) << QPointF(diagonal1 / 2, -diagonal2 / 2);
    rhombus = new QGraphicsPolygonItem(polygon);

    double centerX = (polygon[0].x() + polygon[1].x() + polygon[2].x() + polygon[3].x()) / 4;
    double centerY = (polygon[0].y() + polygon[1].y() + polygon[2].y() + polygon[3].y()) / 4;

    rhombus->setPos(-centerX, -centerY);

    centerOfMass = new QGraphicsEllipseItem(0, 0, 10, 10, rhombus);
    centerOfMass->setPos(centerX - 5, centerY - 5);
    centerOfMass->setBrush(QBrush(Qt::red));
    centerOfMass->hide();

    rhombus->setTransformOriginPoint(centerX, centerY);
}

QGraphicsPolygonItem* Rhombus::getItem()
{
    return rhombus;
}

QGraphicsEllipseItem* Rhombus::getCenterOfMass()
{
    return centerOfMass;
}

double Rhombus::getArea()
{
    return 0.5 * diagonal1 * diagonal2;
}

double Rhombus::getPerimeter()
{
    return 2 * sqrt(pow(diagonal1 / 2, 2) + pow(diagonal2 / 2, 2));
}

void Rhombus::moveCenterOfMass(double dx, double dy)
{
    rhombus->moveBy(dx, dy);
    centerOfMass->moveBy(dx, dy);
}

void Rhombus::scale(double factor)
{
    rhombus->setScale(rhombus->scale() * factor);
    centerOfMass->setScale(centerOfMass->scale() * factor);
}


