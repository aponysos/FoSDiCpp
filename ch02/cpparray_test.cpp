#include "stdafx.h"
#include "cpparray.h"

using namespace std;

TEST(ch02, testCppArray)
{
  CppArray ca1;
  cout << ca1 << '\n';
  CppArray ca2(ca1);
  cout << ca2 << '\n';
  CppArray ca3;
  ca3 = ca2;
  cout << ca3 << '\n';
  EXPECT_EQ(ca3[0], 0);
  ca3[0] = 2;
  EXPECT_EQ(ca3[0], 2);
  cout << ca3 << '\n';
}
