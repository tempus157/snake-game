#include <ncurses.h>

int main()
{
    initscr();
    start_color();
    init_pair(1, COLOR_RED, COLOR_WHITE);

    attron(COLOR_PAIR(1));
    printw("Hello, world!");
    attroff(COLOR_PAIR(1));

    refresh();
    getch();
    endwin();

    return 0;
}