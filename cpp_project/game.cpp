#include "game.h"

Game::Game()
{
    player = new Player(new Coords(5, 10), new Coords(250, 250), 100, 100, 100);
    zombies.push_back(new Zombie(new Coords(5, 10), new Coords(50, 25), 50, 100, 100, 100, player->getPosition()));
    zombies.push_back(new Zombie(new Coords(5, 10), new Coords(550, 25), 50, 100, 100, 100, player->getPosition()));
    zombies.push_back(new Zombie(new Coords(5, 10), new Coords(600, 50), 50, 100, 100, 100, player->getPosition()));
    zombies.push_back(new Zombie(new Coords(5, 10), new Coords(600, 550), 50, 100, 100, 100, player->getPosition()));
    zombies.push_back(new Zombie(new Coords(5, 10), new Coords(10, 50), 50, 100, 100, 100, player->getPosition()));
    zombies.push_back(new Zombie(new Coords(5, 10), new Coords(10, 550), 50, 100, 100, 100, player->getPosition()));
    zombies.push_back(new Zombie(new Coords(5, 10), new Coords(50, 600), 50, 100, 100, 100, player->getPosition()));
    zombies.push_back(new Zombie(new Coords(5, 10), new Coords(550, 600), 50, 100, 100, 100, player->getPosition()));
}

void Game::tick(float timeDeltaMs)
{
    // move player
    player->move(timeDeltaMs);

    // move enemies
    for (Zombie* zombie : zombies) {
        zombie->setTarget(player->getPosition());
        zombie->move(timeDeltaMs);
        if (checkEnemyCollides(zombie) && zombie->getMoved()) {
            zombie->revertPosition();
            zombie->moveOnlyX();
            if (checkEnemyCollides(zombie)) {
                zombie->revertPosition();
                zombie->moveOnlyY();
                if (checkEnemyCollides(zombie))
                    zombie->revertPosition();
            }
        }
    }
}

bool Game::checkEnemyCollosion(Enemy* enemy1, Enemy* enemy2)
{
    Coords enemy1Pos = *enemy1->getPosition();
    Coords enemy1HitBox = *enemy1->getHitBox();
    Coords enemy2Pos = *enemy2->getPosition();
    Coords enemy2HitBox = *enemy2->getHitBox();
    if ((enemy1Pos.x() < enemy2Pos.x() + enemy2HitBox.x() &&
         enemy2Pos.x() < enemy1Pos.x() + enemy1HitBox.x() &&
         enemy1Pos.y() < enemy2Pos.y() + enemy2HitBox.y() &&
         enemy2Pos.y() < enemy1Pos.y() + enemy1HitBox.y())) {
        return true;
    }
    return false;
}

bool Game::checkEnemyCollides(Enemy *enemy)
{
    std::vector<Enemy*> enemies;
    enemies.insert(enemies.end(), zombies.begin(), zombies.end());
    for (Enemy* enemy2 : enemies) {
        if (enemy != enemy2 && checkEnemyCollosion(enemy, enemy2))
            return true;
    }
    return false;
}

Player *Game::getPlayer()
{
    return player;
}

std::vector<Zombie*> Game::getZombies()
{
    return zombies;
}
