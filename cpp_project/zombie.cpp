#define _USE_MATH_DEFINES

#include "zombie.h"

#include <math.h>
#include <numbers>

#include <iostream>

Zombie::Zombie(Coords *hitBox, Coords *position, unsigned int speed, unsigned int maxHealth, unsigned int currentHealth, unsigned int damage, Coords* target):
    Enemy(hitBox, position, speed, maxHealth, currentHealth, target), damage(damage)
{
}

void Zombie::move(float timeDeltaMs)
{
    moveAllowance += speed * (timeDeltaMs / 1000);
    if (moveAllowance < 1)
        return;
    int xDif = target->x() - position->x();
    int yDif = target->y() - position->y();
    float angle = std::atan2(yDif, xDif);
    float xDist = std::round(std::cos(angle) * moveAllowance);
    float yDist = std::round(std::sin(angle) * moveAllowance);
    if (std::hypot(xDist, yDist) > moveAllowance)
        return;
    position->addX(xDist);
    position->addY(yDist);

    moveAllowance = 0;
}

void Zombie::modifyHealth(int amount)
{

}
