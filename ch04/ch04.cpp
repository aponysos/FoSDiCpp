// ch04.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CH04Test.h"

int _tmain(int argc, _TCHAR* argv[])
{
  CH04Test tests;
  Test::TextOutput output(Test::TextOutput::Verbose);

  return tests.run(output);
}

