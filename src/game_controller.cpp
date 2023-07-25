// C++ standard headers
#include <iostream>
// C standard libraries
#include <cstdlib>
// Local headers
#include <game_controller.hpp>
#include <entity_manager.hpp>
#include <display.hpp>

// Constructor/Destructor
GameController::GameController(void) {
    this->screen = new Display;
    screen->make_board();
    if(screen->win_fail()) {
        const char* err = screen->get_err();
        delete screen;
        std::cerr << err << std::endl;
        std::exit(EXIT_FAILURE);
    }
    this->enMan = new EntityManager;
    this->running = true;
}

// Instance methods
void GameController::cleanup(void) {
    delete this->screen;
    delete this->enMan;
}

bool GameController::play_round(void) {
    screen->wait_input();
    this->running = false;
    return this->running;
}