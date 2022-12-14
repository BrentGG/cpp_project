#include "enemy.h"

Enemy::Enemy(Coords *hitBox, Coords *position, unsigned short int speed, unsigned short int maxHealth, unsigned short int currentHealth, Coords* target):
    Character(hitBox, position, speed, maxHealth, currentHealth), target(target)
{
    prevPosition = new Coords(position->x(), position->y());
    prevMoveAllowance = 0;
    moved = false;
}

void Enemy::revertPosition()
{
    *position = *prevPosition;
}

void Enemy::setTarget(Coords *target)
{
    this->target = target;
}

Coords *Enemy::getTarget()
{
    return target;
}

bool Enemy::getMoved()
{
    return moved;
}
