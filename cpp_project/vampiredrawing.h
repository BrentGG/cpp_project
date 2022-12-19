#ifndef VAMPIREDRAWING_H
#define VAMPIREDRAWING_H

#include "canvasdrawing.h"
#include "vampire.h"

class VampireDrawing : public CanvasDrawing
{
public:
    VampireDrawing(Vampire* model);

    void draw(QPainter* painter) override;

private:
    Vampire* model;
};

#endif // VAMPIREDRAWING_H
