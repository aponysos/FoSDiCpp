#include "stdafx.h"
#include "Polynomial.h"

using namespace std;

void Polynomial::NewTerm(int c, int e)
{
  poly_.InsertBack(Term(c, e));
}

int Polynomial::Eval(int x)
{
  int ret = 0;
  for (auto i = poly_.Begin(); i != poly_.End(); ++i)
    ret += (*i).coef * static_cast<int>(pow(x, (*i).exp));
  return ret;
}

Polynomial & Polynomial::operator+=(const Polynomial & b)
{
  auto ai = poly_.Begin(), bi = b.poly_.Begin();
  auto ae = poly_.End(), be = b.poly_.End();

  while (ai != ae && bi != be)
  {
    int exp1 = (*ai).exp, exp2 = (*bi).exp;
    int coef1 = (*ai).coef, coef2 = (*bi).coef;
    if (exp1 > exp2) {
      ++ai; // need not copy
    }
    else if (exp1 < exp2) {
      poly_.InsertBefore(ai, *bi); // copy *bi before ai
      ++bi;
    }
    else {
      int coef3 = coef1 + coef2;
      if (coef3) {
        (*ai).coef = coef3; // refresh (*ai).coef
        ++ai;
        ++bi;
      }
      else {
        poly_.Delete(ai); // remove ai & ++ai
        ++bi;
      }
    }
  }

  while (bi != be)
    poly_.InsertBack(*bi++);

  return *this;
}

Polynomial operator+(const Polynomial & lhs, const Polynomial & rhs)
{
  Polynomial temp(lhs);
  return temp += rhs;
}

std::ostream & operator<<(std::ostream & os, const Term & t)
{
  os << t.coef << 'x' << t.exp;
  return os;
}

std::ostream & operator<<(std::ostream & os, const Polynomial & p)
{
  os << p.poly_;
  return os;
}
