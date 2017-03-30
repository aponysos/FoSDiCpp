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
  os << c.real_ << showpos << c.image_ << 'i';
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
  return std::pair<Complex, Complex>();
}

std::istream & operator>>(std::istream & is, Quadratic & q)
{
  is >> q.a_;
  return is;
}

std::string Double2String(double d)
{
  stringstream ss;
  ss << showpos << d;
  string str;
  ss >> str;
  return str;
}

std::ostream & operator<<(std::ostream & os, const Quadratic & q)
{
  os << Double2String(q.a_) << "x^2" << Double2String(q.b_) << "x" << q.c_;
  return os;
}
