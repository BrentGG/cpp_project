#include "game.h"

Game::Game()
{
    player = new Player(new Coords(5, 10), new Coords(50, 50), 100, 100, 100);
}

Player *Game::getPlayer()
{
    return player;
}
