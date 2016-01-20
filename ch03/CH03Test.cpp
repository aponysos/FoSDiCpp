#include "stdafx.h"
#include "CH03Test.h"
#include "Container.h"
#include "mazing_problem.h"
#include "expression_evaluation.h"

using namespace std;

CH03Test::CH03Test(void)
{
  TEST_ADD(CH03Test::testHelloWorld);
  TEST_ADD(CH03Test::testDeque);
  TEST_ADD(CH03Test::testStack);
  TEST_ADD(CH03Test::testQueue);
  TEST_ADD(CH03Test::testMazingProblem);
  TEST_ADD(CH03Test::testExpressionEvaluation);
}

void CH03Test::testHelloWorld(void)
{
  cout << "\nHello, world!" << endl;
}

void CH03Test::testDeque(void)
{
  Deque<int> deq1;
  TEST_ASSERT(deq1.Capacity() == 4);
  TEST_ASSERT(deq1.Size() == 0);
  deq1.PushBack(0);
  deq1.PushFront(1);
  deq1.PushBack(2);
  TEST_ASSERT(deq1.Capacity() == 4);
  TEST_ASSERT(deq1.Size() == 3);
  deq1.PushFront(3);
  TEST_ASSERT(deq1.Capacity() == 8);
  TEST_ASSERT(deq1.Size() == 4);
  TEST_ASSERT(deq1.PeekBack() == 2);
  TEST_ASSERT(deq1.PeekFront() == 3);

  TEST_ASSERT(deq1.PopBack() == 2);
  TEST_ASSERT(deq1.PopFront() == 3);
  TEST_ASSERT(deq1.Size() == 2);

  TEST_ASSERT(deq1.PopBack() == 0);
  TEST_ASSERT(deq1.PopFront() == 1);
  TEST_ASSERT(deq1.Size() == 0);

  int ai[] = { 1, 2, 3 };
  Deque<int> deq2(3, ai);
  TEST_ASSERT(deq2.Capacity() == 4);
  TEST_ASSERT(deq2.Size() == 3);
  TEST_ASSERT(deq2.GetAt(0) == 1);
  TEST_ASSERT(deq2.GetAt(1) == 2);
  TEST_ASSERT(deq2.GetAt(2) == 3);

  int bi[] = { 1, 2, 3, 4 };
  Deque<int> deq3(4, bi);
  TEST_ASSERT(deq3.Capacity() == 8);
  TEST_ASSERT(deq3.Size() == 4);

  Deque<int> deq4(4);
  TEST_ASSERT(deq4.Capacity() == 8);
  TEST_ASSERT(deq4.Size() == 4);
  TEST_ASSERT(deq4.GetAt(0) == 0);
  TEST_ASSERT(deq4.GetAt(3) == 0);

}

void CH03Test::testStack(void)
{
  Stack<int> stk;
  stk.Push(0);
  TEST_ASSERT(stk.Size() == 1);
  stk.Push(1);
  stk.Push(2);
  TEST_ASSERT(stk.Pop() == 2);
  TEST_ASSERT(stk.Size() == 2);
  TEST_ASSERT(stk.Pop() == 1);
}

void CH03Test::testQueue(void)
{
  Queue<int> que;
  que.Add(0);
  TEST_ASSERT(que.Size() == 1);
  que.Add(1);
  que.Add(2);
  TEST_ASSERT(que.Delete() == 0);
  TEST_ASSERT(que.Size() == 2);
  TEST_ASSERT(que.Delete() == 1);
}

void CH03Test::testMazingProblem(void)
{
  Maze m;
  m.Load("maze.txt");
  TEST_ASSERT(m.Path(OFF(0, 0), OFF(11, 14)) == true);
  m.PrintPath();
}

void CH03Test::testExpressionEvaluation(void)
{
  Expression ex("7+5*(2+4)/3-9");
  TEST_ASSERT(ex.Infix2Postfix() == "7524+*3/+9-");
  TEST_ASSERT(ex.Evaluate() == 8);
}
