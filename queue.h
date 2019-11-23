#ifndef _QUEUE_H
#define _QUEUE_H

#include "deque.h"

template <typename T>
class Queue {
 public:
  Queue(const Queue<T>&) = delete;
  explicit Queue(int capacity = 8) : deque_(capacity) {}
  ~Queue() { deque_.~Deque(); }
  Queue<T>& operator=(const Queue<T>&) = delete;
  bool IsEmpty(void) const { return deque_.IsEmpty(); }
  int GetSize(void) const { return deque_.GetSize(); }
  T& GetFront(void) { return deque_.GetFront(); }
  const T& GetFront(void) const { return deque_.GetFront(); }
  T& GetBack(void) { return deque_.GetBack(); }
  const T& GetBack(void) const { return deque_.GetBack(); }
  void Push(const T& t) { deque_.PushFront(t); }
  void Pop(void) { deque_.PopBack(); }

 private:
  Deque<T> deque_;
};

#endif  // _QUEUE_H