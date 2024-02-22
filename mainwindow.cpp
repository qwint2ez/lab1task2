#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , rect(0, 0)
{
    ui->setupUi(this);
    timerClockwise = new QTimer(this);
    timerCounterClockwise = new QTimer(this);
    timerScaleUp = new QTimer(this);
    timerScaleDown = new QTimer(this);

    connect(timerClockwise, &QTimer::timeout, this, &MainWindow::on_turnclockwise_pressed);
    connect(timerCounterClockwise, &QTimer::timeout, this, &MainWindow::on_turncounterclockwise_pressed);
    connect(timerScaleUp, &QTimer::timeout, this, &MainWindow::on_scaleUpButton_pressed);
    connect(timerScaleDown, &QTimer::timeout, this, &MainWindow::on_scaleDownButton_pressed);

    connect(ui->scaleUpButton, &QPushButton::pressed, timerScaleUp, QOverload<>::of(&QTimer::start));
    connect(ui->scaleUpButton, &QPushButton::released, timerScaleUp, &QTimer::stop);
    connect(ui->scaleDownButton, &QPushButton::pressed, timerScaleDown, QOverload<>::of(&QTimer::start));
    connect(ui->scaleDownButton, &QPushButton::released, timerScaleDown, &QTimer::stop);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_rectangle_clicked()
{
    bool ok;
    width = QInputDialog::getInt(this, tr("Введите ширину"),
                                 tr("Ширина:"), 100, 0, 1000, 1, &ok);
    height = QInputDialog::getInt(this, tr("Введите высоту"),
                                  tr("Высота:"), 200, 0, 1000, 1, &ok);

    if (ok) {
        scene = new QGraphicsScene(this);

        rect = Rectangle(width, height);
        QGraphicsRectItem *rectangle = rect.getRectangle();

        rectangle->setTransformOriginPoint(rectangle->boundingRect().center());

        scene->addItem(rectangle);

        ui->graphicsView->setScene(scene);
        ui->graphicsView->centerOn(rectangle);
    }
}

void MainWindow::on_calculate_clicked()
{
    int area = width * height;
    int perimeter = 2 * (width + height);

    QString message = tr("Площадь: ") + QString::number(area) + tr(", Периметр: ") + QString::number(perimeter);
    QMessageBox::information(this, tr("Результаты"), message);

    QGraphicsEllipseItem *centerOfMass = this->rect.getCenterOfMass();
    this->scene->addItem(centerOfMass);
}

void MainWindow::on_turnclockwise_pressed()
{
     timerClockwise->start(10);
    qreal currentRotation = this->rect.getRectangle()->rotation();
    this->rect.getRectangle()->setRotation(currentRotation - 1);
}

void MainWindow::on_turnclockwise_released()
{
    timerClockwise->stop();
}

void MainWindow::on_turncounterclockwise_pressed()
{
    timerCounterClockwise->start(10);
    qreal currentRotation = this->rect.getRectangle()->rotation();
    this->rect.getRectangle()->setRotation(currentRotation + 1);
}

void MainWindow::on_turncounterclockwise_released()
{
    timerCounterClockwise->stop();
}

void MainWindow::on_moveCenterButton_clicked()
{
    bool ok;
    double newX = QInputDialog::getDouble(this, tr("Введите новую координату X центра масс"),
                                          tr("X:"), 0, -1000, 1000, 2, &ok);
    double newY = QInputDialog::getDouble(this, tr("Введите новую координату Y центра масс"),
                                          tr("Y:"), 0, -1000, 1000, 2, &ok);

    if (ok) {
        QPointF oldCenter = rect.getCenterOfMass()->scenePos();
        QPointF delta = QPointF(newX, newY) - oldCenter;

        rect.getRectangle()->moveBy(delta.x(), delta.y());
        rect.getCenterOfMass()->moveBy(delta.x(), delta.y());
    }
}


void MainWindow::on_scaleUpButton_pressed()
{
    timerScaleUp->start(10);
    qreal currentScale = this->rect.getRectangle()->scale();
    this->rect.getRectangle()->setScale(currentScale * 1.01);

    // TYTA YA OBNOVLYAU PLOWADI I TD
    // qreal newArea = this->rect.getRectangle()->area() * 1.01 * 1.01;
    // qreal newPerimeter = this->rect.getRectangle()->perimeter() * 1.01;
    // this->rect.getRectangle()->setArea(newArea);
    // this->rect.getRectangle()->setPerimeter(newPerimeter);
}

void MainWindow::on_scaleUpButton_released()
{
    timerScaleUp->stop();
}

void MainWindow::on_scaleDownButton_pressed()
{
    timerScaleDown->start(10);
    qreal currentScale = this->rect.getRectangle()->scale();
    this->rect.getRectangle()->setScale(currentScale / 1.01);

    // TYTA YA OBNOVLYAU PLOWADI I TD
    // qreal newArea = this->rect.getRectangle()->area() / (1.01 * 1.01);
    // qreal newPerimeter = this->rect.getRectangle()->perimeter() / 1.01;
    // this->rect.getRectangle()->setArea(newArea);
    // this->rect.getRectangle()->setPerimeter(newPerimeter);
}
void MainWindow::on_scaleDownButton_released()
{
    timerScaleDown->stop();
}


