#include "arrow.h"

Arrow::Arrow(qreal x,qreal y,qreal w,qreal h)
    : QGraphicsObject()
{
    rect = QRectF(x,y,w,h);
}

Arrow::~Arrow()
{

}

QRectF Arrow::geometry() const
{
    return rect;
}

void Arrow::setGeometry(const QRectF &value)
{
    if(rect!=value)
    {
        prepareGeometryChange();
        rect = value;
    }
}

QRectF Arrow::boundingRect() const
{
    return rect;
}

void Arrow::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    arrow.moveTo(rect.right(),rect.center().y());
    arrow.lineTo(rect.left(),rect.top());
    arrow.cubicTo(rect.left()+rect.width()*2/5,rect.top()+rect.height()/3,rect.left()+rect.width()*2/5,rect.bottom()-rect.height()/3,rect.left(),rect.bottom());
    arrow.closeSubpath();
    arrow.setFillRule(Qt::WindingFill);

    QLinearGradient gradient(rect.center().x(), rect.bottom(), 0, -rect.height());
    gradient.setColorAt(0.0, Qt::darkGray);
    gradient.setColorAt(1.0, Qt::black);
    QBrush fill(gradient);
    painter->setBrush(fill);
    painter->setPen(QPen(Qt::NoPen));
    painter->setRenderHint(QPainter::Antialiasing);
    painter->drawPath(arrow);
        Q_UNUSED(option);
        Q_UNUSED(widget);
}

void Arrow::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit signalArrow();

    QGraphicsItem::mousePressEvent(event);
}
