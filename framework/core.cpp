#include "core.hpp"

#include <clocale>
#include <unistd.h>
#include <ncurses.h>

const Vector Vector::zero = Vector(0, 0);
const Vector Vector::one = Vector(1, 1);
const Vector Vector::up = Vector(0, 1);
const Vector Vector::down = Vector(0, -1);
const Vector Vector::left = Vector(-1, 0);
const Vector Vector::right = Vector(1, 0);

Vector::Vector() {}
Vector::Vector(int x, int y) : x(x), y(y) {}

ColorPair::ColorPair() {}
ColorPair::ColorPair(Color foreground, Color background)
    : foreground(foreground), background(background) {}

short ColorPair::getAttribute()
{
    auto lhs = static_cast<int>(foreground) * 10;
    auto rhs = static_cast<int>(background);
    return lhs + rhs;
}

Label *Label::create()
{
    return new Label();
}

Label *Label::setText(std::string text)
{
    this->text = text;
    return this;
}

Label *Label::setPosition(Vector position)
{
    this->position = position;
    return this;
}

Label *Label::setPosition(int x, int y)
{
    position.x = x;
    position.y = y;
    return this;
}

Label *Label::setColor(Optional<ColorPair> color)
{
    this->color = color;
    return this;
}

Label *Label::setColor(Color foreground, Color background)
{
    color = ColorPair(foreground, background);
    return this;
}

bool Label::isActive()
{
    return true;
}

void Label::render()
{
    if (color.hasValue)
    {
        attron(COLOR_PAIR(color.value.getAttribute()));
    }

    mvprintw(position.y, position.x, text.c_str());

    if (color.hasValue)
    {
        attroff(COLOR_PAIR(color.value.getAttribute()));
    }
}

Border *Border::create()
{
    return new Border();
}

Border *Border::setCharacter(unsigned int character)
{
    left = character;
    right = character;
    top = character;
    bottom = character;
    topLeft = character;
    topRight = character;
    bottomLeft = character;
    bottomRight = character;
    return this;
}

Border *Border::setLeft(unsigned int character)
{
    left = character;
    return this;
}

Border *Border::setRight(unsigned int character)
{
    right = character;
    return this;
}

Border *Border::setTop(unsigned int character)
{
    top = character;
    return this;
}

Border *Border::setBottom(unsigned int character)
{
    bottom = character;
    return this;
}

Border *Border::setTopLeft(unsigned int character)
{
    topLeft = character;
    return this;
}

Border *Border::setTopRight(unsigned int character)
{
    topRight = character;
    return this;
}

Border *Border::setBottomLeft(unsigned int character)
{
    bottomLeft = character;
    return this;
}

Border *Border::setBottomRight(unsigned int character)
{
    bottomRight = character;
    return this;
}

Border *Border::setColor(Optional<ColorPair> color)
{
    this->color = color;
    return this;
}

Border *Border::setColor(Color foreground, Color background)
{
    color = ColorPair(foreground, background);
    return this;
}

Window::Window() {}

Window::~Window()
{
    for (auto const object : objects)
    {
        delete object;
    }

    endwin();
}

Window *Window::create()
{
    return new Window();
}

Window *Window::setScale(Vector scale)
{
    this->scale = scale;
    return this;
}

Window *Window::setScale(int x, int y)
{
    scale.x = x;
    scale.y = y;
    return this;
}

Window *Window::setColor(ColorPair color)
{
    this->color = color;
    return this;
}

Window *Window::setColor(Color foreground, Color background)
{
    color.foreground = foreground;
    color.background = background;
    return this;
}

Window *Window::useObject(IObject *object)
{
    objects.push_back(object);
    return this;
}

bool Border::isActive()
{
    return true;
}

void Border::render()
{
    if (color.hasValue)
    {
        attron(COLOR_PAIR(color.value.getAttribute()));
    }

    border(left, right, top, bottom, topLeft, topRight, bottomLeft, bottomRight);

    if (color.hasValue)
    {
        attroff(COLOR_PAIR(color.value.getAttribute()));
    }
}

void Window::init()
{
    initscr();
    resize_term(scale.y, scale.x);
    bkgd(COLOR_PAIR(color.getAttribute()));
}

void Window::render()
{
    clear();

    for (auto object : objects)
    {
        object->render();
    }

    refresh();
}

bool App::progress = true;

App::App()
{
    setlocale(LC_ALL, "");
}

App::~App()
{
    for (auto const window : windows)
    {
        delete window;
    }
}

App *App::create()
{
    return new App();
}

App *App::useWindow(Window *window)
{
    windows.push_back(window);
    return this;
}

int App::execute()
{
    initWindows();
    initColors();

    while (progress)
    {
        renderWindows();
        usleep(20000);
    }

    delete this;
    return 0;
}

void App::initWindows()
{
    for (auto window : windows)
    {
        window->init();
    }
}

void App::initColors()
{
    start_color();
    ColorPair color;

    for (auto foreground = 0; foreground < 8; foreground++)
    {
        for (auto background = 0; background < 8; background++)
        {
            color.foreground = static_cast<Color>(foreground);
            color.background = static_cast<Color>(background);
            init_pair(color.getAttribute(), foreground, background);
        }
    }
}

void App::renderWindows()
{
    for (auto window : windows)
    {
        window->render();
    }
}
