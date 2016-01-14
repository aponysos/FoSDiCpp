// 2.4 SPARSE MATRICES
#pragma once

class SparseMatrix;

class MatrixTerm
{
  friend class SparseMatrix;

private:
  int row, col, value;
};

class SparseMatrix
{
public:
  SparseMatrix(int r = -1, int c = -1);
  ~SparseMatrix();

  SparseMatrix(const SparseMatrix & sm);
  SparseMatrix & operator=(const SparseMatrix & sm);
  bool operator==(const SparseMatrix & sm);
  
public:
  void NewTerm(int r, int c, int v);
  void NewTerm(const MatrixTerm & mt);
  bool HasTerm(int r, int c, int v) const;
  bool HasTerm(const MatrixTerm & mt) const;

public:
  SparseMatrix Transpose();
  SparseMatrix FastTranspose();

private:
  static const int MAX_TERMS = 128;
  MatrixTerm smArray[MAX_TERMS];
  int rows, cols, terms;
};

