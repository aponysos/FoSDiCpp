// 4.6 THE POLYNOMIAL ABSTRACT DATA TYPE
#pragma once

#include "LinkedList.h"

class Polynomial;

struct Term
{
  int coef; // coefficient
  int exp; // exponent
  Term(int c = 0, int e = 0) : coef(c), exp(e) {}
};

class Polynomial
{
  friend std::ostream & operator<<(std::ostream & os, const Polynomial & poly);

public:
  // add a new term to Polynomial. set finish to new position.
  void NewTerm(int c, int e);

  // Evaluate the polynomial at x and return the result
  int Eval(int x);

  // addition
  Polynomial & operator+=(const Polynomial & poly);

private:
  List<Term> poly_;

};

Polynomial operator+(const Polynomial & lhs, const Polynomial & rhs);
std::ostream & operator<<(std::ostream & os, const Term & t);
std::ostream & operator<<(std::ostream & os, const Polynomial & p);
