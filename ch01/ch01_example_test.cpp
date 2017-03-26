#include "stdafx.h"
#include "ch01_example.h"

using namespace std;

TEST(ch01_examples, testSelectionSort)
{
  int a[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
  SelectionSort(a, ARRAY_LENGTH(a));

  for (int i = 0; i < ARRAY_LENGTH(a); ++i)
    EXPECT_EQ(a[i], i);
}

TEST(ch01_examples, testBinarySearch)
{
  int a[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  int la = ARRAY_LENGTH(a);

  for (int i = 0; i < la; ++i)
  {
    int b = BinarySearch(a, i, la);
    EXPECT_EQ(b, i);
  }

  for (int i = 0; i < la; ++i)
  {
    int b = BinarySearch(a, i, 0, la - 1);
    EXPECT_EQ(b, i);
  }

  EXPECT_EQ(BinarySearch(a, la, la), -1);
  EXPECT_EQ(BinarySearch(a, la, 0, la - 1), -1);
}

TEST(ch01_examples, testPerm)
{
  char a[] = { '1', '2', '3', };
  cout << '\n';
  Perm(a, 0, ARRAY_LENGTH(a));
}

TEST(ch01_examples, testFibonacci)
{
  int fibo[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55 };
  for (int i = 0; i < ARRAY_LENGTH(fibo); ++i) {
    EXPECT_EQ(Fibonacci(i), fibo[i]);
    EXPECT_EQ(FibonacciR(i), fibo[i]);
  }
}

TEST(ch01_examples, testMagic)
{
  cout << '\n';
  try {
    Magic(0);
  }
  catch (exception & e) {
    cerr << e.what() << '\n';
  }
  Magic(1);
  Magic(3);
  Magic(5);
  try {
    Magic(6);
  }
  catch (exception & e) {
    cerr << e.what() << '\n';
  }
  Magic(7);
  try {
    Magic(52);
  }
  catch (exception & e) {
    cerr << e.what() << '\n';
  }
}
