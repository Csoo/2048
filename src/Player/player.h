#ifndef PLAYER_H
#define PLAYER_H

#include <string>
class Player {
    std::string mDna;
    int mFittness = 1;  // 0

public:
    Player();
    Player(const std::string &dna);
    const std::string &dna() const;
    int fittness() const;
    void setDna(const std::string &dna);
    void randomDna(unsigned int length);

    void mutate(unsigned int numberOfGenes = 1);
    Player operator+(Player &player);
};

#endif  // PLAYER_H