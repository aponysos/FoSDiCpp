#pragma once

const int DEFAULT_CAPACITY = 4;

template<class KeyType>
class Deque
{
public:
  Deque(int size = 0, const KeyType * array = nullptr)
    : array_(nullptr), capacity_(0), front_(0), back_(0)
  {
    ExtendCapacity(size);

    for (back_ = 0; back_ < size; ++back_)
      array_[back_] = (array != nullptr ? array[back_] : KeyType());
  }

  ~Deque() { delete[]array_; }

  void Dump(std::ostream & os) const;

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
class Stack
{
public:
  Stack(int size = 0, const KeyType * array = nullptr)
    : deque_(size, array) {}

  void Dump(std::ostream & os) const { deque_.Dump(os); }

public:
  int Size() const { return deque_.Size(); }
  bool IsEmpty() const { return deque_.IsEmpty(); }

public:
  void Push(const KeyType &x) { deque_.PushBack(x); }
  KeyType Peek() { return deque_.PeekBack(); }
  KeyType Pop()  { return deque_.PopBack(); }

private:
  Deque<KeyType> deque_;
};

template<class KeyType>
class Queue
{
public:
  Queue(int size = 0, const KeyType * array = nullptr)
    : deque_(size, array) {}

  void Dump(std::ostream & os) const { deque_.Dump(os); }

public:
  int Size() const { return deque_.Size(); }
  bool IsEmpty() const { return deque_.IsEmpty(); }

public:
  void Add(const KeyType &x) { deque_.PushBack(x); }
  KeyType Peek()  { return deque_.PeekFront(); }
  KeyType Delete()  { return deque_.PopFront(); }

private:
  Deque<KeyType> deque_;
};

template<class KeyType>
void Deque<KeyType>::Dump(std::ostream & os) const
{
  for (int i = 0; i < Size(); ++i)
    os << GetAt(i) << '\n';
}

template<class KeyType>
std::ostream & operator<<(std::ostream & os, const Deque<KeyType> & deque)
{
  deque.Dump(os);
  return os;
}

template<class KeyType>
std::ostream & operator<<(std::ostream & os, const Stack<KeyType> & stack)
{
  stack.Dump(os);
  return os;
}

template<class KeyType>
std::ostream & operator<<(std::ostream & os, const Queue<KeyType> & queue)
{
  queue.Dump(os);
  return os;
}
