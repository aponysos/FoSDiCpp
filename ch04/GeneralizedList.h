// Section 4.10 Generalized Lists
#pragma once

struct GenListNode
{
  GenListNode(char d, GenListNode * l = NULL)
    : link(l), data(d), tag(false) {}

  GenListNode(GenListNode * dl, GenListNode * l = NULL)
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
  static int equal(GenListNodePtr s, GenListNodePtr t);
  static int depth(GenListNodePtr s);

private:
  GenListNodePtr first_;
};
