#include "player.h"
#include <stdlib.h>
#include <string>
#include "direction.h"

void Player::setDna(const std::string &dna) {
    mDna = dna;
}

void Player::mutate(unsigned int numberOfGenes) {
    for (int i = 0; i < numberOfGenes; ++i) {
        const unsigned int geneIdx = rand() % mDna.size();
        DirectionGene direction = static_cast<DirectionGene>(mDna[geneIdx]);
        mDna[geneIdx] = static_cast<char>(++direction);
    }
}

Player Player::operator+(Player &player) {
    Player tempPlayer;
    const float fitnessRatio = (float)mFittness / (mFittness + player.fittness());
    const int subDnaLength = fitnessRatio * mDna.size();
    std::string dna = mDna;
    tempPlayer.setDna(dna.replace(0, subDnaLength, player.dna().substr(0, subDnaLength)));
    return tempPlayer;
}

const std::string &Player::dna() const {
    return mDna;
}

int Player::fittness() const {
    return mFittness;
}

Player::Player() {}

Player::Player(const std::string &dna) : mDna(dna) {}