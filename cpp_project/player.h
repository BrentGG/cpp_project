#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"

class Player : public Character
{
public:
    Player(Coords* hitBox, Coords* position, unsigned int speed, unsigned int maxHealth, unsigned int currentHealth);

    void move(float timeDeltaMs) override;
    void modifyHealth(int amount) override;

    void setGoingUp(bool goingUp);
    void setGoingDown(bool goingDown);
    void setGoingLeft(bool goingLeft);
    void setGoingRight(bool goingRight);

private:
    bool goingUp;
    bool goingDown;
    bool goingLeft;
    bool goingRight;
};

#endif // PLAYER_H
