#pragma once

// Section 1.5.1
//

// Example 1.2 [Selection sort]
// Program 1.6: Selection sort, p22
// Sort the n integers a[0] to a[n-1] into nondecreasing order.
void SelectionSort(int *a, const int n);

// Example 1.3 [Binary search]
// Program 1.9: C++ function for binary search, p24
// Search the sorted array a[0], ..., a[n-1] for x.
int BinarySearch(int *a, const int x, const int n);

// Example 1.4 [Recursive binary search]
// Program 1.10: Recursive implementation of binary search, p27
// Search the sorted array a[left], ..., a[right] for x.
int BinarySearch(int *a, const int x, const int left, const int right);

// Example 1.5 [Permutation generator]
// Program 1.11: Recursive permutation generator, p28
// Generate all the permutations of a[k], ..., a[n-1].
void Perm(char *a, const int k, const int n);

// Example 1.12 [Fibonacci numbers]
// Program 1.21: Fibonacci numbers, p42
// Compute the Fibonacci number Fn.
int Fibonacci(int n);

// Example 1.18 [Magic square]
// Program 1.22: Magic square p49
// Create a magic square of size n, n is odd.
void Magic(int n);

// p28 EX.1 see ch02 Polynomial

// p28 EX.2 [print all assignments]
// Given n Boolean variables, print all possible combinations of truth values they can assume
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

// p29 EX.12 [pigeonhole principle]
// find the values a & b, for which the range values are equal, f(a) = f(b)
// the inputs are 1, 2, 3, ... , n

// p29 EX.13
// Given a positive integer n, determine if n is the sum of all of its divisors

// p29 EX.15 [powerset]
// recursive function to compute powerset(S)

// p29 EX.16 [Towers of Hanoi]

