#include "game.h"

Game::Game()
{
    player = new Player(new Coords(5, 10), new Coords(250, 250), 100, 100, 100);
    //zombies.push_back(new Zombie(new Coords(5, 10), new Coords(50, 25), 50, 100, 100, 100, player->getPosition()));
    zombies.push_back(new Zombie(new Coords(5, 10), new Coords(550, 25), 50, 100, 100, 100, player->getPosition()));
    //zombies.push_back(new Zombie(new Coords(5, 10), new Coords(600, 50), 50, 100, 100, 100, player->getPosition()));
    //zombies.push_back(new Zombie(new Coords(5, 10), new Coords(600, 550), 50, 100, 100, 100, player->getPosition()));
    //zombies.push_back(new Zombie(new Coords(5, 10), new Coords(10, 50), 50, 100, 100, 100, player->getPosition()));
    //zombies.push_back(new Zombie(new Coords(5, 10), new Coords(10, 550), 50, 100, 100, 100, player->getPosition()));
    //zombies.push_back(new Zombie(new Coords(5, 10), new Coords(50, 600), 50, 100, 100, 100, player->getPosition()));
    //zombies.push_back(new Zombie(new Coords(5, 10), new Coords(550, 600), 50, 100, 100, 100, player->getPosition()));
}

Player *Game::getPlayer()
{
    return player;
}

std::vector<Zombie*> Game::getZombies()
{
    return zombies;
}

void Game::tick(float timeDeltaMs)
{
    player->move(timeDeltaMs);
    for (Zombie* zombie: zombies) {
        zombie->setTarget(player->getPosition());
        zombie->move(timeDeltaMs);
    }
}
