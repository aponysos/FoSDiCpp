#include "stdafx.h"
#include "ch01_exercise.h"

using namespace std;

int HornerEval(int * a, int n, int x0)
{
  int i = n - 1;
  int result = a[i];
  while (i-- > 0)
    result = result * x0 + a[i];
  return result;
}

void PrintAllAssignments(int n)
{
  boost::scoped_array<bool> arr(new bool[n]);
  for (int i = 0; i < n; ++i)
    arr[i] = false;
  PrintAllAssignments(arr.get(), 0, n);
}

void PrintAllAssignments(bool *arr, int m, int n)
{
  if (m == n) {
    for (int i = 0; i < n; ++i)
      cout << boolalpha << arr[i] << " ";
    cout << '\n';
  }
  else {
    PrintAllAssignments(arr, m + 1, n);
    arr[m] ^= true; // xor change arr[m]
    PrintAllAssignments(arr, m + 1, n);
  }
}

void SortTriple(int *tr)
{
  if (tr[0] > tr[1])
    swap(tr[0], tr[1]);
  if (tr[1] > tr[2])
    swap(tr[1], tr[2]);
  if (tr[0] > tr[1])
    swap(tr[0], tr[1]);
}

int Factorial(int n)
{
  int ret = 1;
  for (int i = 1; i <= n; ++i)
    ret *= i;
  return ret;
}

int FactorialR(int n)
{
  if (n <= 1)
    return 1;
  else
    return FactorialR(n - 1) * n;
}

int BinomialCoefficient(int n, int m)
{
  return Factorial(n) / Factorial(n - m) / Factorial(m);
}

int BinomialCoefficientR(int n, int m)
{
  if (m == 0)
    return 1;
  else if (n == m)
    return 1;
  else
    return BinomialCoefficientR(n - 1, m - 1) + BinomialCoefficientR(n - 1, m);
}

int Ackermann(int m, int n)
{
  switch (m)
  {
  case 0:
    return n + 1;
  case 1:
    return n + 2;
  case 2:
    return n * 2 + 3;
  case 3:
    return (1 << (n + 3)) - 3;
  case 4:
  {
    int ret = 2;
    for (int i = 0; i < n + 2; ++i)
      ret = (1 << ret);
    return ret - 3;
  }
  default:
    throw out_of_range("m out of range [0, 4] not supported now");
  }
}

int AckermannR(int m, int n)
{
  if (m == 0)
    return n + 1;
  else if (n == 0)
    return AckermannR(m - 1, 1);
  else
    return AckermannR(m - 1, AckermannR(m, n - 1));
}

bool PigeonHole(int(*f)(int), int n)
{
  bool found = false;
  boost::scoped_array<int> results(new int[n]);
  for (int i = 0; i < n; ++i)
    results[i] = f(i + 1);
  for (int j = 0; j < n; ++j)
    for (int k = j + 1; k < n; ++k)
      if (results[j] == results[k]) {
        cout << "f(" << j << ") == f(" << k << ") == " << results[j] << '\n';
        found = true;
      }
  return found;
}

bool IsSumOfDivisors(int n)
{
  vector<int> divisors;
  for (int i = 1; i <= n / 2; ++i)
    if (n % i == 0)
      divisors.push_back(i);
  int sum = 0;
  for (auto d : divisors)
    sum += d;
  return sum == n;
}

void Powerset(const char * s, int n)
{
  boost::scoped_array<bool> b(new bool[n]);
  for (int i = 0; i < n; ++i)
    b[i] = false;
  Powerset(s, b.get(), 0, n);
}

void Powerset(const char * s, bool * b, int m, int n)
{
  if (m == n) {
    int isEmpty = true;
    for (int i = 0; i < n; ++i)
      if (b[i]) {
        cout << s[i] << " ";
        isEmpty = false;
      }
    if (isEmpty)
      cout << '@';
    cout << '\n';
  }
  else {
    Powerset(s, b, m + 1, n);
    b[m] ^= true; // xor change b[m]
    Powerset(s, b, m + 1, n);
  }
}

int Hanoi(int n, char from, char pass, char to)
{
  if (n == 1) {
    cout << from << " -> " << to << '\n';
    return 1;
  }
  else {
    int nstep = 0;
    nstep += Hanoi(n - 1, from, to, pass);
    cout << from << " -> " << to << '\n';
    ++nstep;
    nstep += Hanoi(n - 1, pass, from, to);
    return nstep;
  }
}
