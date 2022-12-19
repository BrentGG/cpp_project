#include "character.h"

Character::Character(Coords *hitBox, Coords *position, unsigned short int speed, unsigned short int maxHealth, unsigned short int currentHealth) :
    hitBox(hitBox), position(position), speed(speed), maxHealth(maxHealth), currentHealth(currentHealth)
{
    moveAllowance = 0;
}

Character::~Character()
{
    delete hitBox;
    delete position;
}

Coords *Character::getHitBox()
{
    return hitBox;
}

Coords *Character::getPosition()
{
    return position;
}
