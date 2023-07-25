#ifndef GAME_CONTROLLER_HPP
#define GAME_CONTROLLER_HPP

class Display;
class EntityManager;

class GameController {
    public:
        GameController(void);
        void end_with_code(int code);
        void cleanup(void);
        void play_round(void);

        // Getters
        bool is_running(void);
        int get_exit_state(void);
    private:
        bool running;
        int exitState;
        Display *screen;
        EntityManager *entMan;
};

#endif