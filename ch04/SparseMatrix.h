// 4.8 SPARSE MATRICES
#pragma once

class Matrix;

struct Triple { int val, row, col; };

class MatrixNode
{
  friend class Matrix;
  friend std::istream & operator>>(std::istream & is, Matrix & matrix);
  friend std::ostream & operator<<(std::ostream & os, Matrix & matrix);

private:
  MatrixNode(const Triple &tri, bool isHead = false);

private:
  MatrixNode *down_, *right_;
  bool isHead_;
  union {
    MatrixNode *next_;
    Triple tri_;
  };
};

typedef MatrixNode * MatrixNodePtr;

class Matrix
{
  friend std::istream & operator>>(std::istream & is, Matrix & matrix);
  friend std::ostream & operator<<(std::ostream & os, Matrix & matrix);

public:
  ~Matrix();

private:
  MatrixNodePtr headnode_;
};

