//Mark_R_headington p.441
#include <iostream>
#include "ustack.h"
using namespace std;
int main(){
    IntStack stk;
    if (stk.isEmpty())  //true
        cout << "Stack Empty" << endl;
    stk.push(111);
    stk.push(112);
    stk.push(113);
    stk.pop();
    stk.push(777);

//    while (stk.isEmpty() == 0){
    while (!stk.isEmpty()){
        cout << stk.getTop() << " ";
        stk.pop();
    }
    cout << endl;
    return 0;
}
//Stack Empty
//777 112 111

