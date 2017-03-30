#include "stdafx.h"
#include "complex_quadratic.h"

using namespace std;

TEST(ch02, testComplexQuadratic)
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
}
