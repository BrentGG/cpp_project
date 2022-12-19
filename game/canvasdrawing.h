#ifndef CANVASDRAWING_H
#define CANVASDRAWING_H

#include <QPainter>

#include <vector>

class CanvasDrawing
{
public:
    CanvasDrawing();

    virtual void draw(QPainter* painter) = 0;
};

#endif // CANVASDRAWING_H
