#ifndef HEXAGON_H
#define HEXAGON_H

#include "shape.h"
#include <QGraphicsPolygonItem>
#include <QGraphicsEllipseItem>
#include <QPainter>

class Hexagon : public Shape
{
public:
    Hexagon(int sideHexagon);

    QRectF boundingRect() const override
    {
        return QRectF(-sideHexagon, -sideHexagon, 2*sideHexagon, 2*sideHexagon);
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override
    {
        painter->drawPolygon(hexagon->polygon());
    }

    QGraphicsPolygonItem* getItem() override;
    QGraphicsEllipseItem* getCenterOfMass() override;
    QGraphicsLineItem* getLine1() override { return line1; }
    QGraphicsLineItem* getLine2() override { return line2; }
    double getArea() override;
    double getPerimeter() override;
    void moveCenterOfMass(double dx, double dy);
    void scale(double factor);
    void setSideHexagon(int newSideHexagon) { sideHexagon = newSideHexagon; }

private:
    QGraphicsPolygonItem *hexagon;
    QGraphicsEllipseItem *centerOfMass;
    QGraphicsLineItem *line1;
    QGraphicsLineItem *line2;
    int sideHexagon;
};

#endif // HEXAGON_H
