#include "mainwindow.h"
#include <QApplication>

QVariant myFontInterpolator(const QFont &start, const QFont &end, qreal progress)
{
    int a = start.pixelSize();
    int b = end.pixelSize();
    int c = (1-progress)*a + progress*b;
    QString mot = start.family();
    return QFont(mot,c);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qRegisterAnimationInterpolator<QFont>(myFontInterpolator);

    MainWindow fenetre;
    fenetre.setFixedSize(640,480);
    fenetre.show();

    return a.exec();
}
