#pragma once
#include <atomic>

template<typename T>
class DoubleBuffer {
public:
    DoubleBuffer() : frontIndex(0) {}

    T& getWriteBuffer() { return buffers[1 - frontIndex]; }
    const T& getReadBuffer() const { return buffers[frontIndex]; }

    void swapBuffers() { frontIndex = 1 - frontIndex; }

private:
    T buffers[2];
    std::atomic<int> frontIndex;
};