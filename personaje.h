#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>


class personaje : public QGraphicsItem
{
public:
    personaje();
    QRectF boundingRect() const;
    void paint(QPainter *painter,
    const QStyleOptionGraphicsItem *option, QWidget *widget);
    int x_sprite=31;
    int y_sprite=0;

};


#endif // PERSONAJE_H
