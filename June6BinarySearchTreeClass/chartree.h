//#ifndef EXTERN     //using EXTERN extern for arr and count
//#define EXTERN extern
//#endif

//EXTERN int count;
//EXTERN int arr[20];
//------------
//#ifndef ARRAY_H   //can exlusive the arr and count using ARRAY_H
//#define ARRAY_H
//int count = 0;
//int arr[20];
//#endif

#ifndef CHARTREE_H  //because of this all files include only one
#define CHARTREE_H

#include <stddef.h>
#include <iostream>
#include <limits.h>

extern int count;
extern int arr[20];

struct TreeNode;
typedef TreeNode *NodePtr;
struct TreeNode {
  int data;
  NodePtr lLink;
  NodePtr rLink;
  TreeNode(char, NodePtr, NodePtr); // ctor
};

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
void printNodes(TreeNode *root);
void insertNode(TreeNode **root, TreeNode *newnode);
bool isSubtreeLesser(NodePtr root, int value);
bool isSubtreeGreater(NodePtr root, int value);

#endif // CHARTREE_H
