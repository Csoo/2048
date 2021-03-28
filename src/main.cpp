#include <time.h>
#include <iostream>
#include "2048/game.h"
#include "Player/player.h"
#include "direction.h"

int main(int, char **) {
    srand(time(NULL));
    Game2048 game;
    game.start();
    Player p1;
    p1.mutate();
    std::cout << p1.dna() << '\n';
    p1.mutate();
    std::cout << p1.dna() << '\n';
    p1.mutate(3);
    std::cout << p1.dna() << '\n';
    return 0;
}
