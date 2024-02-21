#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QGraphicsRectItem> //i hope it works

class MyGraphicsView : public QGraphicsView
{
    Q_OBJECT

public:
    MyGraphicsView(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    QPoint m_origin;
    bool m_mousePressed;
    QGraphicsRectItem *rectangle;
};

#endif // MYGRAPHICSVIEW_H
