#ifndef REQUEST_QUEUE_H
#define REQUEST_QUEUE_H

#include "Request.h"
#include <queue>
#include <stdexcept>

class RequestQueue {
public:
    RequestQueue();

    void enqueue(const Request& request);
    Request dequeue();
    Request peek() const;
    bool isEmpty() const;
    size_t size() const;

private:
    std::queue<Request> queue;
};

RequestQueue::RequestQueue() {}

// add a new Request to end of the queue
void RequestQueue::enqueue(const Request& request) {
    queue.push(request);
}

// removes and returns the Request at the front of the queue
Request RequestQueue::dequeue() {
    if (queue.empty()) {
        throw std::out_of_range("Queue is empty. Cannot dequeue.");
    }

    Request frontRequest = queue.front();
    queue.pop();
    return frontRequest;
}

// returns the Request at the front without removing it
Request RequestQueue::peek() const {
    if (queue.empty()) {
        throw std::out_of_range("Queue is empty. Cannot peek.");
    }

    return queue.front();
}

// returns true if the queue is empty, false otherwise
bool RequestQueue::isEmpty() const {
    return queue.empty();
}

// returns the number of Requests in the queue
size_t RequestQueue::size() const {
    return queue.size();
}

#endif