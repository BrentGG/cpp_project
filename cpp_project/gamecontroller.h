#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "game.h"

#include <QKeyEvent>

class GameController
{
public:
    GameController();

    void keyPressed(int key);
    void keyReleased(int key);

    void tick(float timeDeltaMs);

    Player* getPlayer();

private:
    Game* gameModel;
};

#endif // GAMECONTROLLER_H
