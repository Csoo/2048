#ifndef PLAYER_H
#define PLAYER_H

#include <string>
class Player {
    std::string mDna;
    int mFitness = 1;  // 0

public:
    Player( int dnaLength = 100 );
    Player( const std::string &dna );
    const std::string &dna() const;
    int fitness() const;
    void setDna( const std::string &dna );

    // Create randomized DNA
    void randomDna( unsigned int length );

    // Cyclic permutation of numberOfGenes number random selected genes.
    void mutate( unsigned int numberOfGenes = 1 );

    // Cross DNAs of two player based on fitness ratio.
    Player operator+( Player &player );
};

#endif  // PLAYER_H