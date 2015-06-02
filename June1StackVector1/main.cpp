#include <iostream>
using namespace std;
#include <vector>

int main(){
//    IntStack stk;
//    if (stk.isEmpty())
//        cout << "Empty Stack" << endl;
//    stk.Push(123);
//    stk.Push(7);
//    cout << stk.Top() << endl;
//    stk.Pop();
//    stk.Push(455);
//    stk.Push(455);
// does not warranty if you push A then B onto the stack removed order
//B then A.
    vector<int> stk;
    if (stk.size() == 0)
        cout << "Empty Stack" << endl;
    stk.push_back(123);
    stk.push_back(7);
    cout << stk.size() << endl;
    stk.pop_back();
    stk.push_back(455);
    stk.push_back(456);
    for (int i = 0; i < stk.size(); i++)
        cout << stk[i] << " ";
    cout << endl;
}
