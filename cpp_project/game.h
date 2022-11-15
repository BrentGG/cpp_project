#ifndef GAME_H
#define GAME_H

#include "player.h"

class Game
{
public:
    Game();

    Player* getPlayer();

private:
    Player* player;
};

#endif // GAME_H
