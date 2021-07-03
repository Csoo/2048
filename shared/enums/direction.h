#ifndef DIRECTION_H
#define DIRECTION_H

#include <vector>

enum class Direction
{
    LEFT = -1,
    RIGHT = 1,
    UP = 4,
    DOWN = -4
};

enum class DirectionGene : char
{
    LEFT = 'L',
    UP = 'U',
    RIGHT = 'R',
    DOWN = 'D'
};

static std::vector<DirectionGene> ALL_DIRECTION = { DirectionGene::UP, DirectionGene::DOWN, DirectionGene::LEFT,
                                                    DirectionGene::RIGHT };

inline DirectionGene operator++( DirectionGene &direction ) {
    switch ( direction ) {
        case DirectionGene::LEFT:
            return DirectionGene::DOWN;
        case DirectionGene::RIGHT:
            return DirectionGene::UP;
        case DirectionGene::UP:
            return DirectionGene::LEFT;
        case DirectionGene::DOWN:
            return DirectionGene::RIGHT;
    }
    return direction;
};

#endif  // DIRECTION_H