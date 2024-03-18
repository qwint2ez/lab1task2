#ifndef DRAWFIGURE_H
#define DRAWFIGURE_H

#include <QGraphicsRectItem>

class DrawnRectangle : public QGraphicsRectItem
{
public:
    DrawnRectangle(QPointF point);
    ~DrawnRectangle();

    void setStartPoint(const QPointF point);
    void setEndPoint(const QPointF point);

    QPointF startPoint() const;
    QPointF endPoint() const;

private:
    QPointF m_startPoint;
    QPointF m_endPoint;

    void updateRectangle();
};

#endif // DRAWFIGURE_H
