// Section 4.10 Generalized Lists
#pragma once

struct GenListNode
{
  GenListNode(char d, GenListNode * l = nullptr)
    : link(l), data(d), tag(false) {}

  GenListNode(GenListNode * dl, GenListNode * l = nullptr)
    : link(l), dlink(dl), tag(true) {}

  bool tag; // is data link ?
  union {
    char data;
    GenListNode * dlink;
  };
  GenListNode * link;
};

typedef GenListNode * GenListNodePtr;

class GenList
{
  friend std::istream & operator>>(std::istream & is, GenList & l);
  friend std::ostream & operator<<(std::ostream & os, const GenList & l);

public:
  GenList();
  ~GenList();

public:
  GenList & operator=(const GenList & l);
  bool operator==(const GenList & l) const;
  int GetDepth() const;

private:
  // workhorse
  static void Dump(std::ostream & os, const GenListNodePtr p);
  static void Dispose(GenListNodePtr s);
  static GenListNodePtr Copy(const GenListNodePtr s);
  static bool Equal(const GenListNodePtr s, const GenListNodePtr t);
  static int Depth(const GenListNodePtr s);

private:
  GenListNodePtr first_;
};
