#include "square.h"
#include <QBrush>

Square::Square(int sideSquare)
    : sideSquare(sideSquare)
{
    squareItem = new QGraphicsRectItem(0, 0, sideSquare, sideSquare);
    squareItem->setPos(-squareItem->rect().width()/2, -squareItem->rect().height()/2);

    centerOfMass = new QGraphicsEllipseItem(0, 0, 10, 10, squareItem);
    centerOfMass->setPos(sideSquare/2 - 5, sideSquare/2 - 5);
    centerOfMass->setBrush(QBrush(Qt::red));
    centerOfMass->hide();
}

double Square::getArea()
{
    return sideSquare * sideSquare;
}

double Square::getPerimeter()
{
    return 4 * sideSquare;
}

QGraphicsRectItem* Square::getItem()
{
    return squareItem;
}

QGraphicsEllipseItem* Square::getCenterOfMass()
{
    return centerOfMass;
}
