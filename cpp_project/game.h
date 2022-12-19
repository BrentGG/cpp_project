#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "enemy.h"

#include <vector>

class Game
{
public:
    Game();
    ~Game();

    enum ENEMY_TYPE {
        ZOMBIE,
        VAMPIRE
    };

    void tick(float timeDeltaMs);
    bool checkEnemyCollosion(Enemy* enemy1, Enemy* enemy2);
    bool checkEnemyCollides(Enemy* enemy);

    Player* getPlayer();
    std::vector<Enemy*> getEnemies();
    std::vector<Game::ENEMY_TYPE> getEnemyTypes();

private:
    Player* player;
    std::vector<Enemy*> enemies;
    std::vector<Game::ENEMY_TYPE> enemyTypes;
};

#endif // GAME_H
