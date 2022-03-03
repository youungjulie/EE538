#include "q.h"

#include <iostream>
#include <vector>
// Implement each function of `q.h` here.
// Copy constructor.
Queue::Queue(const Queue& rhs) {
    v_ = rhs.GetVec();
}


// Return the queue
std::vector<int> const Queue::GetVec() const{ 
    return v_;
}

// Inserts in the back of the queue.
bool Queue::Enqueue(int value){
    v_.push_back(value);
    return true;
}

// Removes from the front of the queue. If the queue is empty, return false,
// otherwise true.
bool Queue::Dequeue() {
    if (v_.size() == 0) {return false;}
    else {
        v_.erase(v_.begin());
        return true;
    }
}

// Returns true if the queue is empty.
bool Queue::IsEmpty() {
    if (v_.size() == 0) {return true;}
    return false;
}

// Returns the value in the front of the queue. If the queue is empty, return
// -1.
int Queue::Front() {
    if (v_.size() != 0) {
        return (v_[0]);
    }
    else {return -1;}
}