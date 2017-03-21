#include "stdafx.h"
#include "RandomWalkSimulation.h"

using namespace std;

RandomWalkSimulator::RandomWalkSimulator(int nn, int mm, int i, int j)
  : n(nn), m(mm), ibug(i), jbug(j), count(nullptr), moves(0)
{
  if (2 <= n && n <= MAX_N && 2 <= m && m <= MAX_M)
    count = new int[n * m];
  for (int ii = 0; ii < n * m; ++ii)
    count[ii] = 0;
}

RandomWalkSimulator::~RandomWalkSimulator()
{
  delete[]count;
}

int RandomWalkSimulator::MAX_N = 40;
int RandomWalkSimulator::MAX_M = 20;
int RandomWalkSimulator::MAX_MOVES = 50000;
int RandomWalkSimulator::MOVE_VECTOR[8][2] =
{
  {-1, 1}, 
  { 0, 1},
  { 1, 1},
  { 1, 0},
  { 1, -1},
  { 0, -1},
  { -1, -1},
  { -1, 0 },
};

void RandomWalkSimulator::PrintCountArray()
{
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < m; ++j)
      cout << setw(4) << Count(i, j);
    cout << '\n';
  }
  cout << "moves : " << moves << endl;
}

void RandomWalkSimulator::Start()
{
  srand((unsigned int)time(nullptr));

  ++Count(ibug, jbug);

  while (!IsOver() && moves < MAX_MOVES)
    Move();
}

int & RandomWalkSimulator::Count(int i, int j)
{
  return count[i * m + j];
}

bool RandomWalkSimulator::CheckBoundary(int i, int j)
{
  return 0 <= i && i < n && 0 <= j && j < m;
}

void RandomWalkSimulator::Move()
{
  int inext = -1, jnext = -1;
  do {
    int r = rand() % 8;
    inext = ibug + MOVE_VECTOR[r][0];
    jnext = jbug + MOVE_VECTOR[r][1];
  } while (!CheckBoundary(inext, jnext));

  ibug = inext;
  jbug = jnext;
  ++Count(ibug, jbug);
  ++moves;
}

bool RandomWalkSimulator::IsOver()
{
  for (int i = 0; i < n * m; ++i)
    if (count[i] == 0) return false;
  return true;
}
