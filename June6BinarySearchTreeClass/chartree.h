//#ifndef EXTERN
//#define EXTERN extern
//#endif

//EXTERN int count;
//EXTERN int arr[20];

#ifndef CHARTREE_H
#define CHARTREE_H

#include <stddef.h>
#include <iostream>
#include <limits.h>

struct TreeNode;
typedef TreeNode *NodePtr;
class CharTree {
  //  NodePtr rootPtr; //like any data int *rootPtr
  struct TreeNode *rootPtr;

public:
  bool isEmpty() const;
  void BuildRoot(char someChar);
  NodePtr Root() const;
  CharTree();
  ~CharTree();
};

void AppendLeft(NodePtr ptr, char someChar);
void AppendRight(NodePtr ptr, char someChar);
char Data(NodePtr ptr);
void Store(NodePtr ptr, char someChar);
NodePtr LChild(NodePtr ptr);
NodePtr RChild(NodePtr ptr);
bool IsLeaf(NodePtr ptr);
void DeleteLeaf(NodePtr &ptr);
void DeleteAll(NodePtr ptr);
bool isBinarySearchTree(NodePtr ptr);
bool isBST(NodePtr ptr); // Method 1: Binary search tree
bool isBST1(TreeNode *root); // Method 2: in-order traverse
NodePtr deleteNode(TreeNode *root, int data);
void inorderPrint(TreeNode *root);
bool isSubtreeLesser(NodePtr root, int value);
bool isSubtreeGreater(NodePtr root, int value);

#endif // CHARTREE_H
