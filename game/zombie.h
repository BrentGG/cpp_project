#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "enemy.h"

class Zombie : public Enemy
{
public:
    Zombie(Coords* hitBox, Coords* position, unsigned short int speed, unsigned short int maxHealth, unsigned short int currentHealth, unsigned short int damage, Coords* target);

    void move(float timeDeltaMs) override;
    void moveOnlyX() override;
    void moveOnlyY() override;
    void modifyHealth(short int amount) override;

private:
    unsigned int damage;
};

#endif // ZOMBIE_H
