#include <iostream>
#include "2048/direction.h"
#include "2048/game.h"

int main(int, char **) {
    Game2048 game;
    game.start();
    std::cout << game << '\n';
    game.moveAll(DOWN);
    std::cout << game << '\n';
    game.moveAll(LEFT);
    std::cout << game << '\n';
    game.moveAll(DOWN);
    std::cout << game << '\n';
    game.moveAll(LEFT);
    std::cout << game << '\n';
    game.moveAll(DOWN);
    std::cout << game << '\n';
    game.moveAll(DOWN);
    std::cout << game << '\n';
    game.moveAll(LEFT);
    std::cout << game << '\n';
    game.moveAll(DOWN);
    std::cout << game << '\n';
    game.moveAll(DOWN);
    std::cout << game << '\n';
    game.moveAll(LEFT);
    std::cout << game << '\n';
    game.moveAll(DOWN);
    std::cout << game << '\n';
    return 0;
}
