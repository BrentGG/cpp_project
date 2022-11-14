#include "character.h"

Character::Character()
{
}

Character::Character(Coords *hitBox, Coords *position, unsigned int speed, unsigned int maxHealth, unsigned int currentHealth) :
    hitBox(hitBox), position(position), speed(speed), maxHealth(maxHealth), currentHealth(currentHealth)
{
}
