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
  TEST_ASSERT(deq1.Capacity() == 4);
  TEST_ASSERT(deq1.Size() == 0);
  deq1.PushBack(0);
  deq1.PushFront(1);
  deq1.PushBack(2);
  TEST_ASSERT(deq1.Capacity() == 4);
  TEST_ASSERT(deq1.Size() == 3);
  deq1.PushFront(3);
  TEST_ASSERT(deq1.Capacity() == 8);
  TEST_ASSERT(deq1.Size() == 4);
  TEST_ASSERT(deq1.PeekBack() == 2);
  TEST_ASSERT(deq1.PeekFront() == 3);

  TEST_ASSERT(deq1.PopBack() == 2);
  TEST_ASSERT(deq1.PopFront() == 3);
  TEST_ASSERT(deq1.Size() == 2);

  TEST_ASSERT(deq1.PopBack() == 0);
  TEST_ASSERT(deq1.PopFront() == 1);
  TEST_ASSERT(deq1.Size() == 0);

  int ai[] = { 1, 2, 3 };
  Deque<int> deq2(3, ai);
  TEST_ASSERT(deq2.Capacity() == 4);
  TEST_ASSERT(deq2.Size() == 3);
  TEST_ASSERT(deq2.GetAt(0) == 1);
  TEST_ASSERT(deq2.GetAt(1) == 2);
  TEST_ASSERT(deq2.GetAt(2) == 3);

  int bi[] = { 1, 2, 3, 4 };
  Deque<int> deq3(4, bi);
  TEST_ASSERT(deq3.Capacity() == 8);
  TEST_ASSERT(deq3.Size() == 4);

  Deque<int> deq4(4);
  TEST_ASSERT(deq4.Capacity() == 8);
  TEST_ASSERT(deq4.Size() == 4);
  TEST_ASSERT(deq4.GetAt(0) == 0);
  TEST_ASSERT(deq4.GetAt(3) == 0);

}
