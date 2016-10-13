#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H
#include <array>
#include <vector>
#include <memory>

class CircularQueue {
    public:
    CircularQueue(unsigned int initial_capacity = 1);
    ~CircularQueue();
    void Enqueue(int element);
    int Dequeue();
    int QueueSize();
    private:
    // resize function
    int front_;
    int tail_;
    unsigned int size_;
    unsigned int max_size_;
    std::unique_ptr<std::vector<int>> queue_;
};

#endif // CIRCULAR_QUEUE_H
