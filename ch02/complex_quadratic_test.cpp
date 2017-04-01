#include "stdafx.h"
#include "complex_quadratic.h"

using namespace std;

string Complex2String(const Complex & c)
{
  ostringstream oss;
  oss << c;
  cout << c << '\n';
  return oss.str();
}

TEST(ch02, testComplexOutput)
{
  EXPECT_EQ(Complex2String(Complex(0, 0)), "0");
  EXPECT_EQ(Complex2String(Complex(1, 0)), "1");
  EXPECT_EQ(Complex2String(Complex(-2, 0)), "-2");
  EXPECT_EQ(Complex2String(Complex(0, 1)), "i");
  EXPECT_EQ(Complex2String(Complex(0, -1)), "-i");
  EXPECT_EQ(Complex2String(Complex(0, 3)), "3i");
  EXPECT_EQ(Complex2String(Complex(0, -2)), "-2i");
  EXPECT_EQ(Complex2String(Complex(1, 1)), "1+i");
  EXPECT_EQ(Complex2String(Complex(2, -2)), "2-2i");
  EXPECT_EQ(Complex2String(Complex(3, -1)), "3-i");
  EXPECT_EQ(Complex2String(Complex(-1, -3)), "-1-3i");
}

TEST(ch02, testComplex)
{
  Complex c1(1, 3);
  cout << c1 << '\n';
  stringstream ss("3-5i");
  Complex c2;
  ss >> c2;
  Complex c3 = c1 + c2;
  cout << c3 << '\n';
  EXPECT_EQ(c3, Complex(4, -2));
  Complex c4 = c1 * c2;
  cout << c4 << '\n';
  EXPECT_EQ(c4, Complex(18, 4));
  EXPECT_EQ(-c4, Complex(-18, -4));
  Complex c5 = c1 - c2;
  cout << c5 << '\n';
  EXPECT_EQ(c5, Complex(-2, 8));
  EXPECT_EQ(c5 != c5, false);
}

string Quadratic2String(const Quadratic & q)
{
  ostringstream oss;
  oss << q;
  cout << q << '\n';
  return oss.str();
}

TEST(ch02, testQuadraticOutput)
{
  EXPECT_EQ(Quadratic2String(Quadratic(0, 0, 0)), "0");
  EXPECT_EQ(Quadratic2String(Quadratic(1, -1, 0)), "x^2-x");
  EXPECT_EQ(Quadratic2String(Quadratic(2, 1, -2)), "2x^2+x-2");
  EXPECT_EQ(Quadratic2String(Quadratic(0, 2, 1)), "2x+1");
  EXPECT_EQ(Quadratic2String(Quadratic(0, -2, 0)), "-2x");
  EXPECT_EQ(Quadratic2String(Quadratic(0, 1, 0)), "x");
  EXPECT_EQ(Quadratic2String(Quadratic(-2, -2, 0)), "-2x^2-2x");
  EXPECT_EQ(Quadratic2String(Quadratic(-1, 0, -1)), "-x^2-1");
  EXPECT_EQ(Quadratic2String(Quadratic(-1, 1, 1)), "-x^2+x+1");
  EXPECT_EQ(Quadratic2String(Quadratic(1, 0, 2)), "x^2+2");
}

TEST(ch02, testQuadratic)
{
  Quadratic q1(1, 2, -3);
  EXPECT_EQ(q1.Evaluate(1), 0);
  auto solutions = q1.GetSolutions();
  EXPECT_EQ(solutions.first, 1);
  EXPECT_EQ(solutions.second, -3);
}
