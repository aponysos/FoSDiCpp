#pragma once

// ch01 exercises p27 - p29

// p28 EX.1 [Horner's rule]
// evaluate a polynomial at a point x0 using a minimum number of multiplications
// also see ch02 Polynomial
int HornerEval(int *a, int n, int x0);

// p28 EX.2 [print all assignments]
// given n Boolean variables, print all possible combinations of truth values they can assume
void PrintAllAssignments(int n);
void PrintAllAssignments(bool *arr, int m, int n);

// p28 EX.3 [sort triple integer]
// print out the integer values of x, y and z in non-decreasing order
void SortTriple(int *tr);

// p29 EX.7 [factorial function]
// compute n!, recursive & iterative
int Factorial(int n); // iterative
int FactorialR(int n); // recursive

// p29 EX.8 [fibonacci number]
// compute fibonacci number fi, recursive & iterative
// iterative: see Example 1.12, Program 1.21
int FibonacciR(int n); // recursive

// p29 EX.9 EX.10 [binomial coefficient]
// compute binomial coefficient (n, m), recursive & iterative
int BinomialCoefficient(int n, int m);
int BinomialCoefficientR(int n, int m);

// p29 EX.11 [Ackermann's function]
// A(m, n) = n + 1, if m = 0
// A(m, n) = A(m - 1, 1), if n = 0
// A(m, n) = A(m - 1, A(m, n - 1)), otherwise
// recursive & iterative
int Ackermann(int m, int n);
int AckermannR(int m, int n);

// p29 EX.12 [pigeonhole principle]
// find the values a & b, for which the range values are equal, f(a) = f(b)
// the inputs are 1, 2, 3, ... , n
bool PigeonHole(int(*f)(int), int n);

// p29 EX.13
// Given a positive integer n, determine if n is the sum of all of its divisors
bool IsSumOfDivisors(int n);

// p29 EX.15 [powerset]
// recursive function to compute powerset(S)
// elements of S is represented in string 's' of size n, each by one character
void Powerset(const char *s, int n);
void Powerset(const char *s, bool * b, int m, int n); // b is assignment array

// p29 EX.16 [Towers of Hanoi]
// return # of steps
int Hanoi(int n, char from = 'A', char pass = 'B', char to = 'C');
