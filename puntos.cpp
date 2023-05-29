#include "puntos.h"

puntos::puntos()
{

}

QRectF puntos::boundingRect() const
{
    return QRectF(-4,-4,8,8);
}

void puntos::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    pixmap.load(":/Imagenes/punto.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

