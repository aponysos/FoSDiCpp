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
  : maze_(nullptr), mark_(nullptr), m_(0), p_(0)
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
    for (int j = 0; j < (int)line.length() && j < p_; ++j)
      maze_[i++] = (line.at(j) == '0' ? 0 : 1);
  }

  ifs.close();
}

bool Maze::Path(Offset entrance, Offset exit)
{
  path_.Push(MOVE2(entrance, N));

  while (!path_.IsEmpty())
  {
    Move move = path_.Pop();
    int i = move.first.first;
    int j = move.first.second;
    int d = move.second;
    while (d <= NW)
    {
      int g = i + MOVE_VECTOR[d][0];
      int h = j + MOVE_VECTOR[d][1];
      Offset next = OFF(g, h); 
      if (next == exit)
      {
        path_.Push(move);
        return true;
      }
      if (CheckBoundary(next) && MazeAt(next) == 0 && MarkAt(next) == 0)
      {
        MarkAt(next) = 1;
        path_.Push(MOVE3(i, j, (Direction)d));
        path_.Push(MOVE2(next, N));
        break;
      }
      else
        ++d;
    }
  }
  
  return false;
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

bool Maze::CheckBoundary(Offset off)
{
  return 0 <= off.first && off.first < m_ && 0 <= off.second && off.second < p_;
}

int Maze::Offset2Index(Offset off)
{
  return off.first * p_ + off.second;
}

int & Maze::MazeAt(Offset off)
{
  return maze_[Offset2Index(off)];
}

int & Maze::MarkAt(Offset off)
{
  return mark_[Offset2Index(off)];
}
