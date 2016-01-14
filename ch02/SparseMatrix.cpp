#include "stdafx.h"
#include "SparseMatrix.h"

using namespace std;

//static 
const int SparseMatrix::MAX_TERMS;

SparseMatrix::SparseMatrix(int r, int c)
  :rows(r), cols(c), terms(0)
{
}

SparseMatrix::~SparseMatrix()
{
}

SparseMatrix::SparseMatrix(const SparseMatrix & sm)
  :rows(sm.rows), cols(sm.cols), terms(sm.terms)
{
  for (int i = 0; i < terms; ++i)
    smArray[i] = sm.smArray[i];
}

SparseMatrix & SparseMatrix::operator=(const SparseMatrix & sm)
{
  rows = sm.rows;
  cols = sm.cols;
  terms = sm.terms;
  for (int i = 0; i < terms; ++i)
    smArray[i] = sm.smArray[i];

  return *this;
}

bool SparseMatrix::operator==(const SparseMatrix & sm)
{
  if (rows == sm.rows && cols == sm.cols && terms == sm.terms)
  {
    for (int i = 0; i < terms; ++i)
      if (!sm.HasTerm(smArray[i]))
        return false;
    return true;
  }
  else 
    return false;

  return true;
}

void SparseMatrix::NewTerm(int r, int c, int v)
{
  if (terms >= MAX_TERMS) {
    cerr << "Too many terms in sparse matrix" << endl;
    return;
  }

  smArray[terms].row = r;
  smArray[terms].col = c;
  smArray[terms].value = v;
  ++terms;
}
void SparseMatrix::NewTerm(const MatrixTerm & mt)
{
  NewTerm(mt.row, mt.col, mt.value);
}

bool SparseMatrix::HasTerm(int r, int c, int v) const
{
  for (int i = 0; i < terms; ++i)
    if (smArray[i].row == r && smArray[i].col == c && smArray[i].value == v)
      return true;
  return false;
}

bool SparseMatrix::HasTerm(const MatrixTerm & mt) const
{
  return HasTerm(mt.row, mt.col, mt.value);
}

SparseMatrix SparseMatrix::Transpose()
{
  SparseMatrix b(cols, rows);

  if (terms > 0)
    for (int c = 0; c < cols; ++c)
      for (int i = 0; i <terms; ++i)
        if (smArray[i].col == c)
          b.NewTerm(smArray[i].col, smArray[i].row, smArray[i].value);

  return b;
}

SparseMatrix SparseMatrix::FastTranspose()
{
  SparseMatrix b(cols, rows);

  int *rowSize = new int[cols];
  int *rowStart = new int[cols];
  return b;
}
