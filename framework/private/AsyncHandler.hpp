#ifndef __FRAMEWORK_ASYNC_HANDLER__
#define __FRAMEWORK_ASYNC_HANDLER__

#include <functional>
#include <map>
#include <thread>

class AsyncHandler final {
public:
    AsyncHandler() = delete;
    AsyncHandler(const AsyncHandler &) = delete;
    AsyncHandler(AsyncHandler &&) = delete;
    AsyncHandler &operator=(const AsyncHandler &) = delete;
    AsyncHandler &operator=(AsyncHandler &&) = delete;

    static unsigned int setInterval(const std::function<void()> &callback, unsigned int delay);
    static void clearInterval(unsigned int id);
    static void clearAllIntervals();

private:
    static std::map<unsigned int, std::atomic<bool>> cancelTokens;
    static unsigned int newID;
};

#endif
