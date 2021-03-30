#include <time.h>
#include <iostream>
#include "2048/game.h"
#include "Player/player.h"
#include "direction.h"

void makeMove(DirectionGene direction, Game2048 *game) {
    switch (direction) {
        case DirectionGene::DOWN: {
            game->moveAll(Direction::DOWN);
            break;
        }
        case DirectionGene::RIGHT: {
            game->moveAll(Direction::RIGHT);
            break;
        }
        case DirectionGene::UP: {
            game->moveAll(Direction::UP);
            break;
        }
        case DirectionGene::LEFT: {
            game->moveAll(Direction::LEFT);
            break;
        }
    }
}

int main(int, char **) {
    srand(time(nullptr));
    Game2048 game;
    game.start();
    Player p2("DULRURR"), p1;
    p1.randomDna(70);
    std::cout << p1.dna() << '\n';
    const unsigned int size = p1.dna().length();
    unsigned int index = 0;
    while (index < size && !game.over()) {
        makeMove(static_cast<DirectionGene>(p1.dna()[index++]), &game);
    }
    std::cout << game << game.score();
    game.over() ? std::cout << '\n' << "OVER" : std::cout << '\n' << "NOT OVER";
    return 0;
}
