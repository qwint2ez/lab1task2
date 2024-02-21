#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QMessageBox>
#include "rectangle.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_rectangle_clicked();
    void on_calculate_clicked();

    void on_turnclockwise_pressed();

    void on_turncounterclockwise_pressed();

    void on_turnclockwise_released();

    void on_turncounterclockwise_released();

private:
    Ui::MainWindow *ui;
    int width;
    int height;
    Rectangle rect;
    QGraphicsScene *scene;
    QTimer *timerClockwise;
    QTimer *timerCounterClockwise;
};
#endif // MAINWINDOW_H
