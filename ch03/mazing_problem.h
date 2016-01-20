//Section 3.5 A MAZING PROBLEM
#pragma once

#define OFF(i, j) make_pair((i), (j))
#define MOVE2(off, dir) make_pair((off), (dir))
#define MOVE3(i, j, dir) make_pair(OFF((i), (j)), (dir))

class Maze
{
public:
  typedef std::pair<int, int> Offset;
  enum Direction { N, NE, E, SE, S, SW, W, NW };
  typedef std::pair<Offset, Direction> Move;

public:
  Maze();
  ~Maze();

public:
  void Load(const char * file);
  void Path(Offset entrance, Offset exit);
  void PrintPath();

private:
  bool CheckBoundary(Offset off);
  int Offset2Index(Offset off);
  int & MazeAt(Offset off);
  int & MarkAt(Offset off);

private:
  int *maze_;
  int *mark_;
  Stack<Move> path_;
  int m_;
  int p_;
  static int MOVE_VECTOR[8][2];
};
