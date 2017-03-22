#include "stdafx.h"
#include "Container.h"
#include "mazing_problem.h"
#include "expression_evaluation.h"

using namespace std;

TEST(ch03, testDeque)
{
  Deque<int> deq1;
  EXPECT_TRUE(deq1.Capacity() == 4);
  EXPECT_TRUE(deq1.Size() == 0);
  deq1.PushBack(0);
  deq1.PushFront(1);
  deq1.PushBack(2);
  EXPECT_TRUE(deq1.Capacity() == 4);
  EXPECT_TRUE(deq1.Size() == 3);
  deq1.PushFront(3);
  EXPECT_TRUE(deq1.Capacity() == 8);
  EXPECT_TRUE(deq1.Size() == 4);
  EXPECT_TRUE(deq1.PeekBack() == 2);
  EXPECT_TRUE(deq1.PeekFront() == 3);

  EXPECT_TRUE(deq1.PopBack() == 2);
  EXPECT_TRUE(deq1.PopFront() == 3);
  EXPECT_TRUE(deq1.Size() == 2);

  EXPECT_TRUE(deq1.PopBack() == 0);
  EXPECT_TRUE(deq1.PopFront() == 1);
  EXPECT_TRUE(deq1.Size() == 0);

  int ai[] = { 1, 2, 3 };
  Deque<int> deq2(3, ai);
  EXPECT_TRUE(deq2.Capacity() == 4);
  EXPECT_TRUE(deq2.Size() == 3);
  EXPECT_TRUE(deq2.GetAt(0) == 1);
  EXPECT_TRUE(deq2.GetAt(1) == 2);
  EXPECT_TRUE(deq2.GetAt(2) == 3);

  int bi[] = { 1, 2, 3, 4 };
  Deque<int> deq3(4, bi);
  EXPECT_TRUE(deq3.Capacity() == 8);
  EXPECT_TRUE(deq3.Size() == 4);

  Deque<int> deq4(4);
  EXPECT_TRUE(deq4.Capacity() == 8);
  EXPECT_TRUE(deq4.Size() == 4);
  EXPECT_TRUE(deq4.GetAt(0) == 0);
  EXPECT_TRUE(deq4.GetAt(3) == 0);

}

TEST(ch03, testStack)
{
  Stack<int> stk;
  stk.Push(0);
  EXPECT_TRUE(stk.Size() == 1);
  stk.Push(1);
  stk.Push(2);
  cout << endl << stk << endl;
  EXPECT_TRUE(stk.Pop() == 2);
  EXPECT_TRUE(stk.Size() == 2);
  EXPECT_TRUE(stk.Pop() == 1);
}

TEST(ch03, testQueue)
{
  Queue<int> que;
  que.Add(0);
  EXPECT_TRUE(que.Size() == 1);
  que.Add(1);
  que.Add(2);
  cout << endl << que << endl;
  EXPECT_TRUE(que.Delete() == 0);
  EXPECT_TRUE(que.Size() == 2);
  EXPECT_TRUE(que.Delete() == 1);
}

TEST(ch03, testMazingProblem)
{
  Maze m;
  m.Load("maze.txt");
  EXPECT_TRUE(m.Path(OFF(0, 0), OFF(11, 14)) == true);
  m.PrintPath();
}

TEST(ch03, testExpressionEvaluation)
{
  Expression ex("7+5*(2+4)/3-9");
  EXPECT_TRUE(ex.Infix2Postfix() == "7524+*3/+9-");
  EXPECT_TRUE(ex.Evaluate() == 8);
}
