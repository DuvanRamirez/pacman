#include "personaje.h"

personaje::personaje()
{
    vy=7;
}

QRectF personaje::boundingRect() const
{
    return QRectF(-30,-30,30,30);
}

void personaje::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    pixmap.load(":/Imagenes/pacman.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

void personaje::mover()
{
    setPos(x(),y()+vy);
}

void personaje::choque()
{
    vy=-vy/1.3;
}
