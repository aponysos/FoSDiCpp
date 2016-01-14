#include "stdafx.h"
#include "CH02Test.h"
#include "Polynomial.h"
#include "SparseMatrix.h"

using namespace std;

CH02Test::CH02Test(void)
{
  TEST_ADD(CH02Test::testHelloWorld);
  TEST_ADD(CH02Test::testPolynomial);
  TEST_ADD(CH02Test::testSparseMatrix);
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

}
