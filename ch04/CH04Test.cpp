#include "stdafx.h"
#include "CH04Test.h"
#include "LinkedList.h"
#include "Polynomial.h"
#include "SparseMatrix.h"

using namespace std;

CH04Test::CH04Test(void)
{
  TEST_ADD(CH04Test::testHelloWorld);
  TEST_ADD(CH04Test::testLinkedList);
  TEST_ADD(CH04Test::testLinkedStackQueue);
  TEST_ADD(CH04Test::testPolynomial);
  //TEST_ADD(CH04Test::testSparseMatrix);
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

void CH04Test::testPolynomial(void)
{
  cout << endl;

  Polynomial a;
  a.NewTerm(3, 2);
  a.NewTerm(2, 1);
  a.NewTerm(4, 0);
  cout << a << endl;
  TEST_ASSERT(a.Eval(1) == 9);
  TEST_ASSERT(a.Eval(2) == 20);

  Polynomial b;
  b.NewTerm(1, 4);
  b.NewTerm(10, 3);
  b.NewTerm(3, 2);
  cout << b << endl;
  TEST_ASSERT(b.Eval(1) == 14);
  TEST_ASSERT(b.Eval(2) == 108);

  Polynomial c;
  c = a + b;
  cout << c << endl;
  TEST_ASSERT(c.Eval(1) == 23);
  TEST_ASSERT(c.Eval(2) == 128);

  Polynomial d;
  d = b + a;
  cout << d << endl;
  TEST_ASSERT(d.Eval(1) == 23);
  TEST_ASSERT(d.Eval(2) == 128);
}

void CH04Test::testSparseMatrix(void)
{
  SparseMatrix sm1(6, 6);
  sm1.NewTerm(0, 0, 15);
  sm1.NewTerm(0, 3, 22);
  sm1.NewTerm(0, 5, -15);
  sm1.NewTerm(1, 1, 11);
  sm1.NewTerm(1, 2, 3);
  sm1.NewTerm(2, 3, -6);
  sm1.NewTerm(4, 0, 91);
  sm1.NewTerm(5, 2, 28);
  TEST_ASSERT(sm1 == sm1);

  SparseMatrix sm2(6, 6);
  sm2.NewTerm(0, 0, 15);
  sm2.NewTerm(0, 4, 91);
  sm2.NewTerm(1, 1, 11);
  sm2.NewTerm(2, 1, 3);
  sm2.NewTerm(2, 5, 28);
  sm2.NewTerm(3, 0, 22);
  sm2.NewTerm(3, 2, -6);
  sm2.NewTerm(5, 0, -15);
  TEST_ASSERT(sm2 == sm1.Transpose());
  TEST_ASSERT(sm2 == sm1.FastTranspose());

  SparseMatrix sm3(3, 3);
  sm3.NewTerm(0, 0, 1);
  sm3.NewTerm(1, 0, 1);
  sm3.NewTerm(2, 0, 1);
  SparseMatrix sm4(3, 3);
  sm4.NewTerm(0, 0, 1);
  sm4.NewTerm(0, 1, 1);
  sm4.NewTerm(0, 2, 1);
  SparseMatrix sm5(3, 3);
  sm5.NewTerm(0, 0, 1);
  sm5.NewTerm(0, 1, 1);
  sm5.NewTerm(0, 2, 1);
  sm5.NewTerm(1, 0, 1);
  sm5.NewTerm(1, 1, 1);
  sm5.NewTerm(1, 2, 1);
  sm5.NewTerm(2, 0, 1);
  sm5.NewTerm(2, 1, 1);
  sm5.NewTerm(2, 2, 1);
  sm3 *= sm4;
  TEST_ASSERT(sm3 == sm5);
}
