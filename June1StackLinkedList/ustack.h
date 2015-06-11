#ifndef INTSTACK_H
#define INTSTACK_H
#define IN
#define OUT

struct NodeType;

class IntStack
{
    NodeType *top;
public:
    IntStack();
    IntStack(const IntStack &otherStk);
    ~IntStack();
    bool isEmpty() const;
    bool isFull() const;
    void push( /* in */ int newItem);
    int getTop() const;
    void pop();
};

#endif // INTSTACK_H
