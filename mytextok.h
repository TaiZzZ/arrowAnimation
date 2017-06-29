#ifndef MYTEXTOK_H
#define MYTEXTOK_H

#include <QGraphicsSimpleTextItem>
#include <QFont>
#include <QBrush>
#include <QObject>
#include <QPropertyAnimation>

class MyTextOk : public QObject, public QGraphicsSimpleTextItem
{
    Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)
    Q_PROPERTY(QFont font READ font WRITE setFont)
public:
    explicit MyTextOk(QGraphicsObject *parent = 0);
    ~MyTextOk();

    //QPointF localisation() const;
    //void setLocalisation(const QPointF &value);

    //QFont sizePolicy() const;
    //void setSizePolicy(const QFont &value);

private:
    QRectF boundingRect() const;

protected :
    QPointF point;
    QFont fontText;
};

#endif // MYTEXTOK_H
