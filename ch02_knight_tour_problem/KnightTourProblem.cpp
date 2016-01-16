#include "stdafx.h"
#include "KnightTourProblem.h"

using namespace std;

ChessBoard::ChessBoard()
{
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < M; ++j) {
      board[i][j] = INIT_BOARD[i][j];
      exits[i][j] = INIT_EXITS[i][j];
    }
}

const int ChessBoard::INIT_BOARD[8][8] =
{
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
};

const int ChessBoard::INIT_EXITS[8][8] =
{
  2, 3, 4, 4, 4, 4, 3, 2,
  3, 4, 6, 6, 6, 6, 4, 3,
  4, 6, 8, 8, 8, 8, 6, 4,
  4, 6, 8, 8, 8, 8, 6, 4,
  4, 6, 8, 8, 8, 8, 6, 4,
  4, 6, 8, 8, 8, 8, 6, 4,
  3, 4, 6, 6, 6, 6, 4, 3,
  2, 3, 4, 4, 4, 4, 3, 2,
};

const int ChessBoard::MOVE_VECTOR[8][2] =
{
  { -2, 1 },
  { -1, 2 },
  { 1, 2 },
  { 2, 1 },
  { 2, -1 },
  { 1, -2 },
  { -1, -2 },
  { -2, -1 },
};

void ChessBoard::PrintBoard()
{
  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j < M; ++j)
      cout << setw(4) << board[i][j];
    cout << '\n';
  }
}

void ChessBoard::Start(int i, int j)
{
  int moves = 0;
  Square crnt(i, j);

  while (MoveTo(crnt, moves))
    ;
  
  if (CheckBoundary(crnt))
    MoveTo(crnt, moves);
}

bool ChessBoard::CheckBoundary(Square s)
{
  return 0 <= s.first && s.first < N && 0 <= s.second && s.second < M;
}

bool ChessBoard::MoveTo(Square &s, int & moves)
{
  if (!CheckBoundary(s))
    return false;

  Board(s) = ++moves;

  Square nextmin(-1, -1);
  for (int k = 0; k < 8; ++k)
  {
    Square next = Next(s, k);

    if (CheckBoundary(next))
    {
      --Exits(next);

      if (Board(next) == 0)
      {
        if (!CheckBoundary(nextmin))
          nextmin = next;
        else if (Exits(nextmin) > Exits(next))
          nextmin = next;
      }
    }
  }

  s = nextmin;
  return Exits(s) > 0;
}

Square ChessBoard::Next(Square crnt, int dir)
{
  return make_pair(
    crnt.first + MOVE_VECTOR[dir][0], 
    crnt.second + MOVE_VECTOR[dir][1]);
}

int & ChessBoard::Board(Square s)
{
  return board[s.first][s.second];
}

int & ChessBoard::Exits(Square s)
{
  return exits[s.first][s.second];
}
