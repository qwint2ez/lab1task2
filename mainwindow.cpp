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
    timerMoveUp = new QTimer(this);
    timerMoveLeft = new QTimer(this);
    timerMoveRight = new QTimer(this);
    timerMoveDown = new QTimer(this);

    connect(timerClockwise, &QTimer::timeout, this, &MainWindow::on_turnclockwise_pressed);
    connect(timerCounterClockwise, &QTimer::timeout, this, &MainWindow::on_turncounterclockwise_pressed);
    connect(timerScaleUp, &QTimer::timeout, this, &MainWindow::on_scaleUpButton_pressed);
    connect(timerScaleDown, &QTimer::timeout, this, &MainWindow::on_scaleDownButton_pressed);
    connect(timerMoveUp, &QTimer::timeout, this, &MainWindow::on_moveup_pressed);
     connect(timerMoveLeft, &QTimer::timeout, this, &MainWindow::on_moveleft_pressed);
      connect(timerMoveRight, &QTimer::timeout, this, &MainWindow::on_moveright_pressed);
       connect(timerMoveDown, &QTimer::timeout, this, &MainWindow::on_movedown_pressed);

    connect(ui->scaleUpButton, &QPushButton::pressed, timerScaleUp, QOverload<>::of(&QTimer::start));
    connect(ui->scaleUpButton, &QPushButton::released, timerScaleUp, &QTimer::stop);
    connect(ui->scaleDownButton, &QPushButton::pressed, timerScaleDown, QOverload<>::of(&QTimer::start));
    connect(ui->scaleDownButton, &QPushButton::released, timerScaleDown, &QTimer::stop);
    connect(ui->moveup, &QPushButton::released, timerMoveUp, &QTimer::stop);
     connect(ui->moveleft, &QPushButton::released, timerMoveLeft, &QTimer::stop);
      connect(ui->moveright, &QPushButton::released, timerMoveRight, &QTimer::stop);
       connect(ui->movedown, &QPushButton::released, timerMoveDown, &QTimer::stop);

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
    width = width * 1.01;
    height = height * 1.01;
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
    width = width / 1.01;
    height = height / 1.01;

}
void MainWindow::on_scaleDownButton_released()
{
    timerScaleDown->stop();
}



void MainWindow::on_moveup_pressed()
{
    timerMoveUp->start(10);
    rect.getRectangle()->moveBy(0, -1);
    rect.getCenterOfMass()->moveBy(0, -1);
}


void MainWindow::on_moveup_released()
{
    timerMoveUp->stop();
}


void MainWindow::on_moveleft_pressed()
{
    timerMoveLeft->start(10);
    rect.getRectangle()->moveBy(-1, 0);
    rect.getCenterOfMass()->moveBy(-1, 0);
}


void MainWindow::on_moveleft_released()
{
timerMoveLeft->stop();
}


void MainWindow::on_moveright_pressed()
{
    timerMoveRight->start(10);
    rect.getRectangle()->moveBy(1, 0);
    rect.getCenterOfMass()->moveBy(1, 0);
}


void MainWindow::on_moveright_released()
{
timerMoveRight->stop();
}


void MainWindow::on_movedown_pressed()
{
    timerMoveDown->start(10);
    rect.getRectangle()->moveBy(0, 1);
    rect.getCenterOfMass()->moveBy(0, 1);
}


void MainWindow::on_movedown_released()
{
timerMoveDown->stop();
}

