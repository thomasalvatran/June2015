#include "bstack.h"

IntStack::IntStack()
{
    top = -1;
}
bool IntStack::isEmpty() const{
    return (top == -1);
}
bool IntStack::isFull() const{
    return (top == MAX_DEPTH -1);
}
void IntStack::Push(int newItem){
    data[++top] = newItem;
}
int IntStack::Top() const{
    return data[top];
}
void IntStack::Pop() {
    top --;
}
IntStack::~IntStack()
{

}

