#include "characterdrawing.h"

CharacterDrawing::CharacterDrawing(Character* model): model(model)
{
}

void CharacterDrawing::draw(QPainter *painter)
{
    painter->drawRect(model->getPosition()->x(), model->getPosition()->y(), 5, 10);
}
