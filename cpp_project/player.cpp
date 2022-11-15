#include "player.h"

#include <iostream>

Player::Player()
{

}

Player::Player(Coords *hitBox, Coords *position, unsigned int speed, unsigned int maxHealth, unsigned int currentHealth):
    Character(hitBox, position, speed, maxHealth, currentHealth)
{
    goingUp = false;
    goingDown = false;
    goingLeft = false;
    goingRight = false;
}

void Player::move(float timeDeltaMs)
{
    distanceMoved += speed * (timeDeltaMs / 1000);
    if (distanceMoved < 1)
        return;
    if (goingUp && !goingLeft && !goingRight && !goingDown)
        position->addY(-1 * distanceMoved);
    else if (goingDown && !goingLeft && !goingRight && !goingUp)
        position->addY(distanceMoved);
    else if (goingLeft && !goingUp && !goingDown && !goingRight)
        position->addX(-1 * distanceMoved);
    else if (goingRight && !goingUp && !goingDown && !goingLeft)
        position->addX(distanceMoved);
    distanceMoved = 0;
    // TODO: add diagonal movement
}

void Player::modifyHealth(int amount)
{
    // TODO
}

void Player::setGoingUp(bool goingUp)
{
    this->goingUp = goingUp;
}

void Player::setGoingDown(bool goingDown)
{
    this->goingDown = goingDown;
}

void Player::setGoingLeft(bool goingLeft)
{
    this->goingLeft = goingLeft;
}

void Player::setGoingRight(bool goingRight)
{
    this->goingRight = goingRight;
}
