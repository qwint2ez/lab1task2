#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"
#include <QGraphicsPolygonItem>
#include <QPainter>

class Triangle : public Shape
{
public:
    Triangle(int side);

    QRectF boundingRect() const override
    {
        return QRectF(-side/2, -sqrt(3)*side/2, side, sqrt(3)*side);
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override
    {
        painter->drawPolygon(triangle->polygon());
    }

    QGraphicsPolygonItem* getItem() override;
    QGraphicsEllipseItem* getCenterOfMass() override;
    QGraphicsLineItem* getLine1() override { return line1; }
    QGraphicsLineItem* getLine2() override { return line2; }
    double getArea() override;
    double getPerimeter() override;
    void moveCenterOfMass(double dx, double dy);
    void scale(double factor);
    void setSide(int newSide) { side = newSide; }

private:
    QGraphicsPolygonItem *triangle;
    QGraphicsEllipseItem *centerOfMass;
    QGraphicsLineItem *line1;
    QGraphicsLineItem *line2;
    int side;
};

#endif // TRIANGLE_H
