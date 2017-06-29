#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow fenetre;
    fenetre.setFixedSize(640,480);
    fenetre.show();

    return a.exec();
}

