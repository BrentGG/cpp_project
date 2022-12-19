#include "vampiredrawing.h"

VampireDrawing::VampireDrawing(Vampire* model): model(model)
{
}

void VampireDrawing::draw(QPainter *painter)
{
    painter->setPen(Qt::blue);
    painter->drawRect(model->getPosition()->x(), model->getPosition()->y(), 5, 10);
}
