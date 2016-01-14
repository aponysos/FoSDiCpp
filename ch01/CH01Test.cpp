#include "stdafx.h"
#include "CH01Test.h"
#include "Algorithms01.h"

using namespace std;

CH01Test::CH01Test(void)
{
  TEST_ADD(CH01Test::testHelloWorld);
  TEST_ADD(CH01Test::testSelectionSort);
  TEST_ADD(CH01Test::testBinarySearch);
  TEST_ADD(CH01Test::testPerm);
  TEST_ADD(CH01Test::testFibonacci);
  TEST_ADD(CH01Test::testMagic);
}

void CH01Test::testHelloWorld(void)
{
  cout << "\nHello, world!" << endl;
}

void CH01Test::testSelectionSort(void)
{
  int a[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
  SelectionSort(a, 10);

  for (int i = 0; i < 10; ++i)
    TEST_ASSERT(a[i] == i);
}

void CH01Test::testBinarySearch(void)
{
  int a[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

  for (int i = 0; i < 10; ++i)
  {
    int b = BinarySearch(a, i, 10);
    TEST_ASSERT(b == i);
  }

  for (int i = 0; i < 10; ++i)
  {
    int b = BinarySearch(a, i, 0, 9);
    TEST_ASSERT(b == i);
  }
}

void CH01Test::testPerm(void)
{
  char a[4] = { '1', '2', '3', };
  cout << endl;
  Perm(a, 0, 3);
}

void CH01Test::testFibonacci(void)
{
  int fibo[11] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55 };
  for (int i = 0; i < 11; ++i)
    TEST_ASSERT(Fibonacci(i) == fibo[i]);
}

void CH01Test::testMagic(void)
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
