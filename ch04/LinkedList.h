// Section 4.3 A Reusable Linked List Class
#pragma once

template <class Type> class List;
template <class Type> struct ListIterator;

template <class Type>
class ListNode
{
  friend class List<Type> ;
  friend struct ListIterator<Type>;

public:
  ListNode(const Type & data) : data_(data), llink_(NULL), rlink_(NULL) {}

private:
  Type data_;
  ListNode *llink_;
  ListNode *rlink_;
};

template <class Type>
struct ListIterator
{
  typedef ListNode<Type> NodeType;

public:
  ListIterator(NodeType * cur) : cur_(cur) {}
  ListIterator<Type> & operator=(const ListIterator<Type> & i) { cur_ = i.cur_; return *this; }

private:
  Type & Cur() { return cur_->data_; }
  void Next() { cur_ = cur_->rlink_; }
  void Prev() { cur_ = cur_->llink_; }

public:
  Type & operator*();
  ListIterator<Type> & operator++();
  ListIterator<Type> operator++(int);
  ListIterator<Type> & operator--();
  ListIterator<Type> operator--(int);

public:
  NodeType * cur_;
};

template <class Type>
class List
{
  friend struct ListIterator<Type>;

  typedef ListNode<Type> NodeType;
  typedef ListIterator<Type> IteratorType;

public:
  List();
  ~List();
  List(const List<Type> & l);
  List<Type> & operator=(const List<Type> & l);

public:
  bool IsEmpty() const { return head_->rlink_ == head_; }
  void Dump(std::ostream & os) const;

public:
  IteratorType Begin() const { return IteratorType(head_->rlink_); }
  IteratorType End() const { return IteratorType(head_); }

public:
  void InsertBefore(IteratorType i, const Type & data);
  void InsertAfter(IteratorType i, const Type & data);
  void InsertBack(const Type & data) { InsertBefore(End(), data); }
  void InsertFront(const Type & data) { InsertAfter(End(), data); }

public:
  Type PeekBack() const { return head_->llink_->data_; }
  Type PeekFront() const { return head_->rlink_->data_; }

public:
  Type Delete(IteratorType i);
  Type DeleteBack() { return Delete(--End()); }
  Type DeleteFront() { return Delete(Begin()); }

private:
  NodeType *head_;
};

///////////////////////////////////////////////////////////////////////////////////////////////
template <class Type>
Type & ListIterator<Type>::operator*()
{
  return Cur();
}

template <class Type>
ListIterator<Type> & ListIterator<Type>::operator++()
{
  Next();
  return *this;
}

template <class Type>
ListIterator<Type> ListIterator<Type>::operator++(int)
{
  ListIterator<Type> ii = *this;
  Next();
  return ii;
}

template <class Type>
ListIterator<Type> & ListIterator<Type>::operator--()
{
  Prev();
  return *this;
}

template <class Type>
ListIterator<Type> ListIterator<Type>::operator--(int)
{
  ListIterator<Type> ii = *this;
  Prev();
  return ii;
}

template <class Type>
bool operator==(const ListIterator<Type> & i1, const ListIterator<Type> & i2)
{
  return i1.cur_ == i2.cur_;
}

template <class Type>
bool operator!=(const ListIterator<Type> & i1, const ListIterator<Type> & i2)
{
  return i1.cur_ != i2.cur_;
}

///////////////////////////////////////////////////////////////////////////////////////////////
template <class Type>
List<Type>::List()
  : head_(NULL)
{
  head_ = new NodeType(Type());
  head_->llink_ = head_->rlink_ = head_;
}

template <class Type>
List<Type>::~List()
{
  NodeType * cur = head_;
  NodeType * next = NULL;
  while (next != head_)
  {
    next = cur->rlink_;
    delete cur;
    cur = next;
  }
}

template <class Type>
List<Type>::List(const List<Type> & l)
  : List<Type>()
{
  auto i = l.Begin();
  while (i != l.End())
    InsertBack(*i++);
}

template <class Type>
List<Type> & List<Type>::operator=(const List<Type> & l)
{
  auto i = l.Begin();
  while (i != l.End())
    InsertBack(*i++);
  return *this;
}

template <class Type>
void List<Type>::Dump(std::ostream & os) const
{
  for (auto i = Begin(); i != End(); ++i)
    os << *i << '\n';
}

template <class Type>
std::ostream & operator<<(std::ostream & os, const List<Type> & l)
{
  l.Dump(os);
  return os;
}

template <class Type>
bool operator==(const List<Type> & l1, const List<Type> & l2)
{
  auto i1 = l1.Begin(), i2 = l2.Begin();
  for (; i1 != l1.End() && i2 != l2.End(); ++i1, ++i2)
    if (*i1 != *i2) return false;

  if (i1 != l1.End() || i2 != l2.End())
    return false;

  return true;
}

template <class Type>
void List<Type>::InsertAfter(IteratorType i, const Type & data)
{
  NodeType *newNode = new NodeType(data);
  newNode->rlink_ = i.cur_->rlink_;
  newNode->llink_ = i.cur_;
  i.cur_->rlink_->llink_ = newNode;
  i.cur_->rlink_ = newNode;
}

template <class Type>
void List<Type>::InsertBefore(IteratorType i, const Type & data)
{
  NodeType *newNode = new NodeType(data);
  newNode->llink_ = i.cur_->llink_;
  newNode->rlink_ = i.cur_;
  i.cur_->llink_->rlink_ = newNode;
  i.cur_->llink_ = newNode;
}

template <class Type>
Type List<Type>::Delete(IteratorType i)
{
  if (IsEmpty()) throw std::exception();

  NodeType & cur = *(i++.cur_);
  cur.llink_->rlink_ = cur.rlink_;
  cur.rlink_->llink_ = cur.llink_;

  Type ret = cur.data_;
  delete &cur;
  return ret;
}

///////////////////////////////////////////////////////////////////////////////////////////////
template <class Type>
class Stack
{
public:
  void Dump(std::ostream & os) const { l_.Dump(os); }
  bool IsEmpty() const { return l_.IsEmpty(); }

public:
  void Push(const Type & x) { l_.InsertBack(x); }
  Type Peek() const { return l_.PeekBack(); }
  Type Pop() { return l_.DeleteBack(); }

private:
  List<Type> l_;
};

template <class Type>
std::ostream & operator<<(std::ostream & os, const Stack<Type> & s)
{
  s.Dump(os);
  return os;
}

///////////////////////////////////////////////////////////////////////////////////////////////
template <class Type>
class Queue
{
public:
  void Dump(std::ostream & os) const { l_.Dump(os); }
  bool IsEmpty() const { return l_.IsEmpty(); }

public:
  void Add(const Type & x) { l_.InsertBack(x); }
  Type Peek() const { return l_.PeekFront(); }
  Type Delete() { return l_.DeleteFront(); }

private:
  List<Type> l_;
};

template <class Type>
std::ostream & operator<<(std::ostream & os, const Queue<Type> & s)
{
  s.Dump(os);
  return os;
}
