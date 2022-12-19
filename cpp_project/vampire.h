#ifndef VAMPIRE_H
#define VAMPIRE_H

#include "enemy.h"

class Vampire : public Enemy
{
public:
    Vampire(Coords* hitBox, Coords* position, unsigned int speed, unsigned int maxHealth, unsigned int currentHealth, unsigned int damage, Coords* target);

    void move(float timeDeltaMs) override;
    void moveOnlyX() override;
    void moveOnlyY() override;
    void modifyHealth(int amount) override;

private:
    unsigned int damage;
};

#endif // VAMPIRE_H
