#include "stdafx.h"
#include "SparseMatrix.h"
#include "boost\smart_ptr\scoped_array.hpp"

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
}

void SparseMatrix::NewTerm(int r, int c, int v, int pos)
{
  smArray[pos].row = r;
  smArray[pos].col = c;
  smArray[pos].value = v;
  ++terms;
}

void SparseMatrix::NewTerm(int r, int c, int v)
{
  if (terms >= MAX_TERMS) {
    cerr << "Too many terms in sparse matrix" << endl;
    return;
  }

  NewTerm(r, c, v, terms + 1);
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

SparseMatrix SparseMatrix::FastTranspose() const
{
  SparseMatrix b(cols, rows);

  boost::scoped_array<int> rowSize(new int[cols]);
  boost::scoped_array<int> rowStart(new int[cols]);

  if (terms <= 0) return b;

  for (int i = 0; i < cols; ++i) rowSize[i] = 0; // initialize
  for (int i = 0; i < terms; ++i) ++rowSize[smArray[i].col];

  rowStart[0] = 0;
  for (int i = 1; i < cols; ++i) rowStart[i] = rowStart[i - 1] + rowSize[i - 1];

  for (int i = 0; i < terms; ++i)
  {
    int j = rowStart[smArray[i].col];
    b.NewTerm(smArray[i].col, smArray[i].row, smArray[i].value, j); // b.terms added here
    ++rowStart[smArray[i].col];
  }

  return b;
}

int SparseMatrix::StoreSum(int sum, int & lastInResult, int r, int c)
{
  if (sum == 0) return 0;
  
  if (lastInResult < MAX_TERMS - 1)
  {
    NewTerm(r, c, sum, ++lastInResult);
    return 0;
  }
  else
    return 1;
}

SparseMatrix & SparseMatrix::operator*=(const SparseMatrix & b)
{
  if (cols != b.rows)
    throw exception();
  if ((terms == MAX_TERMS) || (b.terms == MAX_TERMS))
    throw exception();

  SparseMatrix result;
  SparseMatrix bXpose = b.FastTranspose();
  int curRowIndex = 0;
  int curRowA = smArray[curRowIndex].row;
  int curRowBegin = curRowIndex;
  int sum = 0;
  int lastInResult = -1;

  // set boundary conditions
  smArray[terms].row = rows;
  bXpose.smArray[b.terms].row = b.rows;
  bXpose.smArray[b.terms].col = -1;

  while (curRowIndex < terms) // generate row curRowA of result
  {
    int curColIndex = 0;
    int curColB = bXpose.smArray[curColIndex].row;

    while (curColIndex <= b.terms) // multiply row curRowA of A by column curColB of b
    {
      if (smArray[curRowIndex].row != curRowA // end of row curRowA of A
        || bXpose.smArray[curColIndex].row != curColB) // end of column curColB of b
      {
        if (result.StoreSum(sum, lastInResult, curRowA, curColB))
          throw exception();

        sum = 0; // reset sum
        curRowIndex = curRowBegin;
        while (bXpose.smArray[curColIndex].row == curColB) // go to next column
          ++curColIndex;
        curColB = bXpose.smArray[curColIndex].row;
      }
      else
      {
        int colA = smArray[curRowIndex].col;
        int colB = bXpose.smArray[curColIndex].col;
        if (colA < colB)
          ++curRowIndex;
        else if (colA > colB)
          ++curColIndex;
        else // colA == colB
          sum += smArray[curRowIndex++].value * bXpose.smArray[curColIndex++].value;
      }
    }

    while (smArray[curRowIndex].row == curRowA) // advanced to next row
      ++curRowIndex;
    curRowBegin = curRowIndex;
    curRowA = smArray[curRowIndex].row;
  }

  result.rows = rows; result.cols = b.cols; result.terms = lastInResult + 1;

  return *this = result;
}
