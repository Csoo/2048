#ifndef GAME_H
#define GAME_H
#include <ostream>
#include <vector>
#include "direction.h"

class Game2048 {
    unsigned int _score = 0;
    unsigned int _width = 4;
    std::vector<unsigned int> _board;
    unsigned int _empties = 16;
    bool _over = false;

    void move(Direction direction, unsigned int index);
    void addSquare();

public:
    Game2048();
    Game2048(unsigned int width);
    Game2048(const Game2048 &c) = delete;

    void start();
    void moveAll(Direction direction);

    friend std::ostream &operator<<(std::ostream &os, const Game2048 &game);
};

#endif  // GAME_H