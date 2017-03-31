#include "stdafx.h"
#include "complex_quadratic.h"

using namespace std;

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

TEST(ch02, testQuadratic)
{
  cout << Quadratic(0, 0, 0) << '\n';
  cout << Quadratic(1, -1, 0) << '\n';
  cout << Quadratic(2, 1, -2) << '\n';
  cout << Quadratic(0, 2, 1) << '\n';
  cout << Quadratic(-2, -2, 0) << '\n';
  cout << Quadratic(-1, 2, -1) << '\n';
  cout << Quadratic(-1, 1, 1) << '\n';
  Quadratic q1(1, 2, -3);
  cout << q1 << '\n';
  EXPECT_EQ(q1.Evaluate(1), 0);
  auto solutions = q1.GetSolutions();
  EXPECT_EQ(solutions.first, 1);
  EXPECT_EQ(solutions.second, -3);
}
