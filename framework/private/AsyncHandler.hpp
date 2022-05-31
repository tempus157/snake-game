#ifndef __FRAMEWORK_ASYNC_HANDLER__
#define __FRAMEWORK_ASYNC_HANDLER__

#include <functional>
#include <future>
#include <map>

class AsyncHandler final {
public:
    AsyncHandler() = delete;
    AsyncHandler(const AsyncHandler &) = delete;
    AsyncHandler(AsyncHandler &&) = delete;
    AsyncHandler &operator=(const AsyncHandler &) = delete;
    AsyncHandler &operator=(AsyncHandler &&) = delete;

    static void setInterval(unsigned int id,
        const std::function<void()> &callback, unsigned int delay);
    static void clearInterval(unsigned int id);
    static void clearAllIntervals();

private:
    static std::map<unsigned int, std::future<void>> intervals;
    static std::map<unsigned int, std::atomic<bool>> cancelTokens;
};

#endif
