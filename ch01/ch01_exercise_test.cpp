#include "stdafx.h"
#include "ch01_exercise.h"

using namespace std;

TEST(ch01, testHornerEval)
{
  int a[] = { 3, 2, 1 };
  EXPECT_EQ(HornerEval(a, ARRAY_LENGTH(a), 1), 6);
  EXPECT_EQ(HornerEval(a, ARRAY_LENGTH(a), 2), 11);
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
  try {
    Ackermann(-1, 0);
  }
  catch (exception & e) {
    cerr << e.what() << '\n';
  }
  try {
    Ackermann(5, 0);
  }
  catch (exception & e) {
    cerr << e.what() << '\n';
  }
}

TEST(ch01_ex, testPigeonHole)
{
  auto f = [](int i) { return i % 3; };
  EXPECT_EQ(PigeonHole(f, 3), false);
  EXPECT_EQ(PigeonHole(f, 4), true);
}

TEST(ch01_ex, testIsSumOfDivisors)
{
  EXPECT_EQ(IsSumOfDivisors(1), false);
  EXPECT_EQ(IsSumOfDivisors(2), false);
  EXPECT_EQ(IsSumOfDivisors(4), false);
  EXPECT_EQ(IsSumOfDivisors(6), true);
  EXPECT_EQ(IsSumOfDivisors(7), false);
  EXPECT_EQ(IsSumOfDivisors(18), false);
  EXPECT_EQ(IsSumOfDivisors(20), false);
}

TEST(ch01_ex, testPowerset)
{
  Powerset("", 0);
  Powerset("a", 1);
  Powerset("ab", 2);
  Powerset("abc", 3);
  Powerset("abcd", 4);
  Powerset("abcde", 5);
}

TEST(ch01_ex, testHanoi)
{
  cout << "Hanoi(1)" << '\n';
  Hanoi(1);
  cout << "Hanoi(2)" << '\n';
  Hanoi(2);
  cout << "Hanoi(3)" << '\n';
  Hanoi(3);
  cout << "Hanoi(4)" << '\n';
  Hanoi(4);
}
