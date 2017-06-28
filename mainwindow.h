#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

#include "arrow.h"

#include <QWidget>
#include <QGraphicsScene>
#include <QPushButton>
#include <QPropertyAnimation>

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected :

    void lancerAnimFleche();

private:
    Ui::MainWindow *ui;

    QGraphicsScene *scene;
    Arrow *arrow;

    QPropertyAnimation *animationFleche;

private slots :
    void slotFromFleche();
};

#endif // MAINWINDOW_H
