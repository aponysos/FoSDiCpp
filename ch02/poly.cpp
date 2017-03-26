#include "stdafx.h"
#include "poly.h"

using namespace std;

//static 
const int Polynomial::MAX_TERMS;

//static 
Term Polynomial::termArray[MAX_TERMS];

//static 
int Polynomial::free = 0;

Polynomial::Polynomial()
  : start(free), finish(-1)
{
}

Polynomial::~Polynomial()
{
}

void Polynomial::NewTerm(int c, int e)
{
  if (free >= MAX_TERMS) {
    cerr << "Too many terms in polymonials" << endl;
    return;
  }

  termArray[free].coef = c;
  termArray[free].exp = e;
  finish = free++;
}

int Polynomial::Eval(int x)
{
  int ret = 0;
  for (int i = start; i <= finish; ++i)
    ret += termArray[i].coef * static_cast<int>(pow(x, termArray[i].exp));
  return ret;
}

int Polynomial::HornerEval(int x)
{
  int ret = 0;
  for (int i = start; i <= finish; ++i)
    ret += termArray[i].coef * static_cast<int>(pow(x, termArray[i].exp));
  return ret;
}

Polynomial & Polynomial::operator+=(const Polynomial & poly)
{
  int s1 = start, f1 = finish, s2 = poly.start, f2 = poly.finish;

  start = free;

  while (s1 <= f1 && s2 <= f2)
  {
    int exp1 = termArray[s1].exp, exp2 = termArray[s2].exp;
    int coef1 = termArray[s1].coef, coef2 = termArray[s2].coef;

    if (exp1 > exp2) {
      NewTerm(coef1, exp1);
      ++s1;
    }
    else if (exp1 < exp2) {
      NewTerm(coef2, exp2);
      ++s2;
    }
    else {
      int coef3 = coef1 + coef2;
      if (coef3) NewTerm(coef3, exp1);
      ++s1; ++s2;
    }
  }

  // add in remaining terms of *this
  for (; s1 <= f1; ++s1)
    NewTerm(termArray[s1].coef, termArray[s1].exp);

  // add in remaining terms of poly
  for (; s2 <= f2; ++s2)
    NewTerm(termArray[s2].coef, termArray[s2].exp);

  return *this;
}

Polynomial operator+(const Polynomial & lhs, const Polynomial & rhs)
{
  Polynomial temp(lhs);
  return temp += rhs;
}
