#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // On crée nos objets
    arrow = new Arrow();

    // On initialise notre vue

    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint); // sert à enlever les bords de la fenêtre

    // On ajoute notre scene à notre vue

    scene = new QGraphicsScene(QRectF(0,0,640,480),this);
    ui->vue->setScene(scene);

    scene -> addItem(arrow);
    arrow->setPos(scene->width() / 2 - 125, scene->height() / 2);

    // Ajout de l'ombre

    /*shadowArrow = new QGraphicsDropShadowEffect;
    shadowArrow->setOffset(2);
    shadowArrow->setColor(QColor(Qt::black));
    arrow->setGraphicsEffect(shadowArrow);*/

    // On connect

    connect(arrow,SIGNAL(signalArrow()),this,SLOT(slotFromFleche()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::lancerAnimFleche()
{
    animationFleche = new QPropertyAnimation(arrow,"geometry");

    animationFleche->setDuration(300);
    animationFleche->setKeyValueAt(0,QRectF(100,-50,50,100));
    animationFleche->setKeyValueAt(0.5,QRectF(105,-50,50,100));
    animationFleche->setKeyValueAt(1,QRectF(100,-50,50,100));

    animationFleche->start();
}

void MainWindow::slotFromFleche()
{
    lancerAnimFleche();
}

