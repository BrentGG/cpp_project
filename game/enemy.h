#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"

class Enemy : public Character
{
public:
    Enemy(Coords* hitBox, Coords* position, unsigned short int speed, unsigned short int maxHealth, unsigned short int currentHealth, Coords* target);

    virtual void moveOnlyX() = 0;
    virtual void moveOnlyY() = 0;

    void revertPosition();

    void setTarget(Coords* target);

    Coords* getTarget();
    bool getMoved();

protected:
    Coords* target;
    Coords* prevPosition;
    float prevMoveAllowance;
    bool moved;
};

#endif // ENEMY_H
