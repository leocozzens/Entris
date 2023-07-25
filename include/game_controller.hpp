#ifndef GAME_CONTROLLER_HPP
#define GAME_CONTROLLER_HPP

class Display;
class EntityManager;

class GameController {
    public:
        GameController(void);
        void cleanup(void);
        bool play_round(void);

    private:
        bool running;
        Display *screen;
        EntityManager *enMan;
};

#endif