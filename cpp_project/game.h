#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "zombie.h"

#include <vector>

class Game
{
public:
    Game();

    void tick(float timeDeltaMs);

    Player* getPlayer();
    std::vector<Zombie*> getZombies();

private:
    Player* player;
    std::vector<Zombie*> zombies;
};

#endif // GAME_H
