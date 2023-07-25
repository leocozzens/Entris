// C++ standard headers
#include <iostream>
// Local headers
#include <game_controller.hpp>
#include <entity_manager.hpp>
#include <display.hpp>

// Constructor/Destructor
GameController::GameController(void) {
    this->screen = new Display;
    this->screen->make_board();
    if(screen->win_fail()) {
        const char* err = screen->get_err();
        this->cleanup();
        std::cerr << err << std::endl;
        this->end_with_code(EXIT_FAILURE);
    }
    else {
        this->entMan = new EntityManager(screen->get_center_x());
        this->screen->draw_entity(entMan->get_current_entity());
        this->running = true; 
    }
}

// Instance methods
void GameController::end_with_code(int code) {
    this->exitState = code;
    this->running = false;
}

void GameController::cleanup(void) {
    delete this->screen;
    delete this->entMan;
}

void GameController::play_round(void) {
    this->screen->wait_input();
    this->screen->clear_entity(entMan->get_current_entity());
    this->entMan->step_down();
    this->screen->draw_entity(entMan->get_current_entity());

    // this->cleanup();
    // end_with_code(EXIT_SUCCESS);
}

// Getters
bool GameController::is_running(void) {
    return this->running;
}

int GameController::get_exit_state(void) {
    return this->exitState;
}