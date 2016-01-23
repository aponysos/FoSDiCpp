#include "stdafx.h"
#include "CH04Test.h"
#include "LinkedList.h"

using namespace std;

CH04Test::CH04Test(void)
{
  TEST_ADD(CH04Test::testHelloWorld);
  TEST_ADD(CH04Test::testLinkedList);
  TEST_ADD(CH04Test::testLinkedStackQueue);
}

void CH04Test::testHelloWorld(void)
{
  cout << "\nHello, world!" << endl;
}

void CH04Test::testLinkedList(void)
{
  List<int> l1;
  TEST_ASSERT(l1.IsEmpty());
  l1.InsertBack(1);
  l1.InsertBack(2);
  l1.InsertBack(3);
  TEST_ASSERT(!l1.IsEmpty());
  List<int> l2;
  l2.InsertFront(3);
  l2.InsertFront(2);
  l2.InsertFront(1);
  cout << endl << l1 << endl;
  cout << endl << l2 << endl;
  TEST_ASSERT(l1 == l2);

  ListIterator<int> i = l1.Begin();
  TEST_ASSERT(*i == 1);
  ++i;
  TEST_ASSERT(*i++ == 2);
  TEST_ASSERT(*i == 3);

  i = l2.End();
  TEST_ASSERT(*(--i) == 3);
  --i;
  TEST_ASSERT(*i-- == 2);
  TEST_ASSERT(*i == 1);

  TEST_ASSERT(l1.Delete(l1.Begin()) == 1);
  TEST_ASSERT(l1.PeekFront() == 2);
  TEST_ASSERT(l1.Delete(--l1.End()) == 3);
  TEST_ASSERT(l1.PeekBack() == 2);
}

void CH04Test::testLinkedStackQueue(void)
{
  Stack<int> s;
  s.Push(1);
  s.Push(2);
  TEST_ASSERT(s.Peek() == 2);
  s.Push(3);
  cout << endl << s << endl;
  TEST_ASSERT(s.Pop() == 3);
  TEST_ASSERT(s.Pop() == 2);
  TEST_ASSERT(s.Pop() == 1);

  Queue<int> q;
  q.Add(1);
  q.Add(2);
  TEST_ASSERT(q.Peek() == 1);
  q.Add(3);
  cout << endl << q << endl;
  TEST_ASSERT(q.Delete() == 1);
  TEST_ASSERT(q.Delete() == 2);
  TEST_ASSERT(q.Delete() == 3);
}
