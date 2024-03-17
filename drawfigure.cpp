#include "drawfigure.h"
#include <QBrush>
#include <QPen>
#include <cmath>

DrawnRectangle::DrawnRectangle(int width, int height)
    : width(width), height(height)
{
    rectangle = new QGraphicsRectItem(0, 0, width, height);
    rectangle->setPos(-rectangle->rect().width()/2, -rectangle->rect().height()/2);

    QPen pen(Qt::red);
    pen.setWidth(2);

    rectangle->setPen(pen);
}

QGraphicsRectItem* DrawnRectangle::getItem()
{
    return rectangle;
}
