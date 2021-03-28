#include "game.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>

void Game2048::addSquare() {
    const unsigned int nth = rand() % _empties + 1;
    const int size = _width * _width;
    int index = 0;
    int ith = 0;
    while (ith != nth && index < size) {
        if (_board[index] == 0)
            ++ith;
        ++index;
    }

    if (index >= size) {
        _over = true;
        return;
    }
    --_empties;
    _board[index - 1] = (rand() % 2 + 1) * 2;
}

void Game2048::move(Direction direction, unsigned int index) {
    const unsigned int newIndex = index + direction;
    if (newIndex < 0 || newIndex >= _width * _width)
        return;
    if (_board[newIndex] != 0 && _board[newIndex] != _board[index])
        return;
    if (direction == LEFT && index % _width == 0)
        return;
    if (direction == RIGHT && index % _width == 3)
        return;
    if (_board[index] == _board[newIndex]) {
        _board[newIndex] <<= 1;
        _board[index] = 0;
        return;
    }
    _board[newIndex] = _board[index];
    _board[index] = 0;
    move(direction, newIndex);
}

void Game2048::moveAll(Direction direction) {
    const unsigned int size = _width * _width;
    if (direction == DOWN || direction == LEFT) {
        for (int index = 0; index < size; ++index) {
            if (_board[index] != 0)
                move(direction, index);
        }
    } else {
        for (int index = size - 1; index >= 0; --index) {
            if (_board[index] != 0)
                move(direction, index);
        }
    }
    addSquare();
}

std::ostream &operator<<(std::ostream &os, const Game2048 &game) {
    for (int index = game._width * game._width - game._width; index >= 0; ++index) {
        os << " " << game._board[index] << " ";
        if (index % game._width == game._width - 1) {
            os << '\n';
            index -= 2 * game._width;
        }
    }
    return os;
}

Game2048::Game2048(unsigned int width) : _width(width) {
    const unsigned int size = _width * _width;
    _board = std::vector<unsigned int>(size);
    _empties = size;
}

Game2048::Game2048() {
    srand(time(NULL));
    _board = std::vector<unsigned int>(_width * _width);
}

void Game2048::start() {
    addSquare();
    addSquare();
}
