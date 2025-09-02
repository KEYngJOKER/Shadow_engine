#pragma once
#include "LockFreeQueue.h"
#include <string>
#include <thread>
#include <atomic>
#include <iostream>
#include <chrono>

class AsyncLogger {
public:
    AsyncLogger() : running(true) {
        logThread = std::thread(&AsyncLogger::processLogs, this);
    }

    ~AsyncLogger() {
        running = false;
        if (logThread.joinable()) logThread.join();
    }

    void log(const std::string& msg) {
        while (!queue.push(msg)) {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
    }

private:
    void processLogs() {
        std::string msg;
        while (running) {
            while (queue.pop(msg)) {
                std::cout << "[LOG] " << msg << std::endl;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }

    LockFreeQueue<std::string, 1024> queue;
    std::atomic<bool> running;
    std::thread logThread;
};