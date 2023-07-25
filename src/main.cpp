// Local headers
#include <game_controller.hpp>

int main(void) {
    GameController gameMan;
    while(gameMan.is_running()) gameMan.play_round();

    return gameMan.get_exit_state();
}