#ifndef MYCIRCLE_H
#define MYCIRCLE_H

#include <QGraphicsObject>
#include <QPainter>
#include <QPropertyAnimation>
#include <QApplication>
#include <QGraphicsSceneHoverEvent>
#include <QGraphicsDropShadowEffect>

class MyCircle :public QGraphicsObject
{
    Q_OBJECT
    Q_PROPERTY(QRectF geometry READ geometry WRITE setGeometry)

public:
    explicit MyCircle();
    ~MyCircle();

    QRectF geometry() const;
    void setGeometry(const QRectF &value);

signals:
    void signal1();

protected:
    virtual void hoverEnterEvent (QGraphicsSceneHoverEvent *event) override
    {
      QGraphicsItem::hoverEnterEvent(event);
      QApplication::setOverrideCursor(Qt::PointingHandCursor);
    }

    virtual void hoverLeaveEvent (QGraphicsSceneHoverEvent *event) override
    {
      QGraphicsItem::hoverLeaveEvent(event);
      QApplication::setOverrideCursor(Qt::ArrowCursor);
    }

    virtual QPainterPath shape () const override
    {
      QPainterPath path;
      path.addEllipse(rect);
      return(path);
    }

    virtual void hoverMoveEvent (QGraphicsSceneHoverEvent *event) override
    {
        QGraphicsItem::hoverMoveEvent(event);
        if (shape().contains(event->pos())) {
          QApplication::setOverrideCursor(Qt::PointingHandCursor);
        }
        else {
          QApplication::setOverrideCursor(Qt::ArrowCursor);
        }
    }

    void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected :
    QRectF rect;
};

#endif // MYCIRCLE_H
