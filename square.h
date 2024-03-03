#ifndef SQUARE_H
#define SQUARE_H

#include "shape.h"
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>

class Square : public Shape
{
public:
    Square(int sideSquare);

    QGraphicsRectItem* getItem() override;
    QGraphicsEllipseItem* getCenterOfMass() override;
    double getArea() override;
    double getPerimeter() override;
    void setSideSquare(int newSideSquare) { sideSquare = newSideSquare; }

private:
    QGraphicsRectItem *squareItem;
    QGraphicsEllipseItem *centerOfMass;
    int sideSquare;
};

#endif // SQUARE_H
