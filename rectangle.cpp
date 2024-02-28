#include "rectangle.h"
#include <QBrush>

Rectangle::Rectangle(int width, int height)
    : width(width), height(height)
{
    rectangle = new QGraphicsRectItem(0, 0, width, height);
    rectangle->setPos(-rectangle->rect().width()/2, -rectangle->rect().height()/2);
    centerOfMass = new QGraphicsEllipseItem(0, 0, 10, 10);
    centerOfMass->setPos(-5, -5);
    centerOfMass->setBrush(QBrush(Qt::red));
}

QGraphicsRectItem* Rectangle::getItem()
{
    return rectangle;
}

QGraphicsEllipseItem* Rectangle::getCenterOfMass()
{
    return centerOfMass;
}

double Rectangle::getArea()
{
    return width * height;
}

double Rectangle::getPerimeter()
{
    return 2 * (width + height);
}
