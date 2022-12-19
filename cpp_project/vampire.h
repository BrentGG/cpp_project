#ifndef VAMPIRE_H
#define VAMPIRE_H

#include "enemy.h"

class Vampire : public Enemy
{
public:
    Vampire(Coords* hitBox, Coords* position, unsigned short int speed, unsigned short int maxHealth, unsigned short int currentHealth, unsigned short int damage, Coords* target);

    void move(float timeDeltaMs) override;
    void moveOnlyX() override;
    void moveOnlyY() override;
    void modifyHealth(short int amount) override;

private:
    unsigned int damage;
};

#endif // VAMPIRE_H
