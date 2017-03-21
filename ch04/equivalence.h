// section 4.7 Equivalence Classes
#pragma once

class EquivalenceClass;

struct EquivalenceNode
{
  friend class EquivalenceClass;

  int data;
  EquivalenceNode *link;

  EquivalenceNode(int d) : data(d), link(nullptr) {}
};

class EquivalenceClass
{
  typedef EquivalenceNode * EquivalenceNodePtr;

public:
  EquivalenceClass();
  ~EquivalenceClass();

public:
  void Input(std::istream & is);
  void Output(std::ostream & os);

private:
  void DeleteList(EquivalenceNodePtr node);

private:
  int n_;
  EquivalenceNodePtr * seq_;
  bool * out_;
};
