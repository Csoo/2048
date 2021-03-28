#ifndef PLAYER_H
#define PLAYER_H

#include <string>
class Player {
    std::string mDna;
    int fittness = 0;

public:
    Player();
    const std::string &dna() const;
    void setDna(const std::string &dna);

    void mutate(unsigned int numberOfGenes = 1);
};

#endif  // PLAYER_H