#ifndef BOARD_HPP
#define BOARD_HPP

class EntityManager;
typedef struct _Board Board;

class Display {
    public:
        Display(void);
        ~Display(void);

        void make_board(void);
        void wait_input(void);
        bool win_fail(void);
        const char *get_err(void);

    private:
        bool open;
        const char *err;
        Board *board;
        EntityManager *enManager;
        

        static void clear_win(void *win);

        void make_window(size_t maxY, size_t maxX);
};

#endif