#include "stdafx.h"
#include "complex_quadratic.h"

using namespace std;

Complex::Complex(double real, double image)
  : real_(real), image_(image)
{
}

Complex::Complex(const Complex & c)
  : Complex(c.real_, c.image_)
{
}

Complex & Complex::operator=(const Complex & c)
{
  real_ = c.real_;
  image_ = c.image_;
  return *this;
}

Complex & Complex::operator+=(const Complex & c)
{
  real_ += c.real_;
  image_ += c.image_;
  return *this;
}

Complex & Complex::operator*=(const Complex & c)
{
  double r = real_ * c.real_ - image_ * c.image_;
  double i = real_ * c.image_ + image_ * c.real_;
  real_ = r;
  image_ = i;
  return *this;
}

Complex Complex::operator+(const Complex & c) const
{
  Complex result(*this);
  result += c;
  return result;
}

Complex Complex::operator*(const Complex & c) const
{
  Complex result(*this);
  result *= c;
  return result;
}

Complex Complex::operator-() const
{
  return Complex(-real_, -image_);
}

Complex & Complex::operator-=(const Complex & c)
{
  real_ -= c.real_;
  image_ -= c.image_;
  return *this;
}

Complex Complex::operator-(const Complex & c) const
{
  Complex result(*this);
  result -= c;
  return result;
}

bool Complex::operator==(const Complex & c) const
{
  return real_ == c.real_ && image_ == c.image_;
}

bool Complex::operator!=(const Complex & c) const
{
  return real_ != c.real_ || image_ != c.image_;
}

std::istream & operator>>(std::istream & is, Complex & c)
{
  char cc;
  is >> c.real_;
  is >> c.image_;
  is >> cc;
  if (cc != 'i')
    throw invalid_argument("missing i");
  return is;
}

std::ostream & operator<<(std::ostream & os, const Complex & c)
{
  double r = c.real_, i = c.image_;
  // real part
  if (r != 0 || i == 0)
    os << noshowpos << r;
  // image part
  if (i != 0) {
    if (abs(i) == 1) {
      if (i < 0)
        os << '-';
      else if (r != 0)
        os << '+';
    }
    else
      os << (r != 0 ? showpos : noshowpos) << i;
    os << 'i';
  }
  os << noshowpos;
  return os;
}

Quadratic::Quadratic(double a, double b, double c)
  : a_(a), b_(b), c_(c)
{
}

Quadratic::Quadratic(const Quadratic & q)
  : Quadratic(q.a_, q.b_, q.c_)
{
}

Quadratic & Quadratic::operator=(const Quadratic & q)
{
  a_ = q.a_;
  b_ = q.b_;
  c_ = q.c_;
  return *this;
}

Quadratic & Quadratic::operator+=(const Quadratic & q)
{
  a_ += q.a_;
  b_ += q.b_;
  c_ += q.c_;
  return *this;
}

Quadratic Quadratic::operator+(const Quadratic & q) const
{
  Quadratic result(*this);
  result += q;
  return result;
}

double Quadratic::Evaluate(double x) const
{
  return a_ * x * x + b_ * x + c_;
}

std::pair<Complex, Complex> Quadratic::GetSolutions() const
{
  double delta = b_ * b_ - 4 * a_ * c_;
  double s1 = (-b_ + sqrt(delta)) / 2 / a_;
  double s2 = (-b_ - sqrt(delta)) / 2 / a_;
  return make_pair<Complex, Complex>(s1, s2);
}

std::istream & operator>>(std::istream & is, Quadratic & q)
{
  is >> q.a_;
  return is;
}

std::ostream & operator<<(std::ostream & os, const Quadratic & q)
{
  double a = q.a_, b = q.b_, c = q.c_;
  bool hasNonzeroTerm = false;
  // term x^2
  if (a != 0) {
    if (abs(a) == 1) {
      if (a < 0)
        os << '-';
    } else
      os << noshowpos << a;
    os << "x^2";
    hasNonzeroTerm = true;
  }
  // term x
  if (b != 0) {
    if (abs(b) == 1) {
      if (b < 0)
        os << '-';
      else if (a != 0)
        os << '+';
    }
    else
      os << (hasNonzeroTerm ? showpos : noshowpos) << b;
    os << "x";
    hasNonzeroTerm = true;
  }
  // constant term
  if (c != 0)
    os << (hasNonzeroTerm ? showpos : noshowpos) << c;
  else if (!hasNonzeroTerm)
    os << '0';
  os << noshowpos;
  return os;
}
