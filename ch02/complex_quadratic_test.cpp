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
  cout << c2 << '\n';
}
