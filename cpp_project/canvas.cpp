#include "canvas.h"

#include <iostream>

Canvas::Canvas(QWidget *parent) : QWidget{parent}
{
    painter = new QPainter(this);
}

void Canvas::paintEvent(QPaintEvent *event)
{
    painter->begin(this);
    for (CanvasDrawing* drawing : drawings)
        drawing->draw(painter);
    painter->end();
}

void Canvas::updateCanvas()
{
    update();
}

void Canvas::addDrawing(CanvasDrawing* drawing)
{
    drawings.push_back(drawing);
}
