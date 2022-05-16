#include "event.hpp"

void Event::operator()()
{
    for (auto function : functions)
    {
        function();
    }
}

Event &Event::operator+=(std::function<void()> function)
{
    functions.push_back(function);
    return *this;
}

Event &Event::operator-=(std::function<void()> function)
{
    functions.erase(std::remove(functions.begin(), functions.end(), function),
                    functions.end());
    return *this;
}