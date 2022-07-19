#include "Input.hpp"

#include <ncurses.h>

std::map<const Key, std::vector<const std::function<void()>>>
    Input::keyPressCallbacks = {};

void Input::onKeyPress(const Key &key, const std::function<void()> &callback) {
    keyPressCallbacks[key].push_back(callback);
}

void Input::notifyKeyPress(const Key &key) {
    for (const auto &callback : keyPressCallbacks[key]) {
        callback();
    }

    for (const auto &callback : keyPressCallbacks[Key::Any]) {
        callback();
    }
}

void Input::clearKeyPress() {
    keyPressCallbacks.clear();
}

void Input::mount() {
    keypad(stdscr, true);
    curs_set(0);
    noecho();
}

Key Input::readKey() {
    switch (getch()) {
    case 'a':
    case 'A':
        return Key::A;
    case 'b':
    case 'B':
        return Key::B;
    case 'c':
    case 'C':
        return Key::C;
    case 'd':
    case 'D':
        return Key::D;
    case 'e':
    case 'E':
        return Key::E;
    case 'f':
    case 'F':
        return Key::F;
    case 'g':
    case 'G':
        return Key::G;
    case 'h':
    case 'H':
        return Key::H;
    case 'i':
    case 'I':
        return Key::I;
    case 'j':
    case 'J':
        return Key::J;
    case 'k':
    case 'K':
        return Key::K;
    case 'l':
    case 'L':
        return Key::L;
    case 'm':
    case 'M':
        return Key::M;
    case 'n':
    case 'N':
        return Key::N;
    case 'o':
    case 'O':
        return Key::O;
    case 'p':
    case 'P':
        return Key::P;
    case 'q':
    case 'Q':
        return Key::Q;
    case 'r':
    case 'R':
        return Key::R;
    case 's':
    case 'S':
        return Key::S;
    case 't':
    case 'T':
        return Key::T;
    case 'u':
    case 'U':
        return Key::U;
    case 'v':
    case 'V':
        return Key::V;
    case 'w':
    case 'W':
        return Key::W;
    case 'x':
    case 'X':
        return Key::X;
    case 'y':
    case 'Y':
        return Key::Y;
    case 'z':
    case 'Z':
        return Key::Z;
    case '0':
    case ')':
        return Key::Number0;
    case '1':
    case '!':
        return Key::Number1;
    case '2':
    case '@':
        return Key::Number2;
    case '3':
    case '#':
        return Key::Number3;
    case '4':
    case '$':
        return Key::Number4;
    case '5':
    case '%':
        return Key::Number5;
    case '6':
    case '^':
        return Key::Number6;
    case '7':
    case '&':
        return Key::Number7;
    case '8':
    case '*':
        return Key::Number8;
    case '9':
    case '(':
        return Key::Number9;
    case '`':
    case '~':
        return Key::Backtick;
    case '-':
    case '_':
        return Key::Hyphen;
    case '=':
    case '+':
        return Key::Equal;
    case '[':
    case '{':
        return Key::LeftBracket;
    case ']':
    case '}':
        return Key::RightBracket;
    case '\\':
    case '|':
        return Key::Backslash;
    case ';':
    case ':':
        return Key::Semicolon;
    case '\'':
    case '"':
        return Key::Apostrophe;
    case ',':
    case '<':
        return Key::Comma;
    case '.':
    case '>':
        return Key::Period;
    case '/':
    case '?':
        return Key::Slash;
    case ' ':
        return Key::Space;
    case KEY_F(1):
        return Key::F1;
    case KEY_F(2):
        return Key::F2;
    case KEY_F(3):
        return Key::F3;
    case KEY_F(4):
        return Key::F4;
    case KEY_F(5):
        return Key::F5;
    case KEY_F(6):
        return Key::F6;
    case KEY_F(7):
        return Key::F7;
    case KEY_F(8):
        return Key::F8;
    case KEY_F(9):
        return Key::F9;
    case KEY_F(10):
        return Key::F10;
    case KEY_F(11):
        return Key::F11;
    case KEY_F(12):
        return Key::F12;
    case '\t':
    case KEY_BTAB:
        return Key::Tab;
    case KEY_BACKSPACE:
    case 127:
        return Key::Backspace;
    case KEY_ENTER:
    case 10:
        return Key::Enter;
    case KEY_IC:
        return Key::Insert;
    case KEY_DC:
        return Key::Delete;
    case KEY_HOME:
        return Key::Home;
    case KEY_END:
        return Key::End;
    case KEY_NPAGE:
        return Key::PageUp;
    case KEY_PPAGE:
        return Key::PageDown;
    case KEY_UP:
    case KEY_SR:
        return Key::UpArrow;
    case KEY_DOWN:
    case KEY_SF:
        return Key::DownArrow;
    case KEY_LEFT:
    case KEY_SLEFT:
        return Key::LeftArrow;
    case KEY_RIGHT:
    case KEY_SRIGHT:
        return Key::RightArrow;
    default:
        return Key::Error;
    }
}
