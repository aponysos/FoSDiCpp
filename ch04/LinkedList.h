// Section 4.3 A Reusable Linked List Class
#pragma once

template <class Type> class List;
template <class Type> class ListIterator;

template <class Type>
class ListNode
{
  friend class List<Type> ;
  friend class ListIterator<Type>;

public:
  ListNode(const Type & data) : data_(data), link_(NULL) {}

private:
  Type data_;
  ListNode *link_;
};

template <class Type>
class List
{
  friend class ListIterator<Type>;

public:
  List() : first_(NULL), last_(NULL) {}

public:
  bool IsEmpty() const { return first_ == NULL; }

public:
  void Attach(const Type & data);
  void Attach(const Type * array, int size);

private:
  ListNode<Type> *first_;
  ListNode<Type> *last_;
};

template <class Type>
class ListIterator
{
public:
  ListIterator(const List<Type> & list) : list_(list), cur_(list.first_) {}
  
public:
  bool IsNull() const { return cur_ == NULL; }
  bool NextIsNull() const { return cur_->link_ == NULL; }

public:
  Type & Cur()
  {
    if (IsNull()) throw std::exception();
    else return cur_->data_;
  }
  void Next()
  {
    if (IsNull()) throw std::exception();
    else cur_ = cur_->link_;
  }

private:
  ListNode<Type> * cur_;
  const List<Type> &list_;
};

template <class Type>
Type & operator*(ListIterator<Type> & i)
{
  return i.Cur();
}

template <class Type>
ListIterator<Type> & operator++(ListIterator<Type> & i)
{
  i.Next();
  return i;
}

template <class Type>
ListIterator<Type> operator++(ListIterator<Type> & i, int)
{
  ListIterator<Type> ii = i;
  i.Next();
  return ii;
}

template <class Type>
void List<Type>::Attach(const Type & data)
{
  ListNode<Type> *newNode = new ListNode<Type>(data);
  if (IsEmpty())
    first_ = last_ = newNode;
  else {
    last_->link_ = newNode;
    last_ = newNode;
  }
}

template <class Type>
void List<Type>::Attach(const Type * array, int size)
{
  if (size <= 0) return;
  if (array == NULL) throw std::exception();
  for (int i = 0; i < size; ++i)
    Attach(array[i]);
}
