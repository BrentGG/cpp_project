#include "worldview.h"

#include<QPainter>

WorldView::WorldView(QWidget *parent) : QWidget{parent}
{
    x = 50;
    y = 50;
    mvmtSpeed = 5;
    setFocusPolicy(Qt::StrongFocus); // Focus otherwise keypressed don't get passed to this widget
}

void WorldView::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawRect(x, y, 5, 5);
}

void WorldView::keyPressEvent(QKeyEvent *event)
{

    if(event->key() == Qt::Key_D)
        x += mvmtSpeed;
    if(event->key() == Qt::Key_Q)
        x -= mvmtSpeed;
    if(event->key() == Qt::Key_Z)
        y -= mvmtSpeed;
    if(event->key() == Qt::Key_S)
        y += mvmtSpeed;
    update();
}