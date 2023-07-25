#ifndef ENTITY_MANAGER_HPP
#define ENTITY_MANAGER_HPP

// C++ standard libraries
#include <random>

typedef struct _Entity Entity;
typedef struct _Coord Coord;

class EntityManager {
    public:
        EntityManager(void);

        Entity *get_current_entity(void);

    private:
        Entity *currentEnt;
        std::random_device randGen;

        Entity *make_entity(uint16_t size, char body, Coord **offSets);
        void get_random_piece(uint16_t &size, char &body, Coord **offSets);
};

#endif