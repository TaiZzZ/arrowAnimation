#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // On crée nos objets

    roundButton = new MyCircle;
    whiteShadow = new MyWhiteShadow(roundButton);
    textOk = new MyTextOk(roundButton);

    // Ajout des ombres
    shadowCircle = new QGraphicsDropShadowEffect;
    shadowCircle->setOffset(0);
    shadowCircle->setBlurRadius(15);
    roundButton->setGraphicsEffect(shadowCircle);

    // On initialise notre vue

    setWindowFlags(Qt::FramelessWindowHint);

    // On ajoute notre scene à notre vue

    scene = new QGraphicsScene(QRect(0, 0, 640, 480), this);
    ui->vue->setScene(scene);

    scene -> addItem(roundButton);
    roundButton -> setPos(scene->width() / 2,scene->height() / 2);

    // On connect

    connect(roundButton,SIGNAL(signal1()),this,SLOT(slotFromCircle()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::lancerAnimBoutonRond()
{
    animationBoutonRondTaille = new QPropertyAnimation(roundButton, "geometry");

    animationBoutonRondTaille->setDuration(300);
    animationBoutonRondTaille->setKeyValueAt(0, QRectF(-90, -90, 180, 180));
    animationBoutonRondTaille->setKeyValueAt(0.5, QRectF(-85,-85,170,170));
    animationBoutonRondTaille->setKeyValueAt(1, QRectF(-90, -90, 180, 180));

    animationBoutonRondTaille -> start();

    animationBoutonRondEllipse = new QPropertyAnimation(whiteShadow, "geometry");

    animationBoutonRondEllipse->setDuration(300);
    animationBoutonRondEllipse->setKeyValueAt(0,QRectF(-70,-80,140,80));
    animationBoutonRondEllipse->setKeyValueAt(0.5,QRectF(-65,-75,130,90));
    animationBoutonRondEllipse->setKeyValueAt(1,QRectF(-70,-80,140,80));

    animationBoutonRondEllipse->start();

    animationBoutonRondOk = new QPropertyAnimation(textOk,"pos");

    animationBoutonRondOk->setDuration(300);
    animationBoutonRondOk->setKeyValueAt(0,QPointF(-40,-45));
    animationBoutonRondOk->setKeyValueAt(0.5,QPointF(-37, -41));
    animationBoutonRondOk->setKeyValueAt(1,QPointF(-40, -45));

    animationBoutonRondOk->start();

    animationBoutonRondOkTaille = new QPropertyAnimation(textOk,"font");

    animationBoutonRondOkTaille->setDuration(300);
    animationBoutonRondOkTaille->setStartValue(QFont("Colibri",50));
    animationBoutonRondOkTaille->setEndValue(QFont("Colibri",50));

    animationBoutonRondOkTaille->start();

}

void MainWindow::slotFromCircle()
{
    lancerAnimBoutonRond();
}
