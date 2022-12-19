#ifndef CHARACTER_H
#define CHARACTER_H

#include "coords.h"

#include <utility>

/**
 * @brief Character is an abstract base class for the different characters such as players and enemies. Every character has a hitbox, position, and certain stats.
 */
class Character
{
public:
    Character(Coords* hitBox, Coords* position, unsigned short int speed, unsigned short int maxHealth, unsigned short int currentHealth);
    virtual ~Character();

    virtual void move(float timeDeltaMs) = 0;
    virtual void modifyHealth(short int amount) = 0;

    Coords *getHitBox();
    Coords *getPosition();

protected:
    Coords* hitBox;
    Coords* position;

    // Stats
    unsigned short int speed; // pixels moved per second
    unsigned short int maxHealth;
    unsigned short int currentHealth;

    float moveAllowance;
};

#endif // CHARACTER_H
