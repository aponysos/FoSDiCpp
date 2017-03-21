// ch02_knight_tour_problem.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "KnightTourProblem.h"

int _tmain(int /*argc*/, _TCHAR* /*argv*/[])
{
  ChessBoard cb;
  cb.Start(4, 2);
  cb.PrintBoard();

	return 0;
}

