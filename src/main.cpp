#include <time.h>
#include <iostream>
#include "2048/game.h"
#include "Player/player.h"
#include "direction.h"

int main(int, char **) {
    srand(time(NULL));
    Game2048 game;
    game.start();
    Player p2("DULRURR"), p1("RUDDRUPUUDDLUPRURRLUP");
    p1.mutate();
    std::cout << p1.dna() << '\n';
    p1.mutate(2);
    std::cout << p1.dna() << '\n';
    p1.mutate(3);
    std::cout << p1.dna() << " + ";
    p1 = p1 + p2;
    std::cout << p2.dna() << " = " << p1.dna();
    return 0;
}
