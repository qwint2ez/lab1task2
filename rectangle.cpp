#include "rectangle.h"
#include <QBrush>

Rectangle::Rectangle(int width, int height)
{
    rectangle = new QGraphicsRectItem(0, 0, width, height);
    rectangle->setPos(-rectangle->rect().width()/2, -rectangle->rect().height()/2);
    centerOfMass = new QGraphicsEllipseItem(0, 0, 10, 10);
    centerOfMass->setPos(-5, -5);
    centerOfMass->setBrush(QBrush(Qt::red));
}

QGraphicsRectItem* Rectangle::getRectangle()
{
    return rectangle;
}

QGraphicsEllipseItem* Rectangle::getCenterOfMass()
{
    return centerOfMass;
}

void Rectangle::moveCenterOfMass(double dx, double dy)
{
    rectangle->moveBy(dx, dy);
    centerOfMass->moveBy(dx, dy);
}

void Rectangle::scale(double factor)
{
    rectangle->setScale(rectangle->scale() * factor);
    centerOfMass->setScale(centerOfMass->scale() * factor);
}
