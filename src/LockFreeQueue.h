#pragma once
#include <atomic>
#include <cstddef> // for std::size_t

template<typename T, std::size_t Size>
class LockFreeQueue {
public:
    LockFreeQueue() : head(0), tail(0) {}

    bool push(const T& item) {
        std::size_t next = (head + 1) % Size;
        if (next == tail.load(std::memory_order_acquire)) {
            return false; // 队列满
        }
        buffer[head] = item;
        head = next;
        return true;
    }

    bool pop(T& item) {
        if (tail.load(std::memory_order_acquire) == head) {
            return false; // 队列空
        }
        item = buffer[tail];
        tail = (tail + 1) % Size;
        return true;
    }

private:
    T buffer[Size];
    std::atomic<std::size_t> head;
    std::atomic<std::size_t> tail;
};