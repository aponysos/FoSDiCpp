#pragma once

class CH02Test : public Test::Suite
{
public:
  CH02Test(void);

protected:
  void testHelloWorld(void);
  void testPolynomial(void);
  void testSparseMatrix(void);

};
