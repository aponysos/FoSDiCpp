// ch02_random_walk_simulation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "RandomWalkSimulation.h"

int _tmain(int /*argc*/, _TCHAR* /*argv*/[])
{
  RandomWalkSimulator sim(15, 10, 9, 9);
  sim.Start();
  sim.PrintCountArray();

	return 0;
}

