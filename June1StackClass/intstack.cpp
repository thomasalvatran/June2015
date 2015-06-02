#include "intstack.h"
// instack.cpp

StackOfInt::StackOfInt(int stk_size) { // construct
  data = new int[lenght = stk_size];
  ptr = 0;
}
void StackOfInt::push(int x) {
  if (ptr < lenght)
    data[ptr++] = x;
  else
    throw "overflow";
}
int StackOfInt::pop() {
  if (ptr > 0)
    return data[--ptr];
  else
    throw "overflow";
}
int StackOfInt::top() const {
  if (ptr > 0)
    return data[ptr - 1];
  else
    throw "overflow";
}
int StackOfInt::size() const { return ptr; }
StackOfInt::~StackOfInt() { // destruct
  delete[] data;
}
void Print() { cout << "test" << endl; }
