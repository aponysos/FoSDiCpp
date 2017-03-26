#include "stdafx.h"
#include "ch02_string.h"

using namespace std;

String::String(const char *init, int l)
  : str(""), len(0)
{
  if (init == nullptr || l < -1) return;

  len = l < 0 ? strlen(init) : l;

  str = new char[len + 1];
  ::memcpy(str, init, len);
  str[len] = '\0';
}

String::String(const String & s)
  : String(s.str, s.len)
{
}

String::~String()
{
  delete[]str;
}

int String::Length()
{
  return len;
}

int String::Find(String pat)
{
  char *p = pat.str, *s = str;
  int i = 0;

  if (*p && *s)
    while (i <= len - pat.len)
      if (*p++ == *s++) {
        if (!*p) return i;
      }
      else {
        ++i; s = str + i; p = pat.str;
      }
  return -1;
}

int String::FastFind(String pat)
{
  boost::scoped_array<int> f(new int[pat.len]);
  pat.Fail(f.get());

  int posP = 0, posS = 0;
  int lenP = pat.len, lenS = len;

  while ((posP < lenP) && (posS < lenS))
    if (pat.str[posP] == str[posS]) {
      ++posP; ++posS;
    }
    else {
      if (posP == 0) ++posS;
      else posP = f[posP - 1] + 1;
    }

  if (posP < lenP) return -1;
  else return posS - lenP;
}

void String::Fail(int *f)
{
  f[0] = -1;
  for (int j = 1; j < Length(); ++j)
  {
    int i = f[j - 1];
    while ((*(str + j) != *(str + i + 1)) && (i >= 0)) i = f[i];
    if (*(str + j) == *(str + i + 1))
      f[j] = i + 1;
    else
      f[j] = -1;
  }
}
