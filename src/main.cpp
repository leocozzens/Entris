// C++ standard libraries
#include <iostream>
#include <thread>
#include <chrono>
// Local headers
#include <board.hpp>

#include <ncurses.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

int main(void) {
    Display screen;
    screen.make_board();
    if(screen.win_fail()) {
        screen.cleanup();
        std::cerr << screen.get_err() << std::endl;
        return EXIT_FAILURE;
    }
    screen.wait_input();

    screen.cleanup();
    return EXIT_SUCCESS;
}