#ifndef DRAWFIGURE_H
#define DRAWFIGURE_H

#include <QGraphicsRectItem>

class DrawnRectangle
{
public:
    DrawnRectangle(int width, int height);

    QGraphicsRectItem* getItem();
    double getWidth() { return width; }
    double getHeight() { return height; }
    double getDiagonal() { return sqrt(width * width + height * height); }

private:
    QGraphicsRectItem *rectangle;
    int width;
    int height;
};

#endif // DRAWFIGURE_H
