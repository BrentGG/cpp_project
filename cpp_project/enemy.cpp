#include "enemy.h"

Enemy::Enemy(Coords *hitBox, Coords *position, unsigned int speed, unsigned int maxHealth, unsigned int currentHealth, Coords* target):
    Character(hitBox, position, speed, maxHealth, currentHealth), target(target)
{
}

void Enemy::setTarget(Coords *target)
{
    this->target = target;
}

Coords *Enemy::getTarget()
{
    return target;
}
