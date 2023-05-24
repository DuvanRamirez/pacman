#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QImage>
#include <QDebug>
#include "personaje.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene=new QGraphicsScene(0,0,650,500);
    ui->graphicsView->setScene(scene);


    puntuacion = 0;
    moverIx1=false;
    moverDx1=false;
    moverUy1=false;
    moverDy1=false;


    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/Imagenes/maparojo.png")));
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/Imagenes/mapa2.png")));

    timer=new QTimer();

    connect(timer,SIGNAL(timeout()),this,SLOT(animar()));
    connect(this,SIGNAL(aviso(int)),this,SLOT(aumentarPunt()));

    timer->start(33);



    pacman = new personaje;
    scene->addItem(pacman);
    pacman->setPos(325, 244);
    objetoPosX = pacman->x();
    objetoPosY = pacman->y();


    punto = new puntos();
    scene->addItem(punto);
    punto->setPos(127,37);
    punto2 = new puntos();
    scene->addItem(punto2);
    punto2->setPos(526,37);
    punto3 = new puntos();
    scene->addItem(punto3);
    punto3->setPos(127,484);
    punto4 = new puntos();
    scene->addItem(punto4);
    punto4->setPos(526,484);
    punto5 = new puntos();
    scene->addItem(punto5);
    punto5->setPos(148,244);
    punto6 = new puntos();
    scene->addItem(punto6);
    punto6->setPos(502,244);
    punto7 = new puntos();
    scene->addItem(punto7);
    punto7->setPos(326,100);
    punto8 = new puntos();
    scene->addItem(punto8);
    punto8->setPos(326,385);
    punto9 = new puntos();
    scene->addItem(punto9);
    punto9->setPos(326,292);
}

MainWindow::~MainWindow()
{
    delete scene;
    delete ui;
}
void MainWindow::animar()
{
    QImage image(":/Imagenes/maparojo.png");
    int z=12;
    if(moverIx1){
        QRgb pixelValueX = image.pixel(objetoPosX-z, objetoPosY);
        int r, g, b;
        QColor color(pixelValueX);
        color.getRgb(&r, &g, &b);

        if(r==0 && g==0 && b==0 ){
            pacman->setPos(pacman->x()-2,pacman->y());
            objetoPosX-=2;
        }

    }
    if(moverDx1){
        QRgb pixelValueX = image.pixel(objetoPosX+z, objetoPosY);
        int r, g, b;
        QColor color(pixelValueX);
        color.getRgb(&r, &g, &b);

        if(r==0 && g==0 && b==0 ){
            pacman->setPos(pacman->x()+2,pacman->y());
            objetoPosX+=2;
        }

    }
    if(moverUy1){
        QRgb pixelValueY = image.pixel(objetoPosX, objetoPosY-z);
        int r, g, b;
        QColor color(pixelValueY);
        color.getRgb(&r, &g, &b);

        if(r==0 && g==0 && b==0 ){
            pacman->setPos(pacman->x(),pacman->y()-2);
            objetoPosY-=2;
        }

    }
    if(moverDy1){
        QRgb pixelValueY = image.pixel(objetoPosX, objetoPosY+z);
        int r, g, b;
        QColor color(pixelValueY);
        color.getRgb(&r, &g, &b);

        if(r==0 && g==0 && b==0){
            pacman->setPos(pacman->x(),pacman->y()+2);
            objetoPosY+=2;
        }

    }
    if(pacman->collidesWithItem(punto))
    {
        if(punto->isVisible()){
            punto->hide();
            emit aviso(9);
        }
    }
    if(pacman->collidesWithItem(punto2))
    {
        if(punto2->isVisible()){
            punto2->hide();
            emit aviso(9);
        }
    }
    if(pacman->collidesWithItem(punto3))
    {
        if(punto3->isVisible()){
            punto3->hide();
            emit aviso(9);
        }
    }
    if(pacman->collidesWithItem(punto4))
    {
        if(punto4->isVisible()){
            punto4->hide();
            emit aviso(9);
        }
    }
    if(pacman->collidesWithItem(punto5))
    {
        if(punto5->isVisible()){
            punto5->hide();
            emit aviso(9);
        }
    }
    if(pacman->collidesWithItem(punto6))
    {
        if(punto6->isVisible()){
            punto6->hide();
            emit aviso(9);
        }
    }
    if(pacman->collidesWithItem(punto7))
    {
        if(punto7->isVisible()){
            punto7->hide();
            emit aviso(9);
        }
    }
    if(pacman->collidesWithItem(punto8))
    {
        if(punto8->isVisible()){
            punto8->hide();
            emit aviso(9);
        }
    }
    if(pacman->collidesWithItem(punto9))
    {
        if(punto9->isVisible()){
            punto9->hide();
            emit aviso(9);
        }
    }


}

void MainWindow::keyPressEvent(QKeyEvent *ev)
{
    if(ev->key()==Qt::Key_A)
    {
        moverIx1=true;
    }
    else if(ev->key()==Qt::Key_D)
    {
        moverDx1=true;
    }
    else if(ev->key()==Qt::Key_W)
    {
        moverUy1=true;
    }
    else if(ev->key()==Qt::Key_S)
    {
        moverDy1=true;
    }


}

void MainWindow::keyReleaseEvent(QKeyEvent *ev)
{
    if(ev->key()==Qt::Key_A)
    {
        moverIx1=false;
    }
    else if(ev->key()==Qt::Key_D)
    {
        moverDx1=false;
    }
    else if(ev->key()==Qt::Key_W)
    {
        moverUy1=false;
    }
    else if(ev->key()==Qt::Key_S)
    {
        moverDy1=false;
    }

}

void MainWindow::aumentarPunt()
{
    puntuacion += 1;
    ui->lcdNumber->display(puntuacion);
    std::cout<<puntuacion<<std::endl;
}





