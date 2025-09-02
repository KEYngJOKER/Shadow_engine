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
    AsyncLogger logger;
    DoubleBuffer<GameState> gameBuffer;

    std::atomic<bool> running(true);

    // 游戏逻辑线程
    std::thread logicThread([&]() {
        int frame = 0;
        while (running) {
            auto& writeBuffer = gameBuffer.getWriteBuffer();
            writeBuffer.frameNumber = frame++;
            writeBuffer.entityPositions = { frame, frame + 1, frame + 2 };

            logger.log("Logic updated frame " + std::to_string(writeBuffer.frameNumber));

            gameBuffer.swapBuffers();
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
    });

    // 渲染线程
    std::thread renderThread([&]() {
        while (running) {
            const auto& readBuffer = gameBuffer.getReadBuffer();
            logger.log("Render frame " + std::to_string(readBuffer.frameNumber) +
                       " Entities: " + std::to_string(readBuffer.entityPositions.size()));
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
    });

    std::this_thread::sleep_for(std::chrono::seconds(2));
    running = false;

    logicThread.join();
    renderThread.join();

    return 0;
}