// 2.8 EXCERSICES 9, p114
// Programming Project : random walk problems simulation
#pragma once

class RandomWalkSimulator
{
public:
  RandomWalkSimulator(int nn, int mm, int i, int j);
  ~RandomWalkSimulator();

public:
  void PrintCountArray();
  void Start();

private:
  int & Count(int i, int j);
  bool CheckBoundary(int i, int j);
  void Move();
  bool IsOver();

private:
  static int MAX_N, MAX_M, MAX_MOVES;
  static int MOVE_VECTOR[8][2];

private:
  int n, m;
  int ibug, jbug;
  int *count;
  int moves;
};
