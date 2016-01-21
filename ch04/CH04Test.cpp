#include "stdafx.h"
#include "CH04Test.h"
#include "LinkedList.h"

using namespace std;

CH04Test::CH04Test(void)
{
  TEST_ADD(CH04Test::testHelloWorld);
  TEST_ADD(CH04Test::testLinkedList);
}

void CH04Test::testHelloWorld(void)
{
  cout << "\nHello, world!" << endl;
}

void CH04Test::testLinkedList(void)
{
  int ai[] = { 1, 2, 3 };
  List<int> l;
  l.Attach(ai, 3);
  ListIterator<int> i(l);
  TEST_ASSERT(i.IsNull() == false);
  TEST_ASSERT(i.NextIsNull() == false);
  TEST_ASSERT(i.Cur() == 1);
  i.Next();
  TEST_ASSERT(*i++ == 2);
  TEST_ASSERT(*i == 3);
  TEST_ASSERT(i.NextIsNull() == true);
  TEST_ASSERT((++i).IsNull() == true);
}
