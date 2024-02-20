#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "rectangle.h"
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_rectangle_clicked()
{
    bool ok;
    int width = QInputDialog::getInt(this, tr("Введите ширину"),
                                     tr("Ширина:"), 100, 0, 1000, 1, &ok);
    int height = QInputDialog::getInt(this, tr("Введите высоту"),
                                      tr("Высота:"), 200, 0, 1000, 1, &ok);

    if (ok) {
        QGraphicsScene *scene = new QGraphicsScene(this);

        Rectangle rect(width, height);
        QGraphicsRectItem *rectangle = rect.getRectangle();

        scene->addItem(rectangle);

        ui->graphicsView->setScene(scene);
        ui->graphicsView->centerOn(rectangle);
    }
}
