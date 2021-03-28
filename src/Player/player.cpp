#include "player.h"
#include <stdlib.h>
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

const std::string &Player::dna() const {
    return mDna;
}

Player::Player() {
    mDna = "DDRLULL";
}
