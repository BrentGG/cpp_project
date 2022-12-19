#ifndef ZOMBIEDRAWING_H
#define ZOMBIEDRAWING_H

#include "canvasdrawing.h"
#include "zombie.h"

class ZombieDrawing : public CanvasDrawing
{
public:
    ZombieDrawing(Zombie* model);

    void draw(QPainter* painter) override;

private:
    Zombie* model;
};

#endif // ZOMBIEDRAWING_H
