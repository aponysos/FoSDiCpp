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
