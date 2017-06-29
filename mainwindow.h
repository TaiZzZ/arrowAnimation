#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mycircle.h"
#include "mywhiteshadow.h"
#include "mytextok.h"

#include <QWidget>
#include <QGraphicsScene>
#include <QPushButton>

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

    void lancerAnimBoutonRond();

private:
    Ui::MainWindow *ui;

    QGraphicsScene *scene;

    MyCircle *roundButton;
    MyWhiteShadow *whiteShadow;
    MyTextOk *textOk;

    QGraphicsDropShadowEffect *shadowCircle;
    QPropertyAnimation *animationBoutonRondTaille;
    QPropertyAnimation *animationBoutonRondEllipse;
    QPropertyAnimation *animationBoutonRondOk;
    QPropertyAnimation *animationBoutonRondOkTaille;

private slots :
    void slotFromCircle();
};

#endif // MAINWINDOW_H
