#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "enemy.h"

#include <vector>

enum ENEMY_TYPE {
    ZOMBIE
};

class Game
{
public:
    Game();

    void tick(float timeDeltaMs);
    bool checkEnemyCollosion(Enemy* enemy1, Enemy* enemy2);
    bool checkEnemyCollides(Enemy* enemy);

    Player* getPlayer();
    std::vector<Enemy*> getEnemies();
    std::vector<ENEMY_TYPE> getEnemyTypes();

private:
    Player* player;
    std::vector<Enemy*> enemies;
    std::vector<ENEMY_TYPE> enemyTypes;
};

#endif // GAME_H
