#include "vampire.h"

#include <math.h>
#include <numbers>

Vampire::Vampire(Coords *hitBox, Coords *position, unsigned short int speed, unsigned short int maxHealth, unsigned short int currentHealth, unsigned short int damage, Coords* target):
    Enemy(hitBox, position, speed, maxHealth, currentHealth, target), damage(damage)
{
}

void Vampire::move(float timeDeltaMs)
{
    moveAllowance += speed * (timeDeltaMs / 1000);
    moved = false;
    if (moveAllowance < 1)
        return;
    int xDif = target->x() - position->x();
    int yDif = target->y() - position->y();
    float angle = std::atan2(yDif, xDif);
    float xDist = std::round(std::cos(angle) * moveAllowance);
    float yDist = std::round(std::sin(angle) * moveAllowance);
    if (std::hypot(xDist, yDist) > moveAllowance)
        return;
    *prevPosition = *position;
    position->addX(xDist);
    position->addY(yDist);
    moved = true;
    prevMoveAllowance = moveAllowance;
    moveAllowance = 0;
}

void Vampire::moveOnlyX()
{
    position->addX(std::round(target->x() > position->x() ? moveAllowance : -1 * moveAllowance));
}

void Vampire::moveOnlyY()
{
    position->addY(std::round(target->y() > position->y() ? moveAllowance : -1 * moveAllowance));
}

void Vampire::modifyHealth(short int amount)
{
    currentHealth += amount;
}
