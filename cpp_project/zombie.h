#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "enemy.h"

class Zombie : public Enemy
{
public:
    Zombie(Coords* hitBox, Coords* position, unsigned int speed, unsigned int maxHealth, unsigned int currentHealth, unsigned int damage, Coords* target);

    void move(float timeDeltaMs) override;
    void modifyHealth(int amount) override;

private:
    unsigned int damage;
};

#endif // ZOMBIE_H
