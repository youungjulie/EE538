#include <iostream>
#include <string>
#include <vector>

// Implement your own Queue class!
// TODO: Implement these functions in q.cc.
class Queue {
 private:
  std::vector<int> v_;

 public:
  // Constructor is already defined. No implementation or modification
  // necessary.
  Queue() {}

  // Copy constructor.
  Queue(const Queue& rhs);

  // Return the queue
  std::vector<int> const GetVec() const;

  // Inserts in the back of the queue.
  bool Enqueue(int value);

  // Removes from the front of the queue. If the queue is empty, return false,
  // otherwise true.
  bool Dequeue();

  // Returns true if the queue is empty.
  bool IsEmpty();

  // Returns the value in the front of the queue. If the queue is empty, return
  // -1.
  int Front();

};
