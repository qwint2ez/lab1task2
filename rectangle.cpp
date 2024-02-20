#include "rectangle.h"

Rectangle::Rectangle(int width, int height)
{
    rectangle = new QGraphicsRectItem(0, 0, width, height);
    rectangle->setPos(-rectangle->rect().width()/2, -rectangle->rect().height()/2);
}

QGraphicsRectItem* Rectangle::getRectangle()
{
    return rectangle;
}
