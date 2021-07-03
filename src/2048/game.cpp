#include "game.h"
#include <stdlib.h>
#include <iostream>
#include <vector>

void Game2048::addSquare() {
    const int size = mWidth * mWidth;
    if (mEmpties <= 0) {
        bool found = false;
        unsigned int index = 0;
        while (index < size - 1 && !found) {  // last row check missing
            if (index + mWidth >= size)
                found = mBoard[index] == mBoard[index + 1];
            else
                found = (mBoard[index] == mBoard[index + 1] && index % mWidth != mWidth - 1) ||
                        mBoard[index] == mBoard[index + mWidth];
            ++index;
        }
        mOver = index >= size - mWidth;
        return;
    }
    const unsigned int nth = rand() % mEmpties + 1;
    int index = 0;
    int ith = 0;
    while (ith != nth && index < size) {
        if (mBoard[index] == 0)
            ++ith;
        ++index;
    }

    --mEmpties;
    mBoard[index - 1] = (rand() % 2 + 1) * 2;
}

void Game2048::move(Direction direction, unsigned int index) {
    const int newIndex = index + static_cast<int>(direction);
    if (newIndex < 0 || newIndex >= mWidth * mWidth)
        return;
    if (mBoard[newIndex] != 0 && mBoard[newIndex] != mBoard[index])
        return;
    if (direction == Direction::LEFT && index % mWidth == 0)
        return;
    if (direction == Direction::RIGHT && index % mWidth == mWidth - 1)
        return;
    if (mBoard[index] == mBoard[newIndex]) {
        mBoard[newIndex] <<= 1;
        mBoard[index] = 0;
        mScore += mBoard[newIndex];
        ++mEmpties;
        return;
    }
    mBoard[newIndex] = mBoard[index];
    mBoard[index] = 0;
    move(direction, newIndex);
}

void Game2048::moveAll(Direction direction) {
    const unsigned int size = mWidth * mWidth;
    if (direction == Direction::DOWN || direction == Direction::LEFT) {
        for (int index = 0; index < size; ++index) {
            if (mBoard[index] != 0)
                move(direction, index);
        }
    } else {
        for (int index = size - 1; index >= 0; --index) {
            if (mBoard[index] != 0)
                move(direction, index);
        }
    }
    addSquare();
}

unsigned int Game2048::score() const {
    return mScore;
}

bool Game2048::over() const {
    return mOver;
}

std::ostream &operator<<(std::ostream &os, const Game2048 &game) {
    for (int index = game.mWidth * game.mWidth - game.mWidth; index >= 0; ++index) {
        os << " " << game.mBoard[index] << " ";
        if (index % game.mWidth == game.mWidth - 1) {
            os << '\n';
            index -= 2 * game.mWidth;
        }
    }
    return os;
}

Game2048::Game2048(unsigned int width) : mWidth(width) {
    const unsigned int size = mWidth * mWidth;
    mBoard = std::vector<unsigned int>(size);
    mEmpties = size;
}

Game2048::Game2048() {
    mBoard = std::vector<unsigned int>(mWidth * mWidth);
}

void Game2048::start() {
    addSquare();
    addSquare();
}
