#include "stdafx.h"
#include "expression_evaluation.h"
#include "Container.h"

using namespace std;

Expression::Expression(const std::string & infix)
  : infix_(infix)
{
}

std::string Expression::Infix2Postfix(void)
{
  postfix_.resize(infix_.length());

  Stack<char> stack(8);
  for (auto i = infix_.begin(); i < infix_.end(); ++i)
  {
    char c = *i;
    if (IsOperand(c))
      stack.Push(c);
    else if (c == ')')
      for (char cc = stack.Pop(); cc != '('; cc = stack.Pop())
        postfix_.push_back(cc);
    else {
      char cc = stack.Pop();
      for (; ISP(cc) <= ICP(c); cc = stack.Pop())
        postfix_.push_back(cc);
      stack.Push(cc);
      stack.Push(c);
    }
  }

  while (!stack.IsEmpty())
    postfix_.push_back(stack.Pop());

  return postfix_;
}

int Expression::Evaluate(void)
{
  Stack<int> stack(8);
  for (auto i = postfix_.begin(); i < postfix_.end(); ++i)
  {
    char c = *i;
    if (IsOperand(c))
      stack.Push(c + '0');
    else
    {
      int op2 = stack.Pop();
      int op1 = stack.Pop();
      int result;
      switch (c)
      {
      case '+':
        result = op1 + op2;
        break;
      case '-':
        result = op1 - op2;
        break;
      case '*':
        result = op1 * op2;
        break;
      case '/':
        result = op1 / op2;
        break;
      default:
        throw exception();
      }
      stack.Push(result);
    }
  }

  return stack.Pop();
}

bool Expression::IsOperand(char c)
{
  return '0' <= c && c <= '9';
}

int Expression::ISP(char c)
{
  int ret = 0;
  switch (c)
  {
  case '+':
  case '-':
    ret = 3;
    break;
  case '*':
  case '/':
    ret = 2;
    break;
  case '(':
    ret = 8;
    break;
  default:
    throw exception();
  }
  return ret;
}

int Expression::ICP(char c)
{
  int ret = 0;
  switch (c)
  {
  case '+':
  case '-':
    ret = 3;
    break;
  case '*':
  case '/':
    ret = 2;
    break;
  case '(':
    ret = 0;
    break;
  default:
    throw exception();
  }
  return ret;
}
