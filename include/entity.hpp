#ifndef ENTITY_HPP
#define ENTITY_HPP

// C standard libraries
#include <stdint.h>

struct _Coord {
    uint16_t y;
    uint16_t x;
};

struct _Entity {
    uint16_t size;
    char body;
    struct _Coord *pieces;
    struct _Entity *nextEnt;
};

#endif