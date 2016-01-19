#include "stdafx.h"
#include <fstream>
#include "Container.h"
#include "mazing_problem.h"

using namespace std;

int Maze::MOVE_VECTOR[8][2] =
{
  { -1, 0 },
  { -1, 1 },
  { 0, 1 },
  { 1, 1 },
  { 1, 0 },
  { 1, -1 },
  { 0, -1 },
  { -1, -1 },
};

Maze::Maze()
  : maze_(NULL), mark_(NULL), m_(0), p_(0)
{
}

Maze::~Maze()
{
  delete[]maze_;
  delete[]mark_;
}

void Maze::Load(const char * file)
{
  ifstream ifs;
  ifs.open(file);
  ifs >> m_ >> p_;
  maze_ = new int[m_ * p_];
  mark_ = new int[m_ * p_];
  for (int i = 0; i < m_ * p_; ++i)
    maze_[i] = mark_[i] = 0;

  string line;
  int i = 0;
  while (ifs >> line)
  {
    for (int j = 0; j < (int)line.length(); ++j)
      maze_[i++] = (line.at(j) == '0' ? 0 : 1);
  }

  ifs.close();
}

void Maze::Path(Offset entrance, Offset exit)
{
  path_.Push(MOVE2(entrance, E));

  while (!path_.IsEmpty())
  {
    Move move = path_.Pop();
    while (move.second <= NW)
    {
      int g = move.first.first + MOVE_VECTOR[move.second][0];
      int h = move.first.second + MOVE_VECTOR[move.second][1];
      if (OFF(g, h) == exit)
        return;
    }
  }

  path_.Push(MOVE2(exit, N));
}

ostream & operator<<(ostream & os, const Maze::Direction & d)
{
  const char * DIRECTION_NAMES[] = 
  {
    "N", "NE","E","SE","S","SW","W","NW"
  };

  os << DIRECTION_NAMES[d];
  return os;
}

ostream & operator<<(ostream & os, const Maze::Move & m)
{
  os << m.first.first << " " << m.first.second << " " << m.second;
  return os;
}

void Maze::PrintPath()
{
  cout << endl << path_ << endl;
}
