#ifndef MYWHITESHADOW_H
#define MYWHITESHADOW_H


#include <QGraphicsObject>
#include <QPainter>

class MyWhiteShadow :public QGraphicsObject
{
    Q_OBJECT
    Q_PROPERTY(QRectF geometry READ geometry WRITE setGeometry)

public:
    explicit MyWhiteShadow(QGraphicsObject *parent = 0);
    ~MyWhiteShadow();

    QRectF geometry() const;
    void setGeometry(const QRectF &value);

private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected :
    QRectF rect;
};

#endif // MYWHITESHADOW_H
