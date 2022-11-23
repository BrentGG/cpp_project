#include "game.h"
#include "zombie.h"

Game::Game()
{
    player = new Player(new Coords(5, 10), new Coords(250, 250), 100, 100, 100);
    enemies.push_back(new Zombie(new Coords(5, 10), new Coords(50, 25), 50, 100, 100, 100, player->getPosition()));
    enemies.push_back(new Zombie(new Coords(5, 10), new Coords(550, 25), 50, 100, 100, 100, player->getPosition()));
    enemies.push_back(new Zombie(new Coords(5, 10), new Coords(600, 50), 50, 100, 100, 100, player->getPosition()));
    enemies.push_back(new Zombie(new Coords(5, 10), new Coords(600, 550), 50, 100, 100, 100, player->getPosition()));
    enemies.push_back(new Zombie(new Coords(5, 10), new Coords(10, 50), 50, 100, 100, 100, player->getPosition()));
    enemies.push_back(new Zombie(new Coords(5, 10), new Coords(10, 550), 50, 100, 100, 100, player->getPosition()));
    enemies.push_back(new Zombie(new Coords(5, 10), new Coords(50, 600), 50, 100, 100, 100, player->getPosition()));
    enemies.push_back(new Zombie(new Coords(5, 10), new Coords(550, 600), 50, 100, 100, 100, player->getPosition()));
    for (int i = 0; i < enemies.size(); ++i)
        enemyTypes.push_back(ZOMBIE);
}

void Game::tick(float timeDeltaMs)
{
    player->move(timeDeltaMs);
    for (Enemy* enemy: enemies) {
        enemy->setTarget(player->getPosition());
        enemy->move(timeDeltaMs);
    }
}

Player *Game::getPlayer()
{
    return player;
}

std::vector<Enemy*> Game::getEnemies()
{
    return enemies;
}

std::vector<ENEMY_TYPE> Game::getEnemyTypes()
{
    return enemyTypes;
}
