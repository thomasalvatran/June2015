#include "chartree.h"
#include <stddef.h>

//class TreeNode { //classes default to private access modifiers and in structs default is public
//public:
struct TreeNode {
  char data;
  NodePtr lLink;
  NodePtr rLink;
  TreeNode(char, NodePtr, NodePtr); // ctor
};

TreeNode::TreeNode(char someChar, NodePtr leftPtr, NodePtr rightPtr) {
  data = someChar;
  lLink = leftPtr;
  rLink = rightPtr;
}

CharTree::CharTree() {
    rootPtr = NULL;
}

CharTree::~CharTree() {}

bool CharTree::isEmpty() const {
    return (rootPtr == NULL);
}

void CharTree::BuildRoot(char someChar){
    rootPtr = new TreeNode(someChar, NULL, NULL);
}

NodePtr CharTree::Root() const {
    return rootPtr;
}

void AppendLeft(NodePtr ptr, char someChar){
    ptr->lLink = new TreeNode(someChar, NULL, NULL);
}

void AppendRight(NodePtr ptr, char someChar){
    ptr->rLink = new TreeNode(someChar, NULL, NULL);
}

char Data(NodePtr ptr){
    return ptr->data;
}

void Store(NodePtr ptr, char someChar){
    ptr->data = someChar;
}

NodePtr LChild(NodePtr ptr){
    return (ptr == NULL) ? NULL : ptr->lLink;
}

NodePtr RChild(NodePtr ptr){
    return (ptr == NULL) ? NULL : ptr->rLink;
}

bool IsLeaf(NodePtr ptr){
    return (ptr->lLink == NULL && ptr->rLink == NULL);
}

void DeleteLeaf(NodePtr &ptr){
    delete ptr;
}
