#include "input.hpp"
#include <ncurses.h>

Key Input::key = Key::None;

void Input::readKey()
{
    switch (getch())
    {
    case '0':
    case ')':
        Input::key = Key::Number0;
        break;
    case '1':
    case '!':
        Input::key = Key::Number1;
        break;
    case '2':
    case '@':
        Input::key = Key::Number2;
        break;
    case '3':
    case '#':
        Input::key = Key::Number3;
        break;
    case '4':
    case '$':
        Input::key = Key::Number4;
        break;
    case '5':
    case '%':
        Input::key = Key::Number5;
        break;
    case '6':
    case '^':
        Input::key = Key::Number6;
        break;
    case '7':
    case '&':
        Input::key = Key::Number7;
        break;
    case '8':
    case '*':
        Input::key = Key::Number8;
        break;
    case '9':
    case '(':
        Input::key = Key::Number9;
        break;
    case 'a':
    case 'A':
        Input::key = Key::A;
        break;
    case 'b':
    case 'B':
        Input::key = Key::B;
        break;
    case 'c':
    case 'C':
        Input::key = Key::C;
        break;
    case 'd':
    case 'D':
        Input::key = Key::D;
        break;
    case 'e':
    case 'E':
        Input::key = Key::E;
        break;
    case 'f':
    case 'F':
        Input::key = Key::F;
        break;
    case 'g':
    case 'G':
        Input::key = Key::G;
        break;
    case 'h':
    case 'H':
        Input::key = Key::H;
        break;
    case 'i':
    case 'I':
        Input::key = Key::I;
        break;
    case 'j':
    case 'J':
        Input::key = Key::J;
        break;
    case 'k':
    case 'K':
        Input::key = Key::K;
        break;
    case 'l':
    case 'L':
        Input::key = Key::L;
        break;
    case 'm':
    case 'M':
        Input::key = Key::M;
        break;
    case 'n':
    case 'N':
        Input::key = Key::N;
        break;
    case 'o':
    case 'O':
        Input::key = Key::O;
        break;
    case 'p':
    case 'P':
        Input::key = Key::P;
        break;
    case 'q':
    case 'Q':
        Input::key = Key::Q;
        break;
    case 'r':
    case 'R':
        Input::key = Key::R;
        break;
    case 's':
    case 'S':
        Input::key = Key::S;
        break;
    case 't':
    case 'T':
        Input::key = Key::T;
        break;
    case 'u':
    case 'U':
        Input::key = Key::U;
        break;
    case 'v':
    case 'V':
        Input::key = Key::V;
        break;
    case 'w':
    case 'W':
        Input::key = Key::W;
        break;
    case 'x':
    case 'X':
        Input::key = Key::X;
        break;
    case 'y':
    case 'Y':
        Input::key = Key::Y;
        break;
    case 'z':
    case 'Z':
        Input::key = Key::Z;
        break;
    case '`':
    case '~':
        Input::key = Key::Backtick;
        break;
    case '-':
    case '_':
        Input::key = Key::Hyphen;
        break;
    case '=':
    case '+':
        Input::key = Key::Equal;
        break;
    case '[':
    case '{':
        Input::key = Key::LeftBracket;
        break;
    case ']':
    case '}':
        Input::key = Key::RightBracket;
        break;
    case '\\':
    case '|':
        Input::key = Key::Backslash;
        break;
    case ';':
    case ':':
        Input::key = Key::Semicolon;
        break;
    case '\'':
    case '"':
        Input::key = Key::Quote;
        break;
    case ',':
    case '<':
        Input::key = Key::Comma;
        break;
    case '.':
    case '>':
        Input::key = Key::Period;
        break;
    case '/':
    case '?':
        Input::key = Key::Slash;
        break;
    case ' ':
        Input::key = Key::Space;
    default:
        Input::key = Key::None;
        break;
    }
}

bool Input::keyPressed()
{
    return Input::currentKey() != Key::None;
}

Key Input::currentKey()
{
    return Input::key;
}

void Input::addListener(Key key, std::function<void(Key)> func)
{
}
