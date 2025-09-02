#include "AsyncLogger.h"
#include "DoubleBuffer.h"
#include <vector>
#include <thread>
#include <atomic>
#include <chrono>

struct GameState {
    int frameNumber;
    std::vector<int> entityPositions;
};

int main() {
    std::atomic<bool> running(true);

    // 游戏逻辑线程
    std::thread logicThread([&]() {
        int frame = 0;
        while (running) {
        }
    });

    // 渲染线程
    std::thread renderThread([&]() {
        while (running) {
        }
    });

    std::this_thread::sleep_for(std::chrono::seconds(2));
    running = false;

    logicThread.join();
    renderThread.join();

    return 0;
}