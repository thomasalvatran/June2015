#ifndef INTSTACK_H
#define INTSTACK_H
#include <vector>

const int MAX_DEPTH = 200;

class IntStack
{
//    vector<int>(MAX_DEPTH);
//    vector<int> data(MAX_DEPTH);
    int data[MAX_DEPTH];
    int top;
public:
    bool isEmpty() const;
    bool isFull() const;
    void Push(int newItem);
    int Top() const;
    void Pop();
    IntStack();
    ~IntStack();
};

#endif // INTSTACK_H
