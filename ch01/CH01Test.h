#pragma once

class CH01Test : public Test::Suite
{
public:
  CH01Test(void);

protected:
  void testHelloWorld(void);
  void testSelectionSort(void);
  void testBinarySearch(void);
  void testPerm(void);
  void testFibonacci(void);
  void testMagic(void);

};
