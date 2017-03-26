#pragma once

// ch02 exercises1 p74 - p75
// complex numbers & quadratic

class Complex
{
public:
  Complex(double real = 0.0, double image = 0.0);

public:
  Complex operator+(const Complex &c) const;
  Complex operator*(const Complex &c) const;

public:
  friend std::istream & operator>>(std::istream & is, const Complex &c);
  friend std::ostream & operator<<(std::ostream & os, const Complex &c);
};

class Quadratic
{
public:
  Quadratic(double a = 0.0, double b = 0.0, double c = 0.0);

public:
  Quadratic operator+(const Quadratic &q) const;

public:
  friend std::istream & operator>>(std::istream & is, const Quadratic &q);
  friend std::ostream & operator<<(std::ostream & os, const Quadratic &q);

public:
  double Evaluate(double x) const;
  std::pair<Complex, Complex> GetSolutions() const;

private:
  double a_, b_, c_;
};
