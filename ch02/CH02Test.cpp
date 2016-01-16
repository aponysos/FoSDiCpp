#include "stdafx.h"
#include "CH02Test.h"
#include "Polynomial.h"
#include "SparseMatrix.h"
#include "String.h"

using namespace std;

CH02Test::CH02Test(void)
{
  TEST_ADD(CH02Test::testHelloWorld);
  TEST_ADD(CH02Test::testPolynomial);
  TEST_ADD(CH02Test::testSparseMatrix);
  TEST_ADD(CH02Test::testString);
}


void CH02Test::testHelloWorld(void)
{
  cout << "\nHello, world!" << endl;
}

void CH02Test::testPolynomial(void)
{
  Polynomial a;
  a.NewTerm(3, 2);
  a.NewTerm(2, 1);
  a.NewTerm(4, 0);
  TEST_ASSERT(a.Eval(1) == 9);
  TEST_ASSERT(a.Eval(2) == 20);

  Polynomial b;
  b.NewTerm(1, 4);
  b.NewTerm(10, 3);
  b.NewTerm(3, 2);
  TEST_ASSERT(b.Eval(1) == 14);
  TEST_ASSERT(b.Eval(2) == 108);

  Polynomial c;
  c = a + b;
  TEST_ASSERT(c.Eval(1) == 23);
  TEST_ASSERT(c.Eval(2) == 128);

  Polynomial d;
  d = b + a;
  TEST_ASSERT(d.Eval(1) == 23);
  TEST_ASSERT(d.Eval(2) == 128);
}

void CH02Test::testSparseMatrix(void)
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

void CH02Test::testString(void)
{
  String s1("abcaabcabcacabcacab");
  String s2("abcaabcabcacacacab");
  String pat("abcabcacab");

  TEST_ASSERT(s1.Length() == 19);
  TEST_ASSERT(s1.Find(pat) == 4);
  TEST_ASSERT(s1.FastFind(pat) == 4);
  TEST_ASSERT(s2.Find(pat) == -1);
  TEST_ASSERT(s2.FastFind(pat) == -1);

}
