#include "drawfigure.h"
#include <QPen>

DrawnRectangle::DrawnRectangle(QPointF point)
    : QGraphicsRectItem(QRectF(point, QSizeF(0, 0)))
{
    setStartPoint(point);
    setEndPoint(point);

    QPen pen(Qt::red);
    pen.setWidth(2);

    setPen(pen);
}

DrawnRectangle::~DrawnRectangle()
{
}

void DrawnRectangle::setStartPoint(const QPointF point)
{
    m_startPoint = point;
    updateRectangle();
}

void DrawnRectangle::setEndPoint(const QPointF point)
{
    m_endPoint = point;
    updateRectangle();
}

QPointF DrawnRectangle::startPoint() const
{
    return m_startPoint;
}

QPointF DrawnRectangle::endPoint() const
{
    return m_endPoint;
}
