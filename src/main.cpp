#include <ncurses.h>
#include "../core/app.hpp"
#include "./windows/mainWindow.hpp"

// int main()
// {
//     initscr();
//     resize_term(25, 80);
//     start_color();
//     init_pair(1, COLOR_BLUE, COLOR_YELLOW);
//     init_pair(2, COLOR_RED, COLOR_GREEN);

//     keypad(stdscr, true);
//     curs_set(0);
//     noecho();

//     bkgd(COLOR_PAIR(1));
//     attron(COLOR_PAIR(1));
//     mvprintw(1, 1, "C++ programming");
//     mvprintw(2, 1, "Computer Science @ Kookmin Univ.");
//     attroff(COLOR_PAIR(1));

//     attron(COLOR_PAIR(2));
//     border('*', '*', '*', '*', '*', '*', '*', '*');
//     attroff(COLOR_PAIR(2));

//     refresh();
//     getch();
//     endwin();

//     return 0;
// }

int main()
{
    App::create()
        ->attachWindow(new MainWindow())
        ->execute();
    return 0;
}
