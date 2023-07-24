// C++ standard libraries
#include <cstddef>
// External libraries
#include <ncurses.h>
// Local headers
#include <board.hpp>

#define WIN_FAIL "Terminal size too small"
#define SUCCESS "No error"

#define BOARD_SCALE 20
#define SET_BORDER(_Window) box((_Window), 0, 0)

struct _Board {
    WINDOW *win;
    size_t height;
    size_t width;
};

// Static methods
void Display::clear_win(void *win) {
    wclear((WINDOW*) win);
    SET_BORDER((WINDOW*) win);
    wrefresh((WINDOW*) win);
}

// Constructor/Destructor
Display::Display(void) {
    initscr();
    cbreak();
    noecho();
    curs_set(0);
}

// Instance methods
void Display::make_board(void) {
    this->board = new Board;
    this->board->height = BOARD_SCALE;
    this->board->width = this->board->height * 2.5;
    size_t maxY, maxX;
    getmaxyx(stdscr, maxY, maxX);
    if(this->board->height > maxY || this->board->width > maxX) {
        this->open = false;
        this->err = WIN_FAIL;
    }
    else {
        this->open = true;
        this->err = SUCCESS;
        make_window(maxY, maxX);
        clear_win(this->board->win);
    }
}

void Display::make_window(size_t maxY, size_t maxX) {
    this->board->win = newwin(this->board->height, this->board->width, (maxY - this->board->height)/2, (maxX - this->board->width)/2);
    keypad(this->board->win, 1);
}

void Display::cleanup(void) {
    endwin();
    delete this->board;
}

void Display::wait_input(void) {
    wgetch(this->board->win);
}

// Getters
bool Display::win_fail(void) {
    return !this->open;
}

const char *Display::get_err(void) {
    return this->err;
}


