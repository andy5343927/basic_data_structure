#ifndef _MAX_KEY_HEAP_H
#define _MAX_KEY_HEAP_H

#include "min_key_heap.h"

template <typename T, typename K>
class MaxHeap {
 public:
  MaxHeap(const MaxHeap<T, K>&) = delete;
  explicit MaxHeap(int capacity = 8) : min_heap_{capacity} {}
  ~MaxHeap() { min_heap_.~MinHeap(); }
  MaxHeap<T, K>& operator=(const MaxHeap<T, K>&) = delete;
  bool IsEmpty(void) const { return min_heap_.IsEmpty(); }
  const T& GetTop(void) const { return min_heap_.GetTop(); }
  void Push(const T& t, const K& key) { min_heap_.Push(t, -key); }
  void Pop(void) { min_heap_.Pop(); }

 private:
  MinKeyHeap<T, K> min_heap_;
};

#endif  // _MAX_KEY_HEAP_H