#define _USE_MATH_DEFINES

#include "player.h"

#include <math.h>

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
    // straight movement
    if (goingUp && !goingLeft && !goingRight && !goingDown)
        position->addY(-1 * distanceMoved);
    else if (goingDown && !goingLeft && !goingRight && !goingUp)
        position->addY(distanceMoved);
    else if (goingLeft && !goingUp && !goingDown && !goingRight)
        position->addX(-1 * distanceMoved);
    else if (goingRight && !goingUp && !goingDown && !goingLeft)
        position->addX(distanceMoved);
    else { // diagonal movement
        float dist = std::sin(45 * (M_PI/180)) * distanceMoved;
        if (std::hypot(dist, dist) > distanceMoved)
            return;
        if (goingUp && goingLeft && !goingRight && !goingDown) {
            position->addX(-1 * dist);
            position->addY(-1 * dist);
        }
        else if (goingUp && goingRight && !goingLeft && !goingDown) {
            position->addX(dist);
            position->addY(-1 * dist);
        }
        else if (goingDown && goingLeft && !goingRight && !goingUp) {
            position->addX(-1 * dist);
            position->addY(dist);
        }
        else if (goingDown && goingRight && !goingLeft && !goingUp) {
            position->addX(dist);
            position->addY(dist);
        }
    }
    distanceMoved = 0;
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
