#ifndef FIVESTAR_H
#define FIVESTAR_H

#include "shape.h"
#include <QGraphicsPolygonItem>
#include <QGraphicsEllipseItem>
#include <QPainter>

class FiveStar : public Shape
{
public:
    FiveStar(int fradius);

    QRectF boundingRect() const override
    {
        return QRectF(-fradius, -fradius, 2*fradius, 2*fradius);
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override
    {
        painter->drawPolygon(fstar->polygon());
    }

    QGraphicsPolygonItem* getItem() override;
    QGraphicsEllipseItem* getCenterOfMass() override;
    QGraphicsLineItem* getLine1() override { return line1; }
    QGraphicsLineItem* getLine2() override { return line2; }
    int getFRadius() const { return fradius; }
    double getArea() override;
    double getPerimeter() override;
    void moveCenterOfMass(double dx, double dy);
    void scale(double factor);
    void setFRadius(int newFRadius) { fradius = newFRadius; }

private:
    QGraphicsPolygonItem *fstar;
    QGraphicsEllipseItem *centerOfMass;
    QGraphicsLineItem *line1;
    QGraphicsLineItem *line2;
    int fradius;
};

#endif // FIVESTAR_H
