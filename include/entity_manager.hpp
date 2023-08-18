#ifndef ENTITY_MANAGER_HPP
#define ENTITY_MANAGER_HPP

// C++ standard libraries
#include <random>

typedef struct _Entity Entity;
typedef struct _Coord Coord;

class EntityManager {
    public:
        EntityManager(size_t screenCenter);
        void step_down(void);

        // Getters
        Entity *get_current_entity(void);

    private:
        static std::random_device randGen;
        size_t screenCenter;
        Entity *currentEnt;

        static Coord *random_piece(uint16_t &size, char &body);
        void init_entities(void);
        Entity *make_entity(uint16_t size, char body, Coord *offSets, size_t startY, size_t startX);
};

#endif