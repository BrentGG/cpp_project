#include "gamecontroller.h"

GameController::GameController()
{
    gameModel = new Game();
}

void GameController::keyPressed(int key)
{
    if (key == Qt::Key_Z)
        gameModel->getPlayer()->setGoingUp(true);
    else if (key == Qt::Key_S)
        gameModel->getPlayer()->setGoingDown(true);
    else if (key == Qt::Key_Q)
        gameModel->getPlayer()->setGoingLeft(true);
    else if (key == Qt::Key_D)
        gameModel->getPlayer()->setGoingRight(true);
}

void GameController::keyReleased(int key)
{
    if (key == Qt::Key_Z)
        gameModel->getPlayer()->setGoingUp(false);
    else if (key == Qt::Key_S)
        gameModel->getPlayer()->setGoingDown(false);
    else if (key == Qt::Key_Q)
        gameModel->getPlayer()->setGoingLeft(false);
    else if (key == Qt::Key_D)
        gameModel->getPlayer()->setGoingRight(false);
}

void GameController::tick(float timeDeltaMs)
{
    gameModel->getPlayer()->move(timeDeltaMs);
}

Player *GameController::getPlayer()
{
    return gameModel->getPlayer();
}
