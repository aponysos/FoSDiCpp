#include "stdafx.h"
#include "Algorithms01.h"

using namespace std;

TEST(ch01, testSelectionSort)
{
  int a[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
  SelectionSort(a, 10);

  for (int i = 0; i < 10; ++i)
    EXPECT_EQ(a[i], i);
}

TEST(ch01, testBinarySearch)
{
  int a[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

  for (int i = 0; i < 10; ++i)
  {
    int b = BinarySearch(a, i, 10);
    EXPECT_EQ(b, i);
  }

  for (int i = 0; i < 10; ++i)
  {
    int b = BinarySearch(a, i, 0, 9);
    EXPECT_EQ(b, i);
  }
}

TEST(ch01, testPerm)
{
  char a[4] = { '1', '2', '3', };
  cout << endl;
  Perm(a, 0, 3);
}

TEST(ch01, testFibonacci)
{
  int fibo[11] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55 };
  for (int i = 0; i < 11; ++i)
    EXPECT_EQ(Fibonacci(i), fibo[i]);
}

TEST(ch01, testMagic)
{
  cout << endl;
  Magic(0);
  Magic(1);
  Magic(3);
  Magic(5);
  Magic(6);
  Magic(7);
  Magic(52);
}
