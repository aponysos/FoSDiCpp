#include "stdafx.h"
#include "GeneralizedList.h"
#include "../ch03/Container.h"

using namespace std;

std::istream & operator>>(std::istream & is, GenList & l)
{
  GenList::Dispose(l.first_);

  char c = 0;
  Stack<GenListNodePtr> s;

  // add fake node
  GenListNodePtr fakeNode = new GenListNode((GenListNodePtr)nullptr, (GenListNodePtr)nullptr);
  GenListNodePtr curNode = fakeNode;
  s.Push(curNode);

  while (is >> c)
  {
    switch (c)
    {
    case ')':
      curNode = s.Pop();
      break;
    default:
      GenListNodePtr newNode = (
        c == '('
        ? new GenListNode((GenListNodePtr)nullptr, (GenListNodePtr)nullptr) // list node
        : new GenListNode(c) // atom node
        );

      if (curNode == s.Peek())
        curNode->dlink = newNode;
      else
        curNode->link = newNode;

      if (newNode->tag) // new list node
        s.Push(newNode);
      curNode = newNode;
      break;
    }
  }

  // remove fake node
  l.first_ = fakeNode->dlink;
  delete fakeNode;

  return is;
}

std::ostream & operator<<(std::ostream & os, const GenList & l)
{
  GenList::Dump(os, l.first_);
  return os;
}


GenList::GenList()
  : first_(nullptr)
{
}

GenList::~GenList()
{
  Dispose(first_);
}

GenList & GenList::operator=(const GenList & l)
{
  Dispose(first_);

  first_ = Copy(l.first_);

  return *this;
}

bool GenList::operator==(const GenList & l) const
{
  return Equal(first_, l.first_);
}

int GenList::GetDepth() const
{
  return Depth(first_);
}

//static 
void GenList::Dump(std::ostream & os, const GenListNodePtr p)
{
  if (p == nullptr) return;
  if (p->tag) {
    os << '(';
    Dump(os, p->dlink);
    os << ')';
    Dump(os, p->link);
  }
  else {
    os << p->data;
    Dump(os, p->link);
  }
}

//static 
void GenList::Dispose(GenListNodePtr s)
{
  if (s == nullptr) return;
  if (s->tag)
    Dispose(s->dlink);
  else
    Dispose(s->link);

  delete s;
}

//static 
GenListNodePtr GenList::Copy(const GenListNodePtr s)
{
  if (s == nullptr) return nullptr;

  GenListNodePtr t = nullptr;
  if (s->tag)
    t = new GenListNode(Copy(s->dlink), Copy(s->link));
  else
    t = new GenListNode(s->data, Copy(s->link));

  return t;
}

//static 
bool GenList::Equal(const GenListNodePtr s, const GenListNodePtr t)
{
  if (s == t) return true;
  if (s == nullptr || t == nullptr) return false;

  if (s->tag == t->tag)
  {
    if (s->tag)
      return Equal(s->dlink, t->dlink) && Equal(s->link, t->link);
    else
      return s->data == t->data && Equal(s->link, t->link);
  }

  return false;
}

//static 
int GenList::Depth(const GenListNodePtr s)
{
  if (s == nullptr) return 0;

  GenListNodePtr p = s;
  int ret = 0;
  while (p != nullptr)
  {
    if (p->tag) {
      int d = Depth(p->dlink);
      if (ret < d) ret = d;
    }
    p = p->link;
  }

  return ret + 1;
}
