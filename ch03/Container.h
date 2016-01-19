#pragma once

const int DEFAULT_CAPACITY = 4;

template<class KeyType>
class Deque
{
public:
  Deque(int size = 0, const KeyType * array = NULL)
    : array_(NULL), capacity_(0), front_(0), back_(0)
  {
    ExtendCapacity(size);

    for (back_ = 0; back_ < size; ++back_)
      array_[back_] = (array != NULL ? array[back_] : KeyType());
  }

  ~Deque() { delete[]array_; }

public:
  int Size() const { return back_ >= front_ ? back_ - front_ : back_ - front_ + capacity_; }
  int Capacity() const { return capacity_; }
  bool IsEmpty() const { return Size() == 0; }
  bool IsFull() const { return Size() == capacity_ - 1; }
  KeyType & GetAt(int idx)
  {
    if (CheckIndex(idx))
      return array_[I2P(idx)];
    else
      throw exception();
  }

  KeyType GetAt(int idx) const
  {
    if (CheckIndex(idx))
      return array_[I2P(idx)];
    else
      throw exception();
  }

public:
  void PushFront(const KeyType &x)
  {
    ExtendCapacity(Size() + 1);
    front_ = Prev(front_);
    array_[front_] = x;
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
    return ret;
  }

  void PushBack(const KeyType &x)
  {
    ExtendCapacity(Size() + 1);
    array_[back_] = x;
    back_ = Next(back_);
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
    return ret;
  }

private:
  int Pos(int pos) const { return pos % capacity_; } // circular position
  int Next(int pos) const { return Pos(pos + 1); } // next position
  int Prev(int pos) const { return Pos(capacity_ + pos - 1); } // previous position
  int I2P(int idx) const { return Pos(front_ + idx); } // index to position

  bool CheckIndex(int idx) const { return 0 <= idx && idx < Size(); }
  bool CheckPosition(int pos) const { return 0 <= pos && pos < capacity_; }

  int CalculateCapacity(int maxSize) const
  {
    int capacity = DEFAULT_CAPACITY;
    while (capacity < maxSize + 1) capacity *= 2; // capacity >= size + 1
    return capacity;
  }

  void ExtendCapacity(int maxSize)
  {
    if (CheckPosition(maxSize)) return;

    int newCapacity = CalculateCapacity(maxSize);

    // copy to newArray
    KeyType *newArray = new KeyType[newCapacity];
    int oldSize = Size();
    for (int i = 0; i < oldSize; ++i)
      newArray[i] = GetAt(i);

    delete[]array_;
    array_ = newArray;
    capacity_ = newCapacity;
    front_ = 0;
    back_ = oldSize;
  }

private:
  KeyType *array_;
  int capacity_; // capacity_ >= Size() + 1
  int front_;
  int back_;
};

template<class KeyType>
class Stack : public Deque<KeyType>
{
public:
  Stack(int size = 0, const KeyType * array = NULL)
    : Deque<KeyType>(size, array) {}

public:
  int Size() const { return Deque<KeyType>::Size(); }
  bool IsEmpty() const { return Deque<KeyType>::IsEmpty(); }

public:
  void Push(const KeyType &x) { Deque<KeyType>::PushBack(x); }
  KeyType Peek() { return Deque<KeyType>::PeekBack(); }
  KeyType Pop()  { return Deque<KeyType>::PopBack(); }

};

template<class KeyType>
class Queue: public Deque<KeyType>
{
public:
  Queue(int size = 0, const KeyType * array = NULL)
    : Deque<KeyType>(size, array) {}

public:
  int Size() const { return Deque<KeyType>::Size(); }
  bool IsEmpty() const { return Deque<KeyType>::IsEmpty(); }

public:
  void Add(const KeyType &x) { Deque<KeyType>::PushBack(x); }
  KeyType Peek()  { return Deque<KeyType>::PeekFront(); }
  KeyType Delete()  { return Deque<KeyType>::PopFront(); }

};

template<class KeyType>
std::ostream & operator<<(std::ostream & os, const Deque<KeyType> & deque)
{
  for (int i = 0; i < deque.Size(); ++i)
    os << deque.GetAt(i) << '\n';
  return os;
}
