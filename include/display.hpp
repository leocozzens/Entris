#ifndef BOARD_HPP
#define BOARD_HPP

#define TURN_DURATION_MS 200

class EntityManager;
typedef struct _Board Board;
typedef struct _Entity Entity;

class Display {
    public:
        Display(void);
        ~Display(void);

        void make_board(void);
        std::chrono::time_point<std::chrono::steady_clock> wait_input(void);
        void draw_entity(Entity *entActive);
        void clear_entity(Entity *entActive);

        // Getters
        bool win_fail(void);
        const char *get_err(void);
        size_t get_center_x(void);
    private:
        bool open;
        const char *err;
        Board *board;
        EntityManager *enManager;

        static void clear_win(void *win);
        void make_window(size_t maxY, size_t maxX);
};

#endif