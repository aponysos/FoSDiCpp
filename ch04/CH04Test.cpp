#include "stdafx.h"
#include <fstream>
#include <sstream>
#include "LinkedList.h"
#include "Polynomial.h"
#include "equivalence.h"
#include "SparseMatrix.h"
#include "GeneralizedList.h"

using namespace std;

TEST(ch04, testLinkedList)
{
  List<int> l1;
  EXPECT_TRUE(l1.IsEmpty());
  l1.InsertBack(1);
  l1.InsertBack(2);
  l1.InsertBack(3);
  EXPECT_TRUE(!l1.IsEmpty());
  List<int> l2;
  l2.InsertFront(3);
  l2.InsertFront(2);
  l2.InsertFront(1);
  cout << endl << l1 << endl;
  cout << endl << l2 << endl;
  EXPECT_TRUE(l1 == l2);

  auto i = l1.Begin();
  EXPECT_TRUE(*i == 1);
  ++i;
  EXPECT_TRUE(*i++ == 2);
  EXPECT_TRUE(*i == 3);

  i = l2.End();
  EXPECT_TRUE(*(--i) == 3);
  --i;
  EXPECT_TRUE(*i-- == 2);
  EXPECT_TRUE(*i == 1);

  EXPECT_TRUE(l1.Delete(l1.Begin()) == 1);
  EXPECT_TRUE(l1.PeekFront() == 2);
  EXPECT_TRUE(l1.Delete(--l1.End()) == 3);
  EXPECT_TRUE(l1.PeekBack() == 2);
}

TEST(ch04, testLinkedStackQueue)
{
  Stack<int> s;
  s.Push(1);
  s.Push(2);
  EXPECT_TRUE(s.Peek() == 2);
  s.Push(3);
  cout << endl << s << endl;
  EXPECT_TRUE(s.Pop() == 3);
  EXPECT_TRUE(s.Pop() == 2);
  EXPECT_TRUE(s.Pop() == 1);

  Queue<int> q;
  q.Add(1);
  q.Add(2);
  EXPECT_TRUE(q.Peek() == 1);
  q.Add(3);
  cout << endl << q << endl;
  EXPECT_TRUE(q.Delete() == 1);
  EXPECT_TRUE(q.Delete() == 2);
  EXPECT_TRUE(q.Delete() == 3);
}

TEST(ch04, testPolynomial)
{
  cout << endl;

  Polynomial a;
  a.NewTerm(3, 2);
  a.NewTerm(2, 1);
  a.NewTerm(4, 0);
  cout << a << endl;
  EXPECT_TRUE(a.Eval(1) == 9);
  EXPECT_TRUE(a.Eval(2) == 20);

  Polynomial b;
  b.NewTerm(1, 4);
  b.NewTerm(10, 3);
  b.NewTerm(3, 2);
  cout << b << endl;
  EXPECT_TRUE(b.Eval(1) == 14);
  EXPECT_TRUE(b.Eval(2) == 108);

  Polynomial c;
  c = a + b;
  cout << c << endl;
  EXPECT_TRUE(c.Eval(1) == 23);
  EXPECT_TRUE(c.Eval(2) == 128);

  Polynomial d;
  d = b + a;
  cout << d << endl;
  EXPECT_TRUE(d.Eval(1) == 23);
  EXPECT_TRUE(d.Eval(2) == 128);
}

TEST(ch04, testEquivalenceClass)
{
  EquivalenceClass ec;
  ifstream inFile("equivalence.txt");
  ec.Input(inFile);
  inFile.close();
  cout << endl;
  ec.Output(cout);
  cout << endl;
}

TEST(ch04, testSparseMatrix)
{
  Matrix m;
  ifstream inFile("matrix.txt");
  inFile >> m;
  inFile.close();
  cout << endl << m << endl;
}

TEST(ch04, testGeneralizedList)
{
  GenList gl1;
  istringstream in("a(ab(ca)b)(c(d))ef(dd)");
  in >> gl1;
  cout << endl << gl1 << endl;
  GenList gl2;
  gl2 = gl1;
  cout << endl << gl1 << endl;
  EXPECT_TRUE(gl1 == gl2);
  EXPECT_TRUE(gl2.GetDepth() == 3);
}
