#pragma once

class CH04Test : public Test::Suite
{
public:
  CH04Test(void);

protected:
  void testHelloWorld(void);
  void testLinkedList(void);
  void testLinkedStackQueue(void);
  void testPolynomial(void);
  void testEquivalenceClass(void);
  void testSparseMatrix(void);

};
