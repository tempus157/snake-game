#ifndef __FRAMEWORK_UTILS_EVENT__
#define __FRAMEWORK_UTILS_EVENT__

#include <functional>
#include <vector>

struct Event
{
public:
    void operator()();
    Event &operator+=(std::function<void()> function);
    Event &operator-=(std::function<void()> function);

private:
    std::vector<std::function<void()>> functions;
};

#endif
