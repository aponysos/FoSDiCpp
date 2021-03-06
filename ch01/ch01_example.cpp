#include "stdafx.h"
#include "ch01_example.h"

using namespace std;

void SelectionSort(int *a, const int n)
{
  for (int i = 0; i < n; i++)
  {
    // find smallest integer(a[j]) in a[i] to a[n-1]
    int j = i;
    for (int k = j + 1; k < n; ++k)
      if (a[k] < a[j]) j = k;
    // interchage
    swap(a[i], a[j]);
  }
}

int BinarySearch(int *a, const int x, const int n)
{
  for (int left = 0, right = n - 1; left <= right;) // while more elements
  {
    int middle = (left + right) / 2;

    if (x > a[middle])
      left = middle + 1;
    else if (x < a[middle])
      right = middle - 1;
    else
      return middle;
  }

  return -1; // not found
}

int BinarySearch(int *a, const int x, const int left, const int right)
{
  if (left <= right)
  {
    int middle = (left + right) / 2;

    if (x > a[middle])
      return BinarySearch(a, x, middle + 1, right);
    else if (x < a[middle])
      return BinarySearch(a, x, left, middle - 1);
    else
      return middle;
  }

  return -1; // not found
}

void Perm(char *a, const int k, const int n)
{
  if (k == n - 1)
  { // output permutation
    for (int i = 0; i < n; ++i)
      cout << a[i] << " ";
    cout << '\n';
  }
  else // a[k], ..., a[n-1] has more than one permutation. Generate these recursively.
  {
    for (int i = k; i < n; ++i)
    {
      // interchange a[k] and a[i]
      swap(a[k], a[i]);
      
      // all permutations of a[k+1], ..., a[n-1]
      Perm(a, k + 1, n);

      // interchange a[k] and a[i] again, to return to the original configuration
      swap(a[k], a[i]);
    }
  }
}

int Fibonacci(int n)
{
  if (n <= 1) return n; // F0 = 0 and F1 = 1
  else // compute Fn
  {
    int fn = -1, fnm2 = 0, fnm1 = 1;
    for (int i = 2; i <= n; ++i)
    {
      fn = fnm1 + fnm2;
      fnm2 = fnm1;
      fnm1 = fn;
    }

    return fn;
  }
}

int FibonacciR(int n)
{
  if (n <= 1)
    return n;
  else
    return FibonacciR(n - 1) + FibonacciR(n - 2);
}

void Magic(int n)
{
  cout << "magic square of size " << n << endl;

  const int MAX_SIZE = 51; // maximum square size

  // check correctness of n
  if (n < 1 || n > MAX_SIZE)
    throw out_of_range("n out of range [1, 51]");
  else if (!(n % 2))
    throw domain_error("n is even");

  // n is odd. Coxeter's rule can be used
  int square[MAX_SIZE][MAX_SIZE];
  for (int i = 0; i < n; ++i) // initialize square to 0
    for (int j = 0; j < n; ++j)
      square[i][j] = 0;

  // i and j are current position, k and l are next position
  int key = 2, i = 0, j = (n - 1) / 2, k, l;
  square[i][j] = 1; // middle of first row
  while (key <= n * n)
  {
    // move up and left
    k = i - 1 < 0 ? n - 1 : i - 1;
    l = j - 1 < 0 ? n - 1 : j - 1;

    if (square[k][l]) // square occupied, move down
      i = (i + 1) % n;
    else { // square[k][l] is unoccupied
      i = k;
      j = l;
    }

    square[i][j] = key++;
  }

  // output the magic square
  for (i = 0; i < n; ++i) {
    for (j = 0; j < n; ++j)
      cout << setw(4) << square[i][j];
    cout << '\n';
  }
}
