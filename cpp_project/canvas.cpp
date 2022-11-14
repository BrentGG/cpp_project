#include "canvas.h"

#include <iostream>

#include<QPainter>
#include <QTimer>

Canvas::Canvas(QWidget *parent) : QWidget{parent}
{
    x = 50;
    y = 50;
    mvmtSpeed = 5;
    setFocusPolicy(Qt::StrongFocus); // Focus otherwise keypressed don't get passed to this widget

    // Set timer to update view
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, QOverload<>::of(&Canvas::updateView));
    timer->start(1000/60); // target fps = 60
}

void Canvas::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawRect(x, y, 5, 5);
}

void Canvas::keyPressEvent(QKeyEvent *event)
{

    if(event->key() == Qt::Key_D)
        x += mvmtSpeed;
    if(event->key() == Qt::Key_Q)
        x -= mvmtSpeed;
    if(event->key() == Qt::Key_Z)
        y -= mvmtSpeed;
    if(event->key() == Qt::Key_S)
        y += mvmtSpeed;
}

void Canvas::updateView()
{
    update();
}
