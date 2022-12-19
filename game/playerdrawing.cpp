#include "playerdrawing.h"

PlayerDrawing::PlayerDrawing(Player* model): model(model)
{
}

void PlayerDrawing::draw(QPainter *painter)
{
    painter->drawRect(model->getPosition()->x(), model->getPosition()->y(), 5, 10);
}
