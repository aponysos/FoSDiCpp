#include "stdafx.h"
#include <fstream>
#include <sstream>
#include "CH04Test.h"
#include "LinkedList.h"
#include "Polynomial.h"
#include "equivalence.h"
#include "SparseMatrix.h"
#include "GeneralizedList.h"

using namespace std;

CH04Test::CH04Test(void)
{
  TEST_ADD(CH04Test::testHelloWorld);
  TEST_ADD(CH04Test::testLinkedList);
  TEST_ADD(CH04Test::testLinkedStackQueue);
  TEST_ADD(CH04Test::testPolynomial);
  TEST_ADD(CH04Test::testEquivalenceClass);
  TEST_ADD(CH04Test::testSparseMatrix);
  TEST_ADD(CH04Test::testGeneralizedList);
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

void CH04Test::testEquivalenceClass(void)
{
  EquivalenceClass ec;
  ifstream inFile("equivalence.txt");
  ec.Input(inFile);
  inFile.close();
  cout << endl;
  ec.Output(cout);
  cout << endl;
}

void CH04Test::testSparseMatrix(void)
{
  Matrix m;
  ifstream inFile("matrix.txt");
  inFile >> m;
  inFile.close();
  cout << endl << m << endl;
}

void CH04Test::testGeneralizedList(void)
{
  GenList gl1;
  istringstream in("a(ab(ca)b)(c(d))ef(dd)");
  in >> gl1;
  cout << endl << gl1 << endl;
  GenList gl2;
  gl2 = gl1;
  cout << endl << gl1 << endl;
  TEST_ASSERT(gl1 == gl2);
  TEST_ASSERT(gl2.GetDepth() == 3);
}
