#include "fivestar.h"
#include <QBrush>
#include <QPolygonF>
#include <cmath>

FiveStar::FiveStar(int radius)
    : radius(radius)
{
    QPolygonF polygon;
    for (int i = 0; i < 10; ++i) {
        double r = (i % 2 == 0) ? radius : radius / 2.0;
        polygon << QPointF(r * cos(i * M_PI / 5), r * sin(i * M_PI / 5));
    }
    fstar = new QGraphicsPolygonItem(polygon);

    double centerX = 0;
    double centerY = 0;

    fstar->setPos(-centerX, -centerY);

    centerOfMass = new QGraphicsEllipseItem(0, 0, 10, 10, fstar);
    centerOfMass->setPos(centerX - 5, centerY - 5);
    centerOfMass->setBrush(QBrush(Qt::red));
    centerOfMass->hide();

    fstar->setTransformOriginPoint(centerX, centerY);
}


QGraphicsPolygonItem* FiveStar::getItem()
{
    return fstar;
}

QGraphicsEllipseItem* FiveStar::getCenterOfMass()
{
    return centerOfMass;
}

double FiveStar::getArea()
{
    return 5.0 / 4.0 * (radius) * (radius) * tan(M_PI / 5);
}

double FiveStar::getPerimeter()
{
    return 10 * (radius) * sin(M_PI / 5);
}

void FiveStar::moveCenterOfMass(double dx, double dy)
{
    fstar->moveBy(dx, dy);
    centerOfMass->moveBy(dx, dy);
}


