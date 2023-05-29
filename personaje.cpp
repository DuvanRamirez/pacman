#include "personaje.h"

personaje::personaje()
{

}

QRectF personaje::boundingRect() const
{
    return QRectF(-18,-18,36,36);
}

void personaje::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    pixmap.load(":/Imagenes/pacman.png");
    painter->drawPixmap(-18,-18,pixmap,x_sprite,y_sprite,30,30);
}
