#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <QTimer> // Добавьте эту строку

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) //i hope it works
    , ui(new Ui::MainWindow)
    , rect(0, 0)
{
    ui->setupUi(this);
    timerClockwise = new QTimer(this);
    timerCounterClockwise = new QTimer(this);
    connect(timerClockwise, &QTimer::timeout, this, &MainWindow::on_turnclockwise_pressed);
    connect(timerCounterClockwise, &QTimer::timeout, this, &MainWindow::on_turncounterclockwise_pressed);
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
