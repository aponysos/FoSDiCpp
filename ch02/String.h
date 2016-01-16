// 2.6 THE STRING ADT
#pragma once

class String
{
public:
  String(const char *init = "", int l = -1);
  String(const String & s);
  ~String();

public:
  int Length();

public:
  int Find(String pat);
  int FastFind(String pat);

private:
  void Fail(int *f);

private:
  char *str;
  int len;
};
