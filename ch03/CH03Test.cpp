#include "stdafx.h"
#include "CH03Test.h"
#include "Container.h"

using namespace std;

CH03Test::CH03Test(void)
{
  TEST_ADD(CH03Test::testHelloWorld);
  TEST_ADD(CH03Test::testDeque);
}

void CH03Test::testHelloWorld(void)
{
  cout << "\nHello, world!" << endl;
}

void CH03Test::testDeque(void)
{
  Deque<int> deq1;
  int ai[] = { 1, 2, 3 };
  Deque<int> deq2(ai, 3);
  TEST_ASSERT(deq2.GetAt(0) == 1);
  TEST_ASSERT(deq2.GetAt(1) == 2);
  TEST_ASSERT(deq2.GetAt(2) == 3);
  deq1.PushBack(0);
  deq1.PushFront(1);
  TEST_ASSERT(deq1.PeekBack() == 0);
  TEST_ASSERT(deq1.PeekFront() == 1);
  TEST_ASSERT(deq1.Size() == 2);
  TEST_ASSERT(deq1.PopBack() == 0);
  TEST_ASSERT(deq1.PopFront() == 1);
  TEST_ASSERT(deq1.IsEmpty());
}