#include "puntos.h"

puntos::puntos()
{
    vy=7;
}

QRectF puntos::boundingRect() const
{
    return QRectF(-10,-10,7,7);
}

void puntos::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    pixmap.load(":/Imagenes/punto.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

void puntos::mover()
{
    setPos(x(),y()+vy);
}

void puntos::choque()
{
    vy=-vy/1.3;
}
