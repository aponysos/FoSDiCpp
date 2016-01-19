#pragma once

class CH03Test : public Test::Suite
{
public:
  CH03Test(void);

protected:
  void testHelloWorld(void);
  void testDeque(void);
  void testStack(void);
  void testQueue(void);

};
