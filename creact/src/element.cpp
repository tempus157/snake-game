#include "element.h"
#include "color.h"

#include <ncurses.h>

#undef border

namespace Creact {
    Element label(const std::string &text) {
        return [=](const Vector &pos) {
            mvwprintw(stdscr, pos.y, pos.x, text.c_str());
        };
    }

    Element label(const std::string &text,
        Color foreground, Color background) {
        return [=](const Vector &pos) {
            InternalCreact::enableColor(foreground, background);
            mvwprintw(stdscr, pos.y, pos.x, text.c_str());
            InternalCreact::disableColor(foreground, background);
        };
    }

    Element box(const char ch, const Vector &scale) {
        return [=](const Vector &pos) {
            const auto current = Vector(getcurx(stdscr), getcury(stdscr));
            for (auto y = 0; y < scale.y; ++y) {
                for (auto x = 0; x < scale.x; ++x) {
                    mvwaddch(stdscr, current.y + y, current.x + x, ch);
                }
            }
        };
    }

    Element box(const char ch, const Vector &scale,
        Color foreground, Color background) {
        return [=](const Vector &origin) {
            const auto current = Vector(getcurx(stdscr), getcury(stdscr));
            InternalCreact::enableColor(foreground, background);

            for (auto y = 0; y < scale.y; ++y) {
                for (auto x = 0; x < scale.x; ++x) {
                    mvwaddch(stdscr, current.y + y, current.x + x, ch);
                }
            }

            InternalCreact::disableColor(foreground, background);
        };
    }

    Element border(const char ch, const Vector &scale) {
        return [=](const Vector &origin) {
            const auto current = Vector(getcurx(stdscr), getcury(stdscr));
            for (auto y = 0; y < scale.y; ++y) {
                for (auto x = 0; x < scale.x; ++x) {
                    if (x == 0 || y == 0 || x == scale.x - 1 || y == scale.y - 1) {
                        mvaddch(current.y + y, current.x + x, ch);
                    }
                }
            }
        };
    }

    Element border(const char ch, const Vector &scale,
        Color foreground, Color background) {
        return [=](const Vector &origin) {
            const auto current = Vector(getcurx(stdscr), getcury(stdscr));
            InternalCreact::enableColor(foreground, background);

            for (auto y = 0; y < scale.y; ++y) {
                for (auto x = 0; x < scale.x; ++x) {
                    if (x == 0 || y == 0 || x == scale.x - 1 || y == scale.y - 1) {
                        mvaddch(current.y + y, current.x + x, ch);
                    }
                }
            }

            InternalCreact::disableColor(foreground, background);
        };
    }
}
