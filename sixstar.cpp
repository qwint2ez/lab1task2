#include "sixstar.h"
#include <QBrush>
#include <QPolygonF>
#include <cmath>

SixStar::SixStar(int radius)
    : radius(radius)
{
    QPolygonF polygon;
    for (int i = 0; i < 12; ++i) {
        double r = (i % 2 == 0) ? radius : radius / 2.0;
        polygon << QPointF(r * cos(i * M_PI / 6), r * sin(i * M_PI / 6));
    }
    sstar = new QGraphicsPolygonItem(polygon);

    double centerX = 0;
    double centerY = 0;

    sstar->setPos(-centerX, -centerY);

    centerOfMass = new QGraphicsEllipseItem(0, 0, 10, 10, sstar);
    centerOfMass->setPos(centerX - 5, centerY - 5);
    centerOfMass->setBrush(QBrush(Qt::red));
    centerOfMass->hide();

    sstar->setTransformOriginPoint(centerX, centerY);
}

QGraphicsPolygonItem* SixStar::getItem()
{
    return sstar;
}

QGraphicsEllipseItem* SixStar::getCenterOfMass()
{
    return centerOfMass;
}

double SixStar::getArea()
{
    return 3 * sqrt(3) / 2 * (radius) * (radius);
}

double SixStar::getPerimeter()
{
    return 12 * (radius) * sin(M_PI / 6);
}

void SixStar::moveCenterOfMass(double dx, double dy)
{
    sstar->moveBy(dx, dy);
    centerOfMass->moveBy(dx, dy);
}
