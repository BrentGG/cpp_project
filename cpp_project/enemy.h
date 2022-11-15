#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"

class Enemy : public Character
{
public:
    Enemy();
    Enemy(Coords* hitBox, Coords* position, unsigned int speed, unsigned int maxHealth, unsigned int currentHealth, Coords* target);

    void setTarget(Coords* target);

protected:
    Coords* target;
};

#endif // ENEMY_H
