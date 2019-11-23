#ifndef _STACK_H
#define _STACK_H

#include "deque.h"

template <typename T>
class Stack {
 public:
  Stack(const Stack<T>&) = delete;
  Stack(int capacity = 8) : deque(capacity) {}
  ~Stack() { deque.~Deque(); }
  Stack<T>& operator=(const Stack<T>&) = delete;
  bool IsEmpty(void) const { return deque.IsEmpty(); }
  int GetSize(void) const { return deque.GetSize(); }
  T& GetTop(void) { return deque.GetBack(); }
  const T& GetTop(void) const { return deque.GetBack(); }
  void Push(const T& t) { deque.PushBack(t); }
  void Pop(void) { deque.PopBack(); }

 private:
  Deque<T> deque;
};

#endif  // _STACK_H