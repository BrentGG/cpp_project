#ifndef PLAYERDRAWING_H
#define PLAYERDRAWING_H

#include "canvasdrawing.h"
#include "player.h"

class PlayerDrawing : public CanvasDrawing
{
public:
    PlayerDrawing(Player* model);

    void draw(QPainter* painter) override;

private:
    Player* model;
};

#endif // PLAYERDRAWING_H
