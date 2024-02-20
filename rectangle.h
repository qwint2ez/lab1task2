#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QGraphicsRectItem>

class Rectangle
{
public:
    Rectangle(int width, int height);

    QGraphicsRectItem* getRectangle();

private:
    QGraphicsRectItem *rectangle;
};

#endif // RECTANGLE_H
