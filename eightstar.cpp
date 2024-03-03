#include "eightstar.h"
#include <QBrush>
#include <QPolygonF>
#include <cmath>

EightStar::EightStar(int radius)
    : radius(radius)
{
    QPolygonF polygon;
    for (int i = 0; i < 16; ++i) {
        double r = (i % 2 == 0) ? radius : radius / 2.0;
        polygon << QPointF(r * cos(i * M_PI / 8), r * sin(i * M_PI / 8));
    }
    estar = new QGraphicsPolygonItem(polygon);

    double centerX = 0;
    double centerY = 0;

    estar->setPos(-centerX, -centerY);

    centerOfMass = new QGraphicsEllipseItem(0, 0, 10, 10, estar);
    centerOfMass->setPos(centerX - 5, centerY - 5);
    centerOfMass->setBrush(QBrush(Qt::red));
    centerOfMass->hide();

    estar->setTransformOriginPoint(centerX, centerY);
}

QGraphicsPolygonItem* EightStar::getItem()
{
    return estar;
}

QGraphicsEllipseItem* EightStar::getCenterOfMass()
{
    return centerOfMass;
}

double EightStar::getArea()
{
    return 2 * sqrt(2) * (radius) * (radius);
}

double EightStar::getPerimeter()
{
    return 16 * (radius) * sin(M_PI / 8);
}

void EightStar::moveCenterOfMass(double dx, double dy)
{
    estar->moveBy(dx, dy);
    centerOfMass->moveBy(dx, dy);
}
