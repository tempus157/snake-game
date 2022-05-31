#include "AsyncHandler.hpp"

std::map<unsigned int, std::atomic<bool>> AsyncHandler::cancelTokens = {};
unsigned int AsyncHandler::newID = 0;

unsigned int AsyncHandler::setInterval(const std::function<void()> &callback, unsigned int delay) {
    const auto id = newID++;
    cancelTokens[id] = true;

    std::thread([=]() {
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        while (cancelTokens[id].load()) {
            callback();
            std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        }
    }).detach();
    return id;
}

void AsyncHandler::clearInterval(unsigned int id) {
    cancelTokens[id] = false;
}

void AsyncHandler::clearAllIntervals() {
    for (auto &token : cancelTokens) {
        token.second = false;
    }
}
