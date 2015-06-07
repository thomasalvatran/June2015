#include <iostream>
using namespace std;
#include "bstack.h"
#include <stack>

int main() {
    cout << "stack IntStack class" << endl;
  IntStack stk;
  cout << stk.isEmpty() << endl;
  if (stk.isEmpty())
    cout << "Empty Stack" << endl;
  stk.Push(123);
  stk.Push(7);
  cout << stk.Top() << endl;
  stk.Pop();
  stk.Push(455);
  stk.Push(456);
  cout << stk.isEmpty() << endl;
  while (stk.isEmpty() == 0) {
    cout << stk.Top() << " ";
    stk.Pop();
  }
  cout << endl;

  cout << "stack STL" << endl;
  stack<int> st;
  if (st.empty())
      cout << "Empty Stack" << endl;
  st.push(123);
  st.push(7);
  st.pop();
  st.push(455);
  st.push(456);
  for (int i = 0; i < st.size(); i++){
     cout << st.top() << " ";
     st.pop();
  }
  cout << st.top() << endl;
}

// 123 455 456
