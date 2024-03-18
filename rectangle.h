#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QPainter>

class Rectangle : public Shape
{
public:
    Rectangle(int width, int height);

    QRectF boundingRect() const override
    {
        return QRectF(-width/2, -height/2, width, height);
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override
    {
        painter->drawRect(rectangle->rect());
    }

    QGraphicsRectItem* getItem() override;
    QGraphicsEllipseItem* getCenterOfMass() override;
    QGraphicsLineItem* getLine1() override { return line1; }
    QGraphicsLineItem* getLine2() override { return line2; }
    double getArea() override;
    double getPerimeter() override;
    void setWidth(int newWidth) { width = newWidth; }
    void setHeight(int newHeight) { height = newHeight; }

private:
    QGraphicsRectItem *rectangle;
    QGraphicsEllipseItem *centerOfMass;
    QGraphicsLineItem *line1;
    QGraphicsLineItem *line2;
    int width;
    int height;
};

#endif // RECTANGLE_H
