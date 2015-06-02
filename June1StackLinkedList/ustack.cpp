#include "ustack.h"
#include <stddef.h>
#include <alloca.h>
//#include <stdlib.h>

typedef NodeType *NodePtr;

struct NodeType {
  int data;
  NodePtr link;
};
NodePtr PtrToClone(NodePtr);
//Top is the head pointer to a single linked list
IntStack::IntStack() { top = NULL; }

IntStack::~IntStack() {
  NodePtr tempPtr;
  while (top != NULL)
    tempPtr = top;  //head
  top = top->link;
  delete tempPtr;
}
IntStack::IntStack(const IntStack &otherStk){
    top = PtrToClone(otherStk.top);
}
bool IntStack::isFull() const{
    return(alloca(sizeof(NodeType)) < (int *)sizeof(NodeType)); //???
}
bool IntStack::isEmpty() const{
    return (top == NULL);
}
void IntStack::push(int newItem){
    NodePtr newPtr = new NodeType;
    newPtr->data = newItem;
    newPtr->link = top;
    top = newPtr;
}
int IntStack::getTop() const {
    return top->data;
}
void IntStack::pop(){
    NodePtr tempPtr = top;
    top = top->link;
    delete tempPtr;
}
NodePtr PtrToClone(NodePtr currPtr) {
    NodePtr newPtr = NULL;
    if (currPtr != NULL){
        newPtr = new NodeType;
        newPtr->data = currPtr->data;
        newPtr->link = PtrToClone(currPtr->link);
    }
    return newPtr;
}
