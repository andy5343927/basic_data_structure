#ifndef _MIN_KEY_HEAP_H
#define _MIN_KEY_HEAP_H

template <typename T, typename K>
class MinKeyHeap {
 public:
  MinKeyHeap(const MinKeyHeap<T, K>&) = delete;
  explicit MinKeyHeap(int capacity = 8)
      : size_(0),
        capacity_(capacity),
        element_(new T[capacity]),
        key_(new K[capacity]) {}
  ~MinKeyHeap() { delete[] element_, delete[] key_; }
  MinKeyHeap<T, K>& operator=(const MinKeyHeap<T, K>&) = delete;
  bool IsEmpty(void) const { return size_ == 0; }
  const T& GetTop(void) const { return element_[1]; }
  void Push(const T& t, const K& key);
  void Pop(void);

 private:
  void DoubleCapacity(void);
  void Swap(int node_1, int node_2);
  int size_, capacity_;
  T* element_;
  K* key_;
};

template <typename T, typename K>
void MinKeyHeap<T, K>::Push(const T& t, const K& key) {
  if (size_ + 1 == capacity_) DoubleCapacity();
  element_[++size_] = t;
  key_[size_] = key;
  int node = size_;
  while (node > 1) {
    if (key_[node] < key_[node / 2]) {
      Swap(node, node / 2);
      node /= 2;
    } else {
      break;
    }
  }
}

template <typename T, typename K>
void MinKeyHeap<T, K>::Pop(void) {
  Swap(1, size_--);
  int node = 1, min;
  while (node <= size_ / 2) {
    min = node;
    if (key_[node * 2] < key_[min]) min = node * 2;
    if (node * 2 + 1 <= size_)
      if (key_[node * 2 + 1] < key_[min]) min = node * 2 + 1;
    if (min != node) {
      Swap(node, min);
      node = min;
    } else {
      break;
    }
  }
}

template <typename T, typename K>
void MinKeyHeap<T, K>::DoubleCapacity(void) {
  capacity_ *= 2;
  T* new_element = new T[capacity_];
  int* new_key = new int[capacity_];
  for (int i = 1; i <= size_; ++i) {
    new_element[i] = element_[i], new_key[i] = key_[i];
  }
  delete element_, delete key_;
  element_ = new_element, key_ = new_key;
}

template <typename T, typename K>
void MinKeyHeap<T, K>::Swap(int node_1, int node_2) {
  T tmp_element = element_[node_1];
  int tmp_key = key_[node_1];
  element_[node_1] = element_[node_2], key_[node_1] = key_[node_2];
  element_[node_2] = tmp_element, key_[node_2] = tmp_key;
}

#endif  // _MIN_KEY_HEAP_H