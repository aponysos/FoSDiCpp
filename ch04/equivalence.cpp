#include "stdafx.h"
#include "equivalence.h"
#include "LinkedList.h"

EquivalenceClass::EquivalenceClass()
  : n_(0), seq_(NULL), out_(NULL)
{
}

EquivalenceClass::~EquivalenceClass()
{
  for (int i = 0; i < n_; ++i)
    DeleteList(seq_[i]);
  delete[]seq_;
  delete[]out_;
}

void EquivalenceClass::DeleteList(EquivalenceNodePtr node)
{
  EquivalenceNodePtr next = NULL;
  while (node != NULL)
  {
    next = node->link;
    delete node;
    node = next;
  }
}

void EquivalenceClass::Input(std::istream & is)
{
  is >> n_;
  if (n_ <= 0) return;

  seq_ = new EquivalenceNodePtr[n_];
  out_ = new bool[n_];
  for (int k = 0; k < n_; ++k) {
    seq_[k] = NULL;
    out_[k] = false;
  }

  int i = -1, j = -1;
  while (is >> i >> j)
  {
    EquivalenceNodePtr x = new EquivalenceNode(j);
    x->link = seq_[i];
    seq_[i] = x;
    EquivalenceNodePtr y = new EquivalenceNode(i);
    y->link = seq_[j];
    seq_[j] = y;
  };
}

void EquivalenceClass::Output(std::ostream & os)
{
  for (int i = 0; i < n_; ++i)
  {
    if (out_[i]) continue;

    Queue<int> q;
    q.Add(i);
    os << "class :";

    while (!q.IsEmpty())
    {
      int j = q.Delete();

      if (out_[j]) continue;

      out_[j] = true;
      os << " " << j;

      EquivalenceNodePtr x = seq_[j];
      while (x != NULL)
      {
        int k = x->data;
        if (!out_[k]) q.Add(k);
        x = x->link;
      }
    } // while (!q.IsEmpty())

    os << '\n';
  } // for
}
