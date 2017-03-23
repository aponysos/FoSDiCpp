#include "stdafx.h"
#include <iomanip>
#include "SparseMatrix.h"

using namespace std;

MatrixNode::MatrixNode(const Triple &tri, bool isHead)
  : isHead_(isHead)
{
  if (isHead_)
    right_ = next_ = this;
  else
    tri_ = tri;
}

Matrix::~Matrix()
{
  if (headnode_ == nullptr) return;
  MatrixNodePtr x = headnode_->right_;
  while (x != headnode_)
  {
    MatrixNodePtr y = x->right_;
    while (y != x)
    {
      MatrixNodePtr yy = y;
      y = yy->right_;
      delete yy;
    }
    MatrixNodePtr xx = x;
    x = x->next_;
    delete xx;
  }
  delete headnode_;
}

std::istream & operator>>(std::istream & is, Matrix & matrix)
{
  // read matrix dimensions
  Triple s;
  is >> s.row >> s.col >> s.val;
  matrix.headnode_ = new MatrixNode(s);

  // set up headnode
  MatrixNodePtr h = matrix.headnode_;
  int p = (s.row > s.col ? s.row : s.col);
  if (p <= 0) {
    h->right_ = h;
    return is;
  }

  // initialize head nodes
  MatrixNodePtr *head = new MatrixNodePtr[p];
  for (int i = 0; i < p; ++i)
    head[i] = new MatrixNode(s, true);
  MatrixNodePtr curRowHead = head[0];

  // read triples
  int curRow = 0;
  for (int i = 0; i < s.val; ++i)
  {
    Triple t;
    is >> t.row >> t.col >> t.val;

    // drop empty rows
    if (t.row > curRow)
    {
      curRowHead->right_ = head[curRow];
      curRow = t.row;
      curRowHead = head[curRow];
    }

    // new node
    MatrixNodePtr newNode = new MatrixNode(t);

    // link node into row list
    curRowHead = curRowHead->right_ = newNode;

    // link node into col list
    MatrixNodePtr curColHead = head[t.col];
    curColHead->next_ = curColHead->next_->down_ = newNode;
  }

  // close last row
  curRowHead->right_ = head[curRow];

  // close all col lists
  for (int i = 0; i < s.col; ++i)
    head[i]->next_->down_ = head[i];

  // link headnodes together
  for (int i = 0; i < p - 1; ++i)
    head[i]->next_ = head[i + 1];
  head[p - 1]->next_ = h;
  h->right_ = head[0];

  delete[]head;

  return is;
}

std::ostream & operator<<(std::ostream & os, Matrix & matrix)
{
  MatrixNodePtr h = matrix.headnode_;
  int maxCol = h->tri_.col;

  int row = 0;
  MatrixNodePtr x = matrix.headnode_->right_;
  while (x != matrix.headnode_)
  {
    // zero row
    for (; row < x->tri_.row; ++row) {
      for (int col = 0; col < maxCol; ++col)
        os << std::setw(4) << 0;
      os << '\n';
    }

    // current row
    MatrixNodePtr y = x->right_;

    // zero row
    if (y == x)
      for (int col = 0; col < maxCol; ++col)
        os << std::setw(4) << 0;
    else // none-zero row
    {
      int col = 0;
      while (y != x)
      {
        // empty col
        for (; col < y->tri_.col; ++col)
          os << std::setw(4) << 0;

        // current col
        os << std::setw(4) << y->tri_.val;

        // next non-zero col
        y = y->right_;
        ++col;
      }

      // zero col
      for (; col < maxCol; ++col)
        os << std::setw(4) << 0;
    }

    os << '\n';

    // next non-zero row
    x = x->next_;
    ++row;
  }

  return os;
}
