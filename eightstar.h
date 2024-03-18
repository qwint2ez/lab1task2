#ifndef EIGHTSTAR_H
#define EIGHTSTAR_H

#include "shape.h"
#include <QGraphicsPolygonItem>
#include <QGraphicsEllipseItem>
#include <QPainter>

class EightStar : public Shape
{
public:
    EightStar(int eradius);

    QRectF boundingRect() const override
    {
        return QRectF(-eradius, -eradius, 2*eradius, 2*eradius);
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override
    {
        painter->drawPolygon(estar->polygon());
    }

    QGraphicsPolygonItem* getItem() override;
    QGraphicsEllipseItem* getCenterOfMass() override;
    QGraphicsLineItem* getLine1() override { return line1; }
    QGraphicsLineItem* getLine2() override { return line2; }
    int getERadius() const { return eradius; }
    double getArea() override;
    double getPerimeter() override;
    void moveCenterOfMass(double dx, double dy);
    void scale(double factor);
    void setERadius(int newERadius) { eradius = newERadius; }

private:
    QGraphicsPolygonItem *estar;
    QGraphicsEllipseItem *centerOfMass;
    QGraphicsLineItem *line1;
    QGraphicsLineItem *line2;
    int eradius;
};

#endif // EIGHTSTAR_H
