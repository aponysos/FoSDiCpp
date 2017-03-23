// 2.3 THE POLYNOMIAL ABSTRACT DATA TYPE
#pragma once

class Polynomial;

class Term
{
  friend Polynomial;

private:
  int coef; // coefficient
  int exp; // exponent
};

class Polynomial
{
public:
  Polynomial();
  ~Polynomial();

public:
  // add a new term to Polynomial. set finish to new position.
  void NewTerm(int c, int e);

  // Evaluate the polynomial at x and return the result
  int Eval(int x);
  // P27 CH01 EX.1
  // Horner'rule : minimum number of multiplication
  int HornerEval(int x);

  // addition
  Polynomial & operator+=(const Polynomial & poly);

private:
  static const int MAX_TERMS = 128;
  static Term termArray[MAX_TERMS]; // array of terms shared by all Polynomial objects
  static int free; // location of next free location in termArray
  int start, finish;

};

Polynomial operator+(const Polynomial & lhs, const Polynomial & rhs);
