// ch03.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CH03Test.h"

int _tmain(int argc, _TCHAR* argv[])
{
  CH03Test tests;
  Test::TextOutput output(Test::TextOutput::Verbose);

  return tests.run(output);
}
