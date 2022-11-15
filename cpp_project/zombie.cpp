#define _USE_MATH_DEFINES

#include "zombie.h"

#include <math.h>
#include <numbers>

#include <iostream>

Zombie::Zombie()
{
}

Zombie::Zombie(Coords *hitBox, Coords *position, unsigned int speed, unsigned int maxHealth, unsigned int currentHealth, unsigned int damage, Coords* target):
    Enemy(hitBox, position, speed, maxHealth, currentHealth, target), damage(damage)
{
}

void Zombie::move(float timeDeltaMs)
{
    distanceMoved += speed * (timeDeltaMs / 1000);
    if (distanceMoved < 1)
        return;

    int xDif = position->x() - target->x();
    int yDif = target->y() - position->y();
    float angle = std::atan2(yDif, xDif) * (180 / M_PI);
    position->addX(-1 * std::cos(angle) * distanceMoved);
    position->addY(std::sin(angle) * distanceMoved);

    distanceMoved = 0;
}

void Zombie::modifyHealth(int amount)
{

}
