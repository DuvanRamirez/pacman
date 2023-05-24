#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsLineItem>
#include <QKeyEvent>
#include <QPainter>
#include <QTimer>
#include "puntos.h"
#include "personaje.h"
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void aviso(int);

public slots:
    void animar();
    void aumentarPunt();

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    personaje* pacman;
    puntos* punto;
    puntos* punto2;
    puntos* punto3;
    puntos* punto4;
    puntos* punto5;
    puntos* punto6;
    puntos* punto7;
    puntos* punto8;
    puntos* punto9;

    QTimer *timer;

    int puntuacion;

    bool moverIx1;
    bool moverDx1;
    bool moverUy1;
    bool moverDy1;

    void keyPressEvent(QKeyEvent *ev);
    void keyReleaseEvent(QKeyEvent *ev);

};
#endif // MAINWINDOW_H
