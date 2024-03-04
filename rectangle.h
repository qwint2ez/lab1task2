#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>

class Rectangle : public Shape
{
public:
    Rectangle(int width, int height);

    QGraphicsRectItem* getItem() override;
    QGraphicsEllipseItem* getCenterOfMass() override;
    QGraphicsLineItem* getLine1() override { return nullptr; }
    QGraphicsLineItem* getLine2() override { return nullptr; }
    double getArea() override;
    double getPerimeter() override;
    void setWidth(int newWidth) { width = newWidth; }
    void setHeight(int newHeight) { height = newHeight; }

private:
    QGraphicsRectItem *rectangle;
    QGraphicsEllipseItem *centerOfMass;
    int width;
    int height;
};

#endif // RECTANGLE_H
