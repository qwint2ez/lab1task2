#ifndef SIXSTAR_H
#define SIXSTAR_H

#include "shape.h"
#include <QGraphicsPolygonItem>
#include <QGraphicsEllipseItem>
#include <QPainter>

class SixStar : public Shape
{
public:
    SixStar(int sradius);

    QRectF boundingRect() const override
    {
        return QRectF(-sradius, -sradius, 2*sradius, 2*sradius);
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override
    {
        painter->drawPolygon(sstar->polygon());
    }

    QGraphicsPolygonItem* getItem() override;
    QGraphicsEllipseItem* getCenterOfMass() override;
    QGraphicsLineItem* getLine1() override { return line1; }
    QGraphicsLineItem* getLine2() override { return line2; }
    int getSRadius() const { return sradius; }
    double getArea() override;
    double getPerimeter() override;
    void moveCenterOfMass(double dx, double dy);
    void scale(double factor);
    void setSRadius(int newSRadius) { sradius = newSRadius; }

private:
    QGraphicsPolygonItem *sstar;
    QGraphicsEllipseItem *centerOfMass;
    QGraphicsLineItem *line1;
    QGraphicsLineItem *line2;
    int sradius;
};

#endif // SIXSTAR_H
