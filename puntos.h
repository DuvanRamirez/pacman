#ifndef PUNTOS_H
#define PUNTOS_H

#include <QGraphicsItem>
#include <QPainter>

class puntos : public QGraphicsItem
{
public:
    puntos();
    QRectF boundingRect() const;
    void paint(QPainter *painter,
       const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mover();
    void choque();
    int vy;
};

#endif // PUNTOS_H
