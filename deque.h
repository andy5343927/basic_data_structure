#ifndef _DEQUE_H
#define _DEQUE_H

template <typename T>
class Deque {
 public:
  Deque(const Deque<T>&) = delete;
  explicit Deque(int capacity = 8)
      : front_{0}, back_{0}, capacity_{capacity}, array_{new T[capacity]} {}
  ~Deque() { delete[] array_; }
  Deque<T>& operator=(const Deque<T>) = delete;
  int GetSize(void) const {
    return (front_ > back_) ? (capacity_ - (front_ - back_)) : (back_ - front_);
  }
  bool IsEmpty(void) const { return GetSize() == 0; }
  void PushBack(const T& t);
  void PushFront(const T& t);
  void PopBack(void);
  void PopFront(void);
  const T& GetBack(void) const { return array_[GetPrev(back_)]; }
  T& GetBack(void) { return array_[GetPrev(back_)]; }
  const T& GetFront(void) const { return array_[front_]; }
  T& GetFront(void) { return array_[front_]; }

 private:
  int GetNext(int it) const { return (it + 1) % capacity_; }
  int GetPrev(int it) const { return (it + capacity_ - 1) % capacity_; }
  void Next(int& it) const { it = GetNext(it); }
  void Prev(int& it) const { it = GetPrev(it); }
  void DoubleCapacity(void);
  int front_, back_, capacity_;
  T* array_;
};

template <typename T>
void Deque<T>::PushBack(const T& t) {
  if (GetSize() + 1 == capacity_) DoubleCapacity();
  array_[back_] = t;
  Next(back_);
}

template <typename T>
void Deque<T>::PushFront(const T& t) {
  if (GetSize() + 1 == capacity_) DoubleCapacity();
  Prev(front_);
  array_[front_] = t;
}

template <typename T>
void Deque<T>::PopBack(void) {
  Prev(back_);
  array_[back_].~T();
}

template <typename T>
void Deque<T>::PopFront(void) {
  array_[front_].~T();
  Next(front_);
}

template <typename T>
void Deque<T>::DoubleCapacity(void) {
  auto new_array = new T[capacity_ * 2];
  for (int i = front_; i != back_; GetNext(i)) new_array[i] = array_[i];
  delete[] array_;
  array_ = new_array;
}

#endif  // _DEQUE_H