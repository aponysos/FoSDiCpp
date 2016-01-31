#include "stdafx.h"
#include "../ch03/Container.h"
#include "GeneralizedList.h"

using namespace std;

std::istream & operator>>(std::istream & is, GenList & l)
{
  char c = 0;
  Stack<GenListNodePtr> s;

  // add fake node
  GenListNodePtr fakeNode = new GenListNode((GenListNodePtr)NULL, (GenListNodePtr)NULL);
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
        ? new GenListNode((GenListNodePtr)NULL, (GenListNodePtr)NULL) // list node
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
  : first_(NULL)
{
}

GenList::~GenList()
{
}

GenList & GenList::operator=(const GenList & l)
{
  return *this;
}

bool GenList::operator==(const GenList & l) const
{
  return false;
}

int GenList::GetDepth() const
{
  return 0;
}

//static 
void GenList::Dump(std::ostream & os, const GenListNodePtr p)
{
  if (p == NULL) return;
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
int GenList::equal(GenListNodePtr s, GenListNodePtr t)
{
  return 0;
}

//static 
int GenList::depth(GenListNodePtr s)
{
  return 0;
}
