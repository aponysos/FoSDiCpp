#pragma once

const int DEFAULT_CAPACITY = 16;

template<class KeyType>
class Deque
{
public:
  Deque(int capacity = DEFAULT_CAPACITY)
    : array_(NULL), capacity_(0), size_(0), front_(0), back_(0)
  {
    capacity_ = capacity <= 0 ? DEFAULT_CAPACITY : capacity;
    array_ = new KeyType[capacity_];
  }

  ~Deque() { delete[]array_; }

  Deque(const KeyType * array, int size)
    : array_(NULL), capacity_(0), size_(0), front_(0), back_(0)
  {
    if (array == NULL || size <= 0)
      throw exception();

    ExtendCapacity(size);
    size_ = size;

    for (int i = 0; i < size_; ++i)
      array_[i] = array[i];

    back_ = Pos(size_);
  }

public:
  int Size() { return size_; }
  int Capacity() { return capacity_; }
  bool IsEmpty() { return size_ == 0; }
  bool IsFull() { return size_ == capacity_; }
  bool CheckSize(int idx) { return 0 <= idx && idx < size_; }
  bool CheckCapacity(int pos) { return 0 <= pos && pos < capacity_; }
  KeyType & GetAt(int idx)
  {
    if (CheckSize(idx))
      return array_[I2P(idx)];
    else
      throw exception();
  }

public:
  void PushFront(const KeyType &x);
  KeyType PeekFront();
  KeyType PopFront();
  void PushBack(const KeyType &x);
  KeyType PeekBack();
  KeyType PopBack();

private:
  int Pos(int pos) { return pos % capacity_; } // circular position
  int Next(int pos) { return Pos(pos + 1); } // next position
  int Prev(int pos) { return pos == 0 ? capacity_ - 1 : Pos(pos - 1);; } // previous position
  int I2P(int idx) { return Pos(front_ + idx); } // index to position

  void ExtendCapacity(int newSize)
  {
    if (CheckCapacity(newSize - 1)) return;

    int newCapacity = capacity_ == 0 ? DEFAULT_CAPACITY : capacity_;
    while (newCapacity < newSize) newCapacity *= 2;
    capacity_ = newCapacity;

    // copy to newArray
    int *newArray = new KeyType[capacity_];
    for (int i = 0; i < size_; ++i)
      newArray[i] = GetAt(i);

    delete[]array_;
    array_ = newArray;
    front_ = 0;
    back_ = Pos(size_);
  }

private:
  KeyType *array_;
  int capacity_;
  int size_;
  int front_;
  int back_;
};
