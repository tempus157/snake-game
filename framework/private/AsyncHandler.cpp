#include "AsyncHandler.hpp"

std::map<unsigned int, std::future<void>> AsyncHandler::intervals = {};
std::map<unsigned int, std::atomic<bool>> AsyncHandler::cancelTokens = {};

void AsyncHandler::setInterval(unsigned int id,
    const std::function<void()> &callback, unsigned int delay) {
    cancelTokens[id] = true;

    intervals[id] = std::async(std::launch::async, [=]() {
        while (cancelTokens[id].load()) {
            callback();
            std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        }
    });
}

void AsyncHandler::clearInterval(unsigned int id) {
    cancelTokens[id] = false;
}
