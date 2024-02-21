#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>
#include <QGraphicsRectItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_mousePressed(false)
    , rectangle(nullptr)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(new QGraphicsScene(this));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_rectangle_clicked()
{
    m_mousePressed = true;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (m_mousePressed) {
        m_origin = event->pos();
        rectangle = new QGraphicsRectItem(QRect(m_origin, QSize()));
        ui->graphicsView->scene()->addItem(rectangle);
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (m_mousePressed) {
        QRect rect(m_origin, event->pos());
        rectangle->setRect(rect.normalized());
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    m_mousePressed = false;
}
