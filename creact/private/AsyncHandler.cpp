#include "AsyncHandler.hpp"

std::map<int, std::atomic<bool>> AsyncHandler::states = {};
std::atomic<int> AsyncHandler::newID{0};

int AsyncHandler::generateID() {
    const auto id = newID++;
    states[id] = true;
    return id;
}

int AsyncHandler::setCall(const std::function<void()> &callback, int delay) {
    const auto id = generateID();
    std::thread([=] {
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        if (states[id].load()) {
            callback();
        }
    }).detach();
    return id;
}

int AsyncHandler::setLoop(const std::function<void()> &callback, int delay) {
    const auto id = generateID();
    std::thread([=] {
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        while (states[id].load()) {
            callback();
            std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        }
    }).detach();
    return id;
}

void AsyncHandler::clear(int id) {
    states[id] = false;
}

void AsyncHandler::clearAll() {
    for (auto &token : states) {
        token.second = false;
    }
}
