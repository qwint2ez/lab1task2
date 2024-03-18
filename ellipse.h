#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "shape.h"
#include <QGraphicsEllipseItem>
#include <QPainter>

class Ellipse : public Shape
{
public:
    Ellipse(int ewidth, int eheight);

    QRectF boundingRect() const override
    {
        return QRectF(-ewidth/2, -eheight/2, ewidth, eheight);
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override
    {
        painter->drawEllipse(boundingRect());
    }

    QGraphicsEllipseItem* getItem() override;
    QGraphicsEllipseItem* getCenterOfMass() override;
    QGraphicsLineItem* getLine1() override { return line1; }
    QGraphicsLineItem* getLine2() override { return line2; }
    int getEWidth() const { return ewidth; }
    int getEHeight() const { return eheight; }
    double getArea() override;
    double getPerimeter() override;
    void moveCenterOfMass(double dx, double dy);
    void scale(double factor);
    void setEWidth(int newEWidth) { ewidth = newEWidth; }
    void setEHeight(int newEHeight) { eheight = newEHeight; }

private:
    QGraphicsEllipseItem *ellipse;
    QGraphicsEllipseItem *centerOfMass;
    QGraphicsLineItem *line1;
    QGraphicsLineItem *line2;
    int ewidth;
    int eheight;
};

#endif // ELLIPSE_H
