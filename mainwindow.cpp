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

    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/Imagenes/mapa2.png")));


    timer=new QTimer();

    connect(timer,SIGNAL(timeout()),this,SLOT(animar()));
    connect(this,SIGNAL(aviso(int)),this,SLOT(aumentarPunt()));

    timer->start(33);

    pacman = new personaje();
    scene->addItem(pacman);
    pacman->setPos(330,260);


    punto = new puntos();
    scene->addItem(punto);
    punto->setPos(200,350);
    punto2 = new puntos();
    scene->addItem(punto2);
    punto2->setPos(130,38);
    punto3 = new puntos();
    scene->addItem(punto3);
    punto3->setPos(300,350);
    punto4 = new puntos();
    scene->addItem(punto4);
    punto4->setPos(350,30);
    punto5 = new puntos();
    scene->addItem(punto5);
    punto5->setPos(200,100);
    punto6 = new puntos();
    scene->addItem(punto6);
    punto6->setPos(210,100);
    punto7 = new puntos();
    scene->addItem(punto7);
    punto7->setPos(50,350);
    punto8 = new puntos();
    scene->addItem(punto8);
    punto8->setPos(25,30);
    punto9 = new puntos();
    scene->addItem(punto9);
    punto9->setPos(12,5);
}

MainWindow::~MainWindow()
{
    delete scene;
    delete ui;
}


void MainWindow::animar()
{

    if(moverIx1 )
    {
        pacman->setPos(pacman->x()-2,pacman->y());
    }
    if(moverDx1 )
    {
        pacman->setPos(pacman->x()+2,pacman->y());
    }
    if(moverUy1 )
    {
        pacman->setPos(pacman->x(),pacman->y()-2);
    }
    if(moverDy1 )
    {
        pacman->setPos(pacman->x(),pacman->y()+2);
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





