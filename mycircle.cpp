#include "mycircle.h"

MyCircle::MyCircle()
    : QGraphicsObject()
{
    rect = QRectF(-90,-90,180,180);
    setAcceptHoverEvents(true);
}

MyCircle::~MyCircle()
{

}

QRectF MyCircle::geometry() const
{
    return rect;
}

void MyCircle::setGeometry(const QRectF &value)
{
    if(rect!=value)
    {
        rect = value;
        update();
    }
}

QRectF MyCircle::boundingRect() const
{
    return rect;
}

void MyCircle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QLinearGradient grad(rect.center().x(),rect.top(),0,rect.height());
    grad.setColorAt(0,Qt::green);
    grad.setColorAt(1,Qt::black);
    QBrush brush(grad);

    // On crée notre cercle

    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(QPen(Qt::NoPen));
    painter -> setBrush(brush);
    painter -> drawEllipse(rect);

        Q_UNUSED(option);
        Q_UNUSED(widget);
}

void MyCircle::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit signal1();

    QGraphicsItem::mousePressEvent(event);
}
