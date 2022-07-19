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

    static int setCall(const std::function<void()> &callback, int delay);
    static int setLoop(const std::function<void()> &callback, int delay);
    static void clear(int id);
    static void clearAll();

private:
    static std::map<int, std::atomic<bool>> states;
    static std::atomic<int> newID;
    static int generateID();
};

#endif
