#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <QGraphicsItem>
#include <QPainter>

class personaje : public QGraphicsItem
{
public:
    personaje();
    QRectF boundingRect() const;
    void paint(QPainter *painter,
       const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mover();
    void choque();
    int vy;
};

#endif // PERSONAJE_H
