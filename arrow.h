#ifndef ARROW_H
#define ARROW_H

#include <QGraphicsObject>
#include <QPainter>
#include <QApplication>

class Arrow : public QGraphicsObject
{
    Q_OBJECT
    Q_PROPERTY(QRectF geometry READ geometry WRITE setGeometry)

public:
    explicit Arrow(qreal x = 100,qreal y = -50,qreal w = 50,qreal h = 100);
    ~Arrow();

    QRectF geometry() const;
    void setGeometry(const QRectF &value);

signals:
    void signalArrow();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected :
    QRectF rect;
    QPainterPath arrow;
};
#endif // ARROW_H
