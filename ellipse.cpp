#include "ellipse.h"
#include <QBrush>
#include <cmath>
#include <QPen>

Ellipse::Ellipse(int ewidth, int eheight)
    : ewidth(ewidth), eheight(eheight)
{
    ellipse = new QGraphicsEllipseItem(0, 0, ewidth, eheight);

    double centerX = ewidth / 2;
    double centerY = eheight / 2;

    ellipse->setPos(-centerX, -centerY);

    centerOfMass = new QGraphicsEllipseItem(0, 0, 0, 0, ellipse);
    centerOfMass->setPos(centerX, centerY);
    centerOfMass->setBrush(QBrush(Qt::red));
    centerOfMass->hide();

    ellipse->setTransformOriginPoint(centerX, centerY);

    QPen pen(Qt::red);
    pen.setWidth(2);

    double lineLength = 10;

    line1 = new QGraphicsLineItem(centerX - lineLength / 2, centerY, centerX + lineLength / 2, centerY, ellipse);
    line1->setPen(pen);

    line2 = new QGraphicsLineItem(centerX, centerY - lineLength / 2, centerX, centerY + lineLength / 2, ellipse);
    line2->setPen(pen);

    QPen outlinePen(Qt::black);
    outlinePen.setWidth(1);

    line1->setPen(outlinePen);
    line2->setPen(outlinePen);

    line1->hide();
    line2->hide();
}


QGraphicsEllipseItem* Ellipse::getItem()
{
    return ellipse;
}

QGraphicsEllipseItem* Ellipse::getCenterOfMass()
{
    return centerOfMass;
}

double Ellipse::getArea()
{
    return M_PI * (ewidth / 2) * (eheight / 2);
}

double Ellipse::getPerimeter()
{
    return M_PI * (3*(ewidth + eheight) - sqrt((3*ewidth + eheight) * (ewidth + 3*eheight)));
}

void Ellipse::moveCenterOfMass(double dx, double dy)
{
    ellipse->moveBy(dx, dy);
    centerOfMass->moveBy(dx, dy);
}
