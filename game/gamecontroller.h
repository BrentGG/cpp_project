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
    std::vector<Enemy*> getEnemies();
    std::vector<Game::ENEMY_TYPE> getEnemyTypes();

private:
    Game* gameModel;
};

#endif // GAMECONTROLLER_H
