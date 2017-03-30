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

std::istream & operator>>(std::istream & is, Complex & c)
{
  char cc;
  is >> c.real_;
  //is >> cc;
  //if (cc != '+')
  //  throw invalid_argument("missing +");
  is >> c.image_;
  is >> cc;
  if (cc != 'i')
    throw invalid_argument("missing i");
  return is;
}

std::ostream & operator<<(std::ostream & os, const Complex & c)
{
  os << c.real_ << (c.image_ >= 0 ? "+" : "") << c.image_ << 'i';
  return os;
}
