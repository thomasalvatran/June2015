#ifndef STACKOFINT_H
#define STACKOFINT_H
#include <iostream>
using namespace std;

class StackOfInt {
  int *data; // private no need to declare
  int lenght;
  int ptr;

public:
  StackOfInt(int);
  void push(int);
  int pop();
  int top() const;
  int size() const;
  ~StackOfInt();
};

void Print();

#endif // STACKOFINT_H
