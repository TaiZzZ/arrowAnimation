#include "mywhiteshadow.h"

MyWhiteShadow::MyWhiteShadow(QGraphicsObject *parent)
    : QGraphicsObject(parent)
{
    rect = QRectF(-70,-80,140,80);
    this->setOpacity(0.3);
}

MyWhiteShadow::~MyWhiteShadow()
{

}

QRectF MyWhiteShadow::geometry() const
{
    return rect;
}

void MyWhiteShadow::setGeometry(const QRectF &value)
{
    if(rect!=value)
    {
        rect = value;
        update();
    }
}

QRectF MyWhiteShadow::boundingRect() const
{
    return rect;
}

void MyWhiteShadow::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QLinearGradient grad(rect.center().x(),rect.top(),0,rect.height());
    grad.setColorAt(0,Qt::white);
    grad.setColorAt(1,Qt::green);
    QBrush brush(grad);

    // On crée notre cercle

    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(QPen(Qt::NoPen));
    painter -> setBrush(brush);
    painter -> drawEllipse(rect);
        Q_UNUSED(option);
        Q_UNUSED(widget);
}
