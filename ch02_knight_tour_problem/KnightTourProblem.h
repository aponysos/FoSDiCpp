// 2.8 EXCERSICES 10, p115
// Programming Project : the knight's tour problem
#pragma once

typedef std::pair<int, int> Square;

class ChessBoard
{

public:
  ChessBoard();

public:
  void PrintBoard();
  void Start(int i, int j);

private:
  bool CheckBoundary(Square s);
  bool MoveTo(Square &s, int & moves);
  Square Next(Square crnt, int dir);
  int & Board(Square s);
  int & Exits(Square s);

private:
  static const int N = 8;
  static const int M = 8;
  static const int INIT_BOARD[8][8];
  static const int INIT_EXITS[8][8];
  static const int MOVE_VECTOR[8][2];

private:
  int ikt, jkt;
  int board[N][M];
  int exits[N][M];
};
