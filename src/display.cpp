// C++ standard libraries
#include <chrono>
// External libraries
#include <ncurses.h>
// Local headers
#include <display.hpp>
#include <entity.hpp>

#define WIN_FAIL            "Terminal size too small"
#define SUCCESS             "No error"

#define BOARD_SCALE         19
#define WIDTH_FACTOR        1.4
#define SET_BORDER(_Window) box((_Window), 0, 0)

#define EMPTY_SPACE " "

#define INPUT_CHECK_RATE    10
#define INPUT_TIME          (TURN_DURATION_MS - INPUT_CHECK_RATE)

typedef std::chrono::time_point<std::chrono::steady_clock> SteadyTime;

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

Display::~Display(void) {
    endwin();
    delete this->board;
}

// Instance methods
void Display::make_board(void) {
    this->board = new Board;
    this->board->height = BOARD_SCALE;
    this->board->width = this->board->height * WIDTH_FACTOR;
    size_t maxY, maxX;
    getmaxyx(stdscr, maxY, maxX);
    if(this->board->height > maxY || this->board->width > maxX) {
        this->open = false;
        this->err = WIN_FAIL; // Required to be a literal
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
    wrefresh(this->board->win);
}

SteadyTime Display::wait_input(void) {
    wtimeout(this->board->win, TURN_DURATION_MS);
    SteadyTime startTime = std::chrono::steady_clock::now();
    do {
        int32_t input = wgetch(this->board->win);
        switch(input) {
            case KEY_UP:
            case 'w':
                break;
            case KEY_DOWN:
            case 's':
                break;
            case KEY_LEFT:
            case 'a':
                break;
            case KEY_RIGHT:
            case 'd':
                break;
        }
    } while((std::chrono::steady_clock::now() - startTime) < std::chrono::milliseconds(INPUT_TIME));
    return startTime;
}

void Display::draw_entity(Entity *entActive) { // TODO: Switch on color identifiers with a default to print the specified char
    for(uint16_t i = 0; i < entActive->size; i++) {
        mvwprintw(this->board->win, entActive->pieces[i].y, entActive->pieces[i].x, &entActive->body);
    }
}

void Display::clear_entity(Entity *entActive) {
    for(uint16_t i = 0; i < entActive->size; i++) {
       mvwprintw(this->board->win, entActive->pieces[i].y, entActive->pieces[i].x, EMPTY_SPACE);
    }
}

// Getters
bool Display::win_fail(void) {
    return !this->open;
}

const char *Display::get_err(void) {
    return this->err;
}

size_t Display::get_center_x(void) {
    return this->board->width/2;
}


