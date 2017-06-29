#include "mytextok.h"

QVariant myFontInterpolator(const QFont &start, const QFont &end, qreal progress)
{
    if (progress<0.5)
    {
        qreal a = (1-progress)*50 + progress*45;
        QFont rt(start);
        rt.setPointSize(a);
        return rt;
    }
    else
    {
        qreal a = (1-progress)*45 + progress*50;
        QFont rt(start);
        rt.setPointSize(a);
        return rt;
    }
        Q_UNUSED(end)
}

MyTextOk::MyTextOk(QGraphicsObject *parent)
    : QObject(parent), QGraphicsSimpleTextItem(parent)
{
    point = QPointF(-40,-45);
    this->setText("Ok");
    this->setPos(point);
    this->setBrush(QBrush(Qt::white));
    fontText = QFont("Colibri",50);
    this->setFont(fontText);

    qRegisterAnimationInterpolator<QFont>(myFontInterpolator);
}

MyTextOk::~MyTextOk()
{

}

/*QPointF MyTextOk::localisation() const
{
    return point;
}

void MyTextOk::setLocalisation(const QPointF &value)
{
    if(point!=value)
    {
        point = value;
        update();
    }
}

QFont MyTextOk::sizePolicy() const
{
    return font;
}

void MyTextOk::setSizePolicy(const QFont &value)
{
    if(font!=value)
    {
        font=value;
        update();
    }
}*/

QRectF MyTextOk::boundingRect() const
{
    return QRectF(0,0,0,0);
}

