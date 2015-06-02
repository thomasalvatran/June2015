//tinstack.cpp: Test StackOfInt
#include "intstack.h"
#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    const float N = 5;
    StackOfInt stk(N);
    cout << "push" <<' ';
    for (int i = 0; i < N; ++i) {
        stk.push(i);
        cout << i << ' ';
     }
     putchar('\n');
     cout << " pop" <<' ';
    while (stk.size() > 0)
        cout << stk.pop() << ' ';
    cout << endl;
    Print();
}
