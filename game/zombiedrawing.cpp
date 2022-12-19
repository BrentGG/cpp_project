#include "zombiedrawing.h"

ZombieDrawing::ZombieDrawing(Zombie* model): model(model)
{
}

void ZombieDrawing::draw(QPainter *painter)
{
    painter->setPen(Qt::red);
    painter->drawRect(model->getPosition()->x(), model->getPosition()->y(), 5, 10);
}
