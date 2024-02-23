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

    void on_moveCenterButton_clicked();

    void on_scaleUpButton_pressed();

    void on_scaleUpButton_released();

    void on_scaleDownButton_pressed();

    void on_scaleDownButton_released();

    void on_moveup_pressed();

    void on_moveup_released();

    void on_moveleft_pressed();

    void on_moveleft_released();

    void on_moveright_pressed();

    void on_moveright_released();

    void on_movedown_pressed();

    void on_movedown_released();

private:
    Ui::MainWindow *ui;
    int width;
    int height;
    Rectangle rect;
    QGraphicsScene *scene;
    QTimer *timerClockwise;
    QTimer *timerCounterClockwise;
    QTimer *timerScaleUp;
    QTimer *timerScaleDown;
    QTimer *timerMoveUp;
};
#endif // MAINWINDOW_H
