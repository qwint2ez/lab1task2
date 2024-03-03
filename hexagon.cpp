#include "hexagon.h"
#include <QBrush>
#include <QPolygonF>
#include <cmath>

Hexagon::Hexagon(int sideHexagon)
    : sideHexagon(sideHexagon)
{
    QPolygonF polygon;
    for (int i = 0; i < 6; ++i) {
        polygon << QPointF(sideHexagon * cos(i * M_PI / 3), sideHexagon * sin(i * M_PI / 3));
    }
    hexagon = new QGraphicsPolygonItem(polygon);

    double centerX = 0;
    double centerY = 0;

    hexagon->setPos(-centerX, -centerY);

    centerOfMass = new QGraphicsEllipseItem(0, 0, 10, 10, hexagon);
    centerOfMass->setPos(centerX - 5, centerY - 5);
    centerOfMass->setBrush(QBrush(Qt::red));
    centerOfMass->hide();

    hexagon->setTransformOriginPoint(centerX, centerY);
}


QGraphicsPolygonItem* Hexagon::getItem()
{
    return hexagon;
}

QGraphicsEllipseItem* Hexagon::getCenterOfMass()
{
    return centerOfMass;
}

double Hexagon::getArea()
{
    return 3 * sqrt(3) / 2 * sideHexagon * sideHexagon;
}

double Hexagon::getPerimeter()
{
    return 6 * sideHexagon;
}

void Hexagon::moveCenterOfMass(double dx, double dy)
{
    hexagon->moveBy(dx, dy);
    centerOfMass->moveBy(dx, dy);
}

