#pragma once

// ch02 exercises2 p76 - p77
// one-dimensional c++ array

const int DEFAULT_SIZE = 16;
const double DEFAULT_VALUE = 0.0;

class CppArray
{
public:
  CppArray(int size = DEFAULT_SIZE, double initvalue = DEFAULT_VALUE);
  CppArray(const CppArray & ca);
  CppArray & operator=(const CppArray & ca);
  ~CppArray();

public:
  double & operator[](int i);
  int GetSize() const;
  friend std::istream & operator>>(std::istream & is, CppArray & ca);
  friend std::ostream & operator<<(std::ostream & os, const CppArray & ca);
};
