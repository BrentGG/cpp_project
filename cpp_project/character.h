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
    Character();
    Character(Coords* hitBox, Coords* position, unsigned int speed, unsigned int maxHealth, unsigned int currentHealth);
    virtual ~Character() = 0;

    virtual void move() = 0;
    virtual void modifyHealth(int amount) = 0;

private:
    Coords* hitBox;
    Coords* position;

    // Stats
    unsigned int speed;
    unsigned int maxHealth;
    unsigned int currentHealth;
};

#endif // CHARACTER_H
