#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , rect(new Rectangle (0, 0))
    , cir(new Circle(0))
    , rhom(new Rhombus(0, 0))
    , square(new Square (0))
    , hex(new Hexagon (0))
    , fstar(new FiveStar (0))
    , sstar(new SixStar (0))
    , estar(new EightStar (0))
    , ell(new Ellipse(0, 0))
    , drawnRect(nullptr)
{
    ui->setupUi(this);
    this->setMinimumSize(760, 600);

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

      xLabel = ui->xLabel;
      yLabel = ui->yLabel;

}


MainWindow::~MainWindow()
{
    delete rect;
    delete tri;
    delete cir;
    delete rhom;
    delete square;
    delete hex;
    delete fstar;
    delete sstar;
    delete estar;
    delete ell;
    delete ui;
    delete drawnRect;
}

bool check = false;

void MainWindow::on_drawbutton_clicked()
{
    isDrawingEnabled = true;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (isDrawingEnabled) {
        startPoint = event->pos();
        endPoint = startPoint;
        if (drawnRectangle != nullptr) {
            scene->removeItem(drawnRectangle);
            delete drawnRectangle;
            drawnRectangle = nullptr;
        }
        drawnRectangle = scene->addRect(QRect(startPoint, endPoint));
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (isDrawingEnabled && drawnRectangle != nullptr) {
        endPoint = event->pos();
        scene->removeItem(drawnRectangle);
        drawnRectangle = scene->addRect(QRect(startPoint, endPoint));
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if (isDrawingEnabled) {
        endPoint = event->pos();
        scene->removeItem(drawnRectangle);
        drawnRectangle = scene->addRect(QRect(startPoint, endPoint));
        if (drawnRect != nullptr) {
            scene->removeItem(drawnRect->getItem());
            delete drawnRect;
            drawnRect = nullptr;
        }
        drawnRect = new DrawnRectangle(abs(endPoint.x() - startPoint.x()), abs(endPoint.y() - startPoint.y()));
        scene->addItem(drawnRect->getItem());
        isDrawingEnabled = false;
    }
}

void MainWindow::on_rectangle_clicked()
{
    bool ok;
    if (drawnRect != nullptr) {
        width = QInputDialog::getInt(this, tr("Введите ширину"),
                                     tr("Ширина:"), drawnRect->getWidth(), 0, 1000, 1, &ok);
        height = QInputDialog::getInt(this, tr("Введите высоту"),
                                      tr("Высота:"), drawnRect->getHeight(), 0, 1000, 1, &ok);
    } else {
        width = QInputDialog::getInt(this, tr("Введите ширину"),
                                     tr("Ширина:"), 100, 0, 1000, 1, &ok);
        height = QInputDialog::getInt(this, tr("Введите высоту"),
                                      tr("Высота:"), 200, 0, 1000, 1, &ok);
    }

    if (ok) {
        rect = new Rectangle(width, height);
        currentShape = rect;
        check = true;

        scene = new QGraphicsScene(this);

        QGraphicsRectItem *rectangle = rect->getItem();

        rectangle->setTransformOriginPoint(rectangle->boundingRect().center());

        scene->addItem(rectangle);

        ui->graphicsView->setScene(scene);
        ui->graphicsView->centerOn(rectangle);

        QPointF center = rect->getCenterOfMass()->scenePos();

        xLabel->setText(tr("X: ") + QString::number(qRound(center.x())));
        yLabel->setText(tr("Y: ") + QString::number(qRound(center.y())));
    }
}

void MainWindow::on_triangle_clicked()
{
    bool ok;
    side = QInputDialog::getInt(this, tr("Введите сторону"),
                                tr("Сторона:"), 100, 0, 1000, 1, &ok);

    if (ok) {
        tri = new Triangle(side);
        currentShape = tri;
        check = true;

        scene = new QGraphicsScene(this);

        QGraphicsPolygonItem *triangle = tri->getItem();

        triangle->setTransformOriginPoint(triangle->boundingRect().center());

        scene->addItem(triangle);

        ui->graphicsView->setScene(scene);
        ui->graphicsView->centerOn(triangle);

        QPointF center = tri->getCenterOfMass()->scenePos();

        xLabel->setText(tr("X: ") + QString::number(qRound(center.x())));
        yLabel->setText(tr("Y: ") + QString::number(qRound(center.y())));
    }
}


void MainWindow::on_rhombus_clicked()
{
    bool ok;
    int diagonal1 = QInputDialog::getInt(this, tr("Введите первую диагональ"),
                                         tr("Диагональ 1:"), 100, 0, 1000, 1, &ok);
    int diagonal2 = QInputDialog::getInt(this, tr("Введите вторую диагональ"),
                                         tr("Диагональ 2:"), 100, 0, 1000, 1, &ok);

    if (ok) {
        Rhombus* rhom = new Rhombus(diagonal1, diagonal2);
        currentShape = rhom;
        check = true;

        scene = new QGraphicsScene(this);

        QGraphicsPolygonItem* rhombus = rhom->getItem();

        rhombus->setTransformOriginPoint(rhombus->boundingRect().center());

        scene->addItem(rhombus);

        ui->graphicsView->setScene(scene);
        ui->graphicsView->centerOn(rhombus);

        QPointF center = rhom->getCenterOfMass()->scenePos();

        xLabel->setText(tr("X: ") + QString::number(qRound(center.x())));
        yLabel->setText(tr("Y: ") + QString::number(qRound(center.y())));
    }
}



void MainWindow::on_circle_clicked()
{
    bool ok;
    diameter = QInputDialog::getInt(this, tr("Введите диаметр"),
                                    tr("Диаметр:"), 100, 0, 1000, 1, &ok);

    if (ok) {
        Circle* cir = new Circle(diameter);
        currentShape = cir;
        check = true;

        scene = new QGraphicsScene(this);

        QGraphicsEllipseItem* circle = cir->getItem();

        circle->setTransformOriginPoint(circle->boundingRect().center());

        scene->addItem(circle);

        ui->graphicsView->setScene(scene);
        ui->graphicsView->centerOn(circle);

        QPointF center = cir->getCenterOfMass()->scenePos();

        xLabel->setText(tr("X: ") + QString::number(qRound(center.x())));
        yLabel->setText(tr("Y: ") + QString::number(qRound(center.y())));
    }
}

void MainWindow::on_square_clicked()
{
    bool ok;
    sideSquare = QInputDialog::getInt(this, tr("Введите сторону"),
                                      tr("Сторона:"), 100, 0, 1000, 1, &ok);

    if (ok) {
        delete square; // удалите старый объект Square
        square = new Square(sideSquare);
        currentShape = square;
        check = true;

        scene = new QGraphicsScene(this);

        QGraphicsRectItem *squareItem = square->getItem();

        squareItem->setTransformOriginPoint(squareItem->boundingRect().center());

        scene->addItem(squareItem);

        ui->graphicsView->setScene(scene);
        ui->graphicsView->centerOn(squareItem);

        QPointF center = square->getCenterOfMass()->scenePos();

        xLabel->setText(tr("X: ") + QString::number(qRound(center.x())));
        yLabel->setText(tr("Y: ") + QString::number(qRound(center.y())));

        scene->update();
    }
}

void MainWindow::on_hexagon_clicked()
{
    bool ok;
    sideHexagon = QInputDialog::getInt(this, tr("Введите сторону"),
                                tr("Сторона:"), 100, 0, 1000, 1, &ok);

    if (ok) {
        Hexagon *hex = new Hexagon(sideHexagon);
        currentShape = hex;
        check = true;

        scene = new QGraphicsScene(this);

        QGraphicsPolygonItem *hexagon = hex->getItem();

        hexagon->setTransformOriginPoint(hexagon->boundingRect().center());

        scene->addItem(hexagon);

        ui->graphicsView->setScene(scene);
        ui->graphicsView->centerOn(hexagon);

        QPointF center = hex->getCenterOfMass()->scenePos();

        xLabel->setText(tr("X: ") + QString::number(qRound(center.x())));
        yLabel->setText(tr("Y: ") + QString::number(qRound(center.y())));
    }
}

void MainWindow::on_fivestar_clicked()
{
    bool ok;
    int radius = QInputDialog::getInt(this, tr("Введите радиус"),
                                      tr("Радиус:"), 100, 0, 1000, 1, &ok);

    if (ok) {
        FiveStar *fstar = new FiveStar(radius);
        currentShape = fstar;
        check = true;

        scene = new QGraphicsScene(this);

        QGraphicsPolygonItem *fivestar = fstar->getItem();

        fivestar->setTransformOriginPoint(fivestar->boundingRect().center());

        scene->addItem(fivestar);

        ui->graphicsView->setScene(scene);
        ui->graphicsView->centerOn(fivestar);

        QPointF center = fstar->getCenterOfMass()->scenePos();

        xLabel->setText(tr("X: ") + QString::number(qRound(center.x())));
        yLabel->setText(tr("Y: ") + QString::number(qRound(center.y())));
    }
}

void MainWindow::on_sixstar_clicked()
{
    bool ok;
    int radius = QInputDialog::getInt(this, tr("Введите радиус"),
                                      tr("Радиус:"), 100, 0, 1000, 1, &ok);

    if (ok) {
        SixStar *sstar = new SixStar(radius);
        currentShape = sstar;
        check = true;

        scene = new QGraphicsScene(this);

        QGraphicsPolygonItem *sixstar = sstar->getItem();

        sixstar->setTransformOriginPoint(sixstar->boundingRect().center());

        scene->addItem(sixstar);

        ui->graphicsView->setScene(scene);
        ui->graphicsView->centerOn(sixstar);

        QPointF center = sstar->getCenterOfMass()->scenePos();

        xLabel->setText(tr("X: ") + QString::number(qRound(center.x())));
        yLabel->setText(tr("Y: ") + QString::number(qRound(center.y())));
    }
}

void MainWindow::on_eightstar_clicked()
{
    bool ok;
    int radius = QInputDialog::getInt(this, tr("Введите радиус"),
                                      tr("Радиус:"), 100, 0, 1000, 1, &ok);

    if (ok) {
        EightStar *estar = new EightStar(radius);
        currentShape = estar;
        check = true;

        scene = new QGraphicsScene(this);

        QGraphicsPolygonItem *eightstar = estar->getItem();

        eightstar->setTransformOriginPoint(eightstar->boundingRect().center());

        scene->addItem(eightstar);

        ui->graphicsView->setScene(scene);
        ui->graphicsView->centerOn(eightstar);

        QPointF center = estar->getCenterOfMass()->scenePos();

        xLabel->setText(tr("X: ") + QString::number(qRound(center.x())));
        yLabel->setText(tr("Y: ") + QString::number(qRound(center.y())));
    }
}

void MainWindow::on_ellipse_clicked()
{
    bool ok;
    int ewidth = QInputDialog::getInt(this, tr("Введите ширину"),
                                     tr("Ширина:"), 100, 0, 1000, 1, &ok);
    int eheight = QInputDialog::getInt(this, tr("Введите высоту"),
                                      tr("Высота:"), 100, 0, 1000, 1, &ok);

    if (ok) {
        Ellipse* ell = new Ellipse(ewidth, eheight);
        currentShape = ell;
        check = true;

        scene = new QGraphicsScene(this);

        QGraphicsEllipseItem* ellipse = ell->getItem();

        ellipse->setTransformOriginPoint(ellipse->boundingRect().center());

        scene->addItem(ellipse);

        ui->graphicsView->setScene(scene);
        ui->graphicsView->centerOn(ellipse);

        QPointF center = ell->getCenterOfMass()->scenePos();

        xLabel->setText(tr("X: ") + QString::number(qRound(center.x())));
        yLabel->setText(tr("Y: ") + QString::number(qRound(center.y())));
    }
}

void MainWindow::on_calculate_clicked()
{
    if (!check) {
        QMessageBox::information(this, tr("Ошибка"), tr("Сначала создайте фигуру!"));
        return;
    }

    double area = currentShape->getArea();
    double perimeter = currentShape->getPerimeter();

    QString message = tr("Площадь: ") + QString::number(area) + tr(", Периметр: ") + QString::number(perimeter);
    QMessageBox::information(this, tr("Результаты"), message);

    QGraphicsEllipseItem *centerOfMass = currentShape->getCenterOfMass();
    centerOfMass->show();

    QGraphicsLineItem *line1 = currentShape->getLine1();
    if (line1 != nullptr) {
        line1->show();
    }

    QGraphicsLineItem *line2 = currentShape->getLine2();
    if (line2 != nullptr) {
        line2->show();
    }

    QPointF center = currentShape->getCenterOfMass()->scenePos();

    xLabel->setText(tr("X: ") + QString::number(qRound(center.x())));
    yLabel->setText(tr("Y: ") + QString::number(qRound(center.y())));
}



void MainWindow::on_turnclockwise_pressed()
{
    if (!check) {
        QMessageBox::information(this, tr("Ошибка"), tr("Сначала создайте фигуру!"));
        return;
    }
    timerClockwise->start(10);
    qreal currentRotation = this->currentShape->getItem()->rotation();
    this->currentShape->getItem()->setRotation(currentRotation - 1);
   // this->currentShape->getCenterOfMass()->setPos(this->currentShape->getItem()->boundingRect().center());
}

void MainWindow::on_turnclockwise_released()
{
    timerClockwise->stop();
}

void MainWindow::on_turncounterclockwise_pressed()
{
    if (!check) {
        QMessageBox::information(this, tr("Ошибка"), tr("Сначала создайте фигуру!"));
        return;
    }
    timerCounterClockwise->start(10);
    qreal currentRotation = this->currentShape->getItem()->rotation();
    this->currentShape->getItem()->setRotation(currentRotation + 1);
  //  this->currentShape->getCenterOfMass()->setPos(this->currentShape->getItem()->boundingRect().center());
}

void MainWindow::on_turncounterclockwise_released()
{
    timerCounterClockwise->stop();
}


void MainWindow::on_moveCenterButton_clicked()
{
    if (!check) {
        QMessageBox::information(this, tr("Ошибка"), tr("Сначала создайте фигуру!"));
        return;
    }
    bool ok;
    double newX = QInputDialog::getDouble(this, tr("Введите новую координату X центра масс"),
                                          tr("X:"), 0, -1000, 1000, 2, &ok);
    double newY = QInputDialog::getDouble(this, tr("Введите новую координату Y центра масс"),
                                          tr("Y:"), 0, -1000, 1000, 2, &ok);

    if (ok) {
        QPointF oldCenter = currentShape->getCenterOfMass()->scenePos();
        QPointF delta = QPointF(newX, newY) - oldCenter;

        currentShape->getItem()->moveBy(delta.x(), delta.y());

        QPointF center = currentShape->getCenterOfMass()->scenePos();

        xLabel->setText(tr("X: ") + QString::number(qRound(center.x())));
        yLabel->setText(tr("Y: ") + QString::number(qRound(center.y())));
    }
}

void MainWindow::on_scaleUpButton_pressed()
{
    if (!check) {
        QMessageBox::information(this, tr("Ошибка"), tr("Сначала создайте фигуру!"));
        return;
    }
    timerScaleUp->start(10);
    qreal currentScale = this->currentShape->getItem()->scale();
    this->currentShape->getItem()->setScale(currentScale * 1.01);

    if (Rectangle* rect = dynamic_cast<Rectangle*>(currentShape)) {
        width = width * 1.01;
        height = height * 1.01;
        rect->setWidth(width);
        rect->setHeight(height);
    } else if (Triangle* tri = dynamic_cast<Triangle*>(currentShape)) {
        side = side * 1.01;
        tri->setSide(side);
    } else if (Circle* cir = dynamic_cast<Circle*>(currentShape)) {
        diameter = diameter * 1.01;
        cir->setDiameter(diameter);
    } else if (Rhombus* rhom = dynamic_cast<Rhombus*>(currentShape)) {
        int diagonal1 = rhom->getDiagonal1() * 1.01;
        int diagonal2 = rhom->getDiagonal2() * 1.01;
        rhom->setDiagonals(diagonal1, diagonal2);
    }
    else if (Square* square = dynamic_cast<Square*>(currentShape)) {
        sideSquare = sideSquare * 1.01;
        square->setSideSquare(sideSquare);
    }
    else if (Hexagon* hex = dynamic_cast<Hexagon*>(currentShape)) {
        sideHexagon = sideHexagon * 1.01;
        hex->setSideHexagon(sideHexagon);
    }
    else if (FiveStar* fstar = dynamic_cast<FiveStar*>(currentShape)) {
        int newFRadius = fstar->getFRadius() * 1.01;
        fstar->setFRadius(newFRadius);
    }
    else if (SixStar* sstar = dynamic_cast<SixStar*>(currentShape)) {
        int newSRadius = sstar->getSRadius() * 1.01;
        sstar->setSRadius(newSRadius);
    }
    else if (EightStar* estar = dynamic_cast<EightStar*>(currentShape)) {
        int newERadius = estar->getERadius() * 1.01;
        estar->setERadius(newERadius);
    }
    else if (Ellipse* ell = dynamic_cast<Ellipse*>(currentShape)){
            int newEWidth = ell->getEWidth() * 1.01;
            int newEHeight = ell->getEHeight() * 1.01;
            ell->setEWidth(newEWidth);
            ell->setEHeight(newEHeight);
    }
}

void MainWindow::on_scaleUpButton_released()
{
    timerScaleUp->stop();
}

void MainWindow::on_scaleDownButton_pressed()
{
    if (!check) {
        QMessageBox::information(this, tr("Ошибка"), tr("Сначала создайте фигуру!"));
        return;
    }
    timerScaleDown->start(10);
    qreal currentScale = this->currentShape->getItem()->scale();
    this->currentShape->getItem()->setScale(currentScale / 1.01);
    if (Rectangle* rect = dynamic_cast<Rectangle*>(currentShape)) {
        width = width / 1.01;
        height = height / 1.01;
        rect->setWidth(width);
        rect->setHeight(height);
    } else if (Triangle* tri = dynamic_cast<Triangle*>(currentShape)) {
        side = side / 1.01;
        tri->setSide(side);
    } else if (Circle* cir = dynamic_cast<Circle*>(currentShape)) {
        diameter = diameter / 1.01;
        cir->setDiameter(diameter);
    } else if (Rhombus* rhom = dynamic_cast<Rhombus*>(currentShape)) {
        int diagonal1 = rhom->getDiagonal1() / 1.01;
        int diagonal2 = rhom->getDiagonal2() / 1.01;
        rhom->setDiagonals(diagonal1, diagonal2);
    }
    else if (Square* square = dynamic_cast<Square*>(currentShape)) {
        sideSquare = sideSquare / 1.01;
        square->setSideSquare(sideSquare);
    }
    else if (Hexagon* hex = dynamic_cast<Hexagon*>(currentShape)) {
        sideHexagon = sideHexagon / 1.01;
        hex->setSideHexagon(sideHexagon);
    }
    else if (FiveStar* fstar = dynamic_cast<FiveStar*>(currentShape)) {
        int newFRadius = fstar->getFRadius() / 1.01;
        fstar->setFRadius(newFRadius);
    }
    else if (SixStar* sstar = dynamic_cast<SixStar*>(currentShape)) {
        int newSRadius = sstar->getSRadius() / 1.01;
        sstar->setSRadius(newSRadius);
    }
    else if (EightStar* estar = dynamic_cast<EightStar*>(currentShape)) {
        int newERadius = estar->getERadius() / 1.01;
        estar->setERadius(newERadius);
    }
    else if (Ellipse* ell = dynamic_cast<Ellipse*>(currentShape)){
        int newEWidth = ell->getEWidth() / 1.01;
        int newEHeight = ell->getEHeight() / 1.01;
        ell->setEWidth(newEWidth);
        ell->setEHeight(newEHeight);
    }
}


void MainWindow::on_scaleDownButton_released()
{
    timerScaleDown->stop();
}



void MainWindow::on_moveup_pressed()
{
    if (!check) {
        QMessageBox::information(this, tr("Ошибка"), tr("Сначала создайте фигуру!"));
        return;
    }
    timerMoveUp->start(10);
    currentShape->getItem()->moveBy(0, -1);

    QPointF center = currentShape->getCenterOfMass()->scenePos();

    xLabel->setText(tr("X: ") + QString::number(qRound(center.x())));
    yLabel->setText(tr("Y: ") + QString::number(qRound(center.y())));
}


void MainWindow::on_moveup_released()
{
    timerMoveUp->stop();
}


void MainWindow::on_moveleft_pressed()
{
    if (!check) {
        QMessageBox::information(this, tr("Ошибка"), tr("Сначала создайте фигуру!"));
        return;
    }
    timerMoveLeft->start(10);
    currentShape->getItem()->moveBy(-1, 0);

    QPointF center = currentShape->getCenterOfMass()->scenePos();

    xLabel->setText(tr("X: ") + QString::number(qRound(center.x())));
    yLabel->setText(tr("Y: ") + QString::number(qRound(center.y())));
}


void MainWindow::on_moveleft_released()
{
timerMoveLeft->stop();
}


void MainWindow::on_moveright_pressed()
{
    if (!check) {
        QMessageBox::information(this, tr("Ошибка"), tr("Сначала создайте фигуру!"));
        return;
    }
    timerMoveRight->start(10);
    currentShape->getItem()->moveBy(1, 0);

    QPointF center = currentShape->getCenterOfMass()->scenePos();

    xLabel->setText(tr("X: ") + QString::number(qRound(center.x())));
    yLabel->setText(tr("Y: ") + QString::number(qRound(center.y())));

}


void MainWindow::on_moveright_released()
{
timerMoveRight->stop();
}


void MainWindow::on_movedown_pressed()
{
    if (!check) {
        QMessageBox::information(this, tr("Ошибка"), tr("Сначала создайте фигуру!"));
        return;
    }
    timerMoveDown->start(10);
    currentShape->getItem()->moveBy(0, 1);

    QPointF center = currentShape->getCenterOfMass()->scenePos();

    xLabel->setText(tr("X: ") + QString::number(qRound(center.x())));
    yLabel->setText(tr("Y: ") + QString::number(qRound(center.y())));

}


void MainWindow::on_movedown_released()
{
timerMoveDown->stop();
}



void MainWindow::on_pushButton_clicked()
{
    if (!check) {
        QMessageBox::information(this, tr("Ошибка"), tr("Сначала создайте фигуру!"));
        return;
    }
    if (currentShape != nullptr) {
        QGraphicsItem* item = currentShape->getItem();
        ui->graphicsView->centerOn(item);
    }
}



void MainWindow::on_pushButton_2_clicked()
{
        scene->clear();
}


