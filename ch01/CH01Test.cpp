#include "stdafx.h"
#include "gtest/gtest.h"
#include "Algorithms01.h"

#define ARRAY_LENGTH(__X__) (sizeof(__X__) / sizeof(*(__X__)))

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

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

  EXPECT_EQ(BinarySearch(a, 10, 10), -1);
  EXPECT_EQ(BinarySearch(a, 10, 0, 9), -1);
}

TEST(ch01, testPerm)
{
  char a[4] = { '1', '2', '3', };
  cout << '\n';
  Perm(a, 0, 3);
}

TEST(ch01, testFibonacci)
{
  int fibo[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55 };
  for (int i = 0; i < ARRAY_LENGTH(fibo); ++i) {
    EXPECT_EQ(Fibonacci(i), fibo[i]);
    EXPECT_EQ(FibonacciR(i), fibo[i]);
  }
}

TEST(ch01, testMagic)
{
  cout << '\n';
  Magic(0);
  Magic(1);
  Magic(3);
  Magic(5);
  Magic(6);
  Magic(7);
  Magic(52);
}

TEST(ch01_ex, testPrintAllAssignments)
{
  PrintAllAssignments(2);
  PrintAllAssignments(4);
}

TEST(ch01_ex, testSortTriple)
{
  int tr[] = { 3, 2, 1 };
  SortTriple(tr);
  EXPECT_LE(tr[0], tr[1]);
  EXPECT_LE(tr[1], tr[2]);
}

TEST(ch01_ex, testFactorial)
{
  int fact[] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800 };
  for (int i = 0; i < ARRAY_LENGTH(fact); ++i) {
    EXPECT_EQ(Factorial(i), fact[i]);
    EXPECT_EQ(FactorialR(i), fact[i]);
  }
}

TEST(ch01_ex, testBinomialCoefficient)
{
  int an[] = { 5, 5, 5, 5 };
  int am[] = { 0, 1, 5, 3 };
  int abc[] = { 1, 5, 1, 10 };
  for (int i = 0; i < ARRAY_LENGTH(abc); ++i) {
    EXPECT_EQ(BinomialCoefficient(an[i], am[i]), abc[i]);
    EXPECT_EQ(BinomialCoefficientR(an[i], am[i]), abc[i]);
  }
}

TEST(ch01_ex, testAckermann)
{
  int am[] = { 0, 1, 2, 3, 4 };
  int an[] = { 5, 3, 4, 2, 0 };
  int aa[] = { 6, 5, 11, 29, 13 };
  for (int i = 0; i < ARRAY_LENGTH(aa); ++i) {
    EXPECT_EQ(Ackermann(am[i], an[i]), aa[i]);
    EXPECT_EQ(AckermannR(am[i], an[i]), aa[i]);
  }
}
