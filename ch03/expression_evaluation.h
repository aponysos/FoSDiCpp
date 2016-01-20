// Section3.6 Evaluation of Expressions
#pragma once

class Expression
{
public:
  Expression(const std::string & infix);

public:
  std::string Infix2Postfix(void);
  int Evaluate(void);

private:
  static bool IsOperand(char c);
  static int ISP(char c);
  static int ICP(char c);

private:
  std::string infix_;
  std::string postfix_;
};
