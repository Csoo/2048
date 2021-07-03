#include <time.h>
#include <iostream>
#include "2048/game.h"
#include "Player/player.h"
#include "enums/direction.h"

int main( int, char ** ) {
    srand( time( nullptr ) );
    Game2048 game;
    game.start();
    Player p1;
    std::cout << p1.dna() << '\n';
    const unsigned int size = p1.dna().length();
    unsigned int index = 0;
    while ( index < size && !game.over() ) {
        game.makeMove( static_cast<DirectionGene>( p1.dna()[index++] ) );
    }
    std::cout << game << game.score() << " turn: " << index;
    game.over() ? std::cout << '\n' << "OVER" : std::cout << '\n' << "NOT OVER";
    return 0;
}
