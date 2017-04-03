#include "stdafx.h"
#include "cpparray.h"

using namespace std;

CppArray::CppArray(int size, double initvalue)
  : pArr_(nullptr), sz_(size)
{
  pArr_ = new double[sz_];
  for (int i = 0; i < sz_; ++i)
    pArr_[i] = initvalue;
}

CppArray::CppArray(const CppArray & ca)
  : pArr_(nullptr), sz_(ca.sz_)
{
  pArr_ = new double[sz_];
  for (int i = 0; i < sz_; ++i)
    pArr_[i] = ca.pArr_[i];
}

CppArray & CppArray::operator=(const CppArray & ca)
{
  delete[]pArr_;
  sz_ = ca.sz_;
  pArr_ = new double[sz_];
  for (int i = 0; i < sz_; ++i)
    pArr_[i] = ca.pArr_[i];
  return *this;
}

CppArray::~CppArray()
{
  delete[]pArr_;
  sz_ = 0;
}

double & CppArray::operator[](int i)
{
  if (i < 0 || i >= sz_)
    throw out_of_range("index out of range");
  return pArr_[i];
}

int CppArray::GetSize() const
{
  return sz_;
}

std::istream & operator>>(std::istream & is, CppArray & ca)
{
  is >> ca.sz_;
  for (int i = 0; i < ca.sz_; ++i)
    is >> ca.pArr_[i];
  return is;
}

std::ostream & operator<<(std::ostream & os, const CppArray & ca)
{
  for (int i = 0; i < ca.sz_; ++i)
    os << ca.pArr_[i] << " ";
  return os;
}
