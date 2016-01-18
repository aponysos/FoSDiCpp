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
  void PushFront(const KeyType &x)
  {
    if (IsFull())
    {
      ExtendCapacity(size_ + 1);
      PushFront(x);
    }
    else
    {
      ++size_;
      front_ = Prev(front_);
      array_[front_] = x;
    }
  }

  KeyType PeekFront()
  {
    if (IsEmpty())
      throw exception();

    return array_[front_];
  }

  KeyType PopFront()
  {
    KeyType ret = PeekFront();
    front_ = Next(front_);
    --size_;
    return ret;
  }

  void PushBack(const KeyType &x)
  {
    if (IsFull())
    {
      ExtendCapacity(size_ + 1);
      PushBack(x);
    }
    else
    {
      ++size_;
      array_[back_] = x;
      back_ = Next(back_);
    }
  }

  KeyType PeekBack()
  {
    if (IsEmpty())
      throw exception();

    return array_[Prev(back_)];
  }

  KeyType PopBack()
  {
    KeyType ret = PeekBack();
    back_ = Prev(back_);
    --size_;
    return ret;
  }

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
