// Local headers
#include <game_controller.hpp>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

int main(void) {
    GameController gameMan;

    bool running;
    do { running = gameMan.play_round(); } while(running);

    gameMan.cleanup();
    return EXIT_SUCCESS;
}