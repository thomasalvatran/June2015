#include "chartree.h"
//#include <iomanip> setw
using namespace std;
int count = 0;
int arr[20];

// class TreeNode { //classes default to private access modifiers and in structs
// default is public
// public:
// struct NewNode{
//    int data;
//    NewNode *left;
//    NewNode *right;
//};

// struct TreeNode {
//  int data;
//  NodePtr lLink;
//  NodePtr rLink;
//  TreeNode(char, NodePtr, NodePtr); // ctor
//};

TreeNode::TreeNode(char someChar, NodePtr leftPtr,
                   NodePtr rightPtr) { // TreeNode Class/struct
  data = someChar;
  lLink = leftPtr;
  rLink = rightPtr;
}

CharTree::CharTree() { // CharTree Class
  rootPtr = NULL;
}

CharTree::~CharTree() {
  cout << "Dtor" << endl;
  //    DeleteAll(rootPtr);
}

void DeleteAll(NodePtr ptr) {
  if (ptr != NULL) {
    DeleteAll(LChild(ptr));
    DeleteAll(RChild(ptr));
    delete ptr;
  }
}

bool CharTree::isEmpty() const { return (rootPtr == NULL); }

void CharTree::BuildRoot(char someChar) {
  rootPtr = new TreeNode(someChar, NULL, NULL);
}

NodePtr CharTree::Root() const { return rootPtr; }

void AppendLeft(NodePtr ptr, char someChar) {
  ptr->lLink = new TreeNode(someChar, NULL, NULL);
}

void AppendRight(NodePtr ptr, char someChar) {
  ptr->rLink = new TreeNode(someChar, NULL, NULL);
}

char Data(NodePtr ptr) { return ptr->data; }

void Store(NodePtr ptr, char someChar) { ptr->data = someChar; }

NodePtr LChild(NodePtr ptr) { return (ptr == NULL) ? NULL : ptr->lLink; }

NodePtr RChild(NodePtr ptr) { return (ptr == NULL) ? NULL : ptr->rLink; }

bool IsLeaf(NodePtr ptr) { return (ptr->lLink == NULL && ptr->rLink == NULL); }

void DeleteLeaf(NodePtr &ptr) { delete ptr; }

bool isBinarySearchTree(TreeNode *root, int minValue, int maxValue) {
  if (root == NULL)
    return true;
  if (root->data > minValue && root->data < maxValue &&
      isBinarySearchTree(root->lLink, minValue, root->data) &&
      isBinarySearchTree(root->rLink, root->data, maxValue))
    return true;
  else
    return false;
}
// Method 2: recursive (
bool isBST(TreeNode *root) {
  return isBinarySearchTree(root, INT_MIN, INT_MAX);
}

// Method 3: in-order traversal
bool isBST1(TreeNode *root) {
  static TreeNode *prev = NULL;

  // traverse the tree in inorder fashion and keep track of prev node
  if (root) {
    if (!isBST1(root->lLink))
      return false;

    // Allows only distinct valued nodes
    if (prev != NULL && root->data <= prev->data)
      return false;

    prev = root;
    arr[count++] = root->data;
    return isBST1(root->rLink);
  }

  return true;
}

char findMax(TreeNode *root) {
  TreeNode *temp = root, *root1;
  if (root == NULL) {
    cout << "Error: Tree is empty\n";
    return -1;
  }
  char max = root->lLink->data; // skip root node
  while (root->lLink != NULL) {
    root = root->lLink;
    root1 = root->rLink;
    if (root->data >= max)
      max = root->data;
    cout << "left: root->data = " << root->data << endl;
    if (root1 != NULL) {
      cout << "left-right: root1->data = " << root1->data << endl;
      if (root1->data >= max)
        max = root1->data;
    }
  }
  cout << "MAX " << max << endl;
  return max;
}

//// In BST right side > root and left side < root
char findMin(TreeNode *root) {
  TreeNode *temp = root, *root1;
  if (root == NULL) {
    cout << "Error: Tree is empty\n";
    return -1;
  }
  char min = root->rLink->data; // skip root node
  while (root->rLink != NULL) {
    root = root->rLink;
    root1 = root->lLink;
    if (root->data <= min)
      min = root->data;
    cout << "right: root->data = " << root->data << endl;
    if (root1 != NULL) {
      cout << "right-left: root1->data = " << root1->data << endl;
      if (root1->data <= min)
        min = root->data;
    }
  }
  //  if (root->data <= min) // last leaf
  //    min = root->data;
  //  return root->data;
  cout << "MIN " << min << endl;
  return min;
}

bool isBinarySearchTree(TreeNode *root) {
  char l = findMax(root); // find max in left sub-tree
  char r = findMin(root); // find min in right sub-tree
  cout << l << " = max <--- " << (char)root->data << " ---> min = " << r
       << endl;
  if (l <= root->data && r >= root->data)
    return true;
  else
    return false;
}
// NodePtr findMinNodeLeft(TreeNode *root) {
//  while (root->lLink != NULL)
//    root = root->lLink;
//  return root;
//}

// NodePtr findMinNodeRight(TreeNode *root) {
//  while (root->rLink != NULL)
//    root = root->rLink;
//  return root;
//}

NodePtr findMinNodeLeftOrRight(TreeNode *root, int LorR) {
  if (!LorR) { /* 0 is left */
    while (root->lLink != NULL)
      root = root->lLink;
  } else {
    while (root->rLink != NULL)
      root = root->rLink;
  }
  return root;
}

NodePtr deleteNode(TreeNode *root, int data) {
  if (root == NULL)
    return root;
  else if (data < root->data)
    root->lLink = deleteNode(root->lLink, data);
  else if (data > root->data)
    root->rLink = deleteNode(root->rLink, data);
  else {
    // case 1: No child
    if (root->lLink == NULL && root->rLink == NULL) {
      delete root;
      root = NULL;
    }
    // case 2: One child
    else if (root->lLink == NULL) {
      TreeNode *temp = root;
      root = root->rLink;
      delete temp;
    } else if (root->rLink == NULL) {
      TreeNode *temp = root;
      root = root->lLink;
      delete temp;
    }
    // case 3: 2 children
    else {
      TreeNode *temp = findMinNodeLeftOrRight(root->rLink, 1);
      root->data = temp->data;
      root->rLink = deleteNode(root->rLink, temp->data);
    }
  }
  return root;
}

void inorderPrint(TreeNode *root) {
  if (root == NULL)
    return;
  inorderPrint(root->lLink);
  cout << (char)root->data;
  inorderPrint(root->rLink);
}

void printNodes(TreeNode *root) {
  if (root->lLink)
    printNodes(root->lLink);
  cout << (char)root->data;
  if (root->rLink)
    printNodes(root->rLink);
  //  TreeNode *cur = new TreeNode('c', NULL, NULL);
  //  cur->lLink = NULL;
}

void insertNodeatBegin(TreeNode **root, TreeNode *newnode) {
  //    cout <<"insertNode" << endl;

  if (!(*root)) {
    *root = newnode;
    return;
  }
  if (newnode->data < (*root)->data)
    insertNodeatBegin(&(*root)->lLink, newnode);
  else
    insertNodeatBegin(&(*root)->rLink, newnode);
}

void insertNodeatEnd(TreeNode **root, TreeNode *newnode) {
  TreeNode *temp;

  //    cout <<"insertNode" << endl;
  if (!(*root)) {
    *root = newnode;
    return;
  }
  if (newnode->data < (*root)->data) {
    //      insertNodeEnd(&(*root)->lLink, newnode);
    //    temp = findMinNodeLeft(*root);
    temp = findMinNodeLeftOrRight(*root, 0);
    insertNodeatEnd(&(*temp).lLink, newnode); // either ways . or ->
  } else {
    //      insertNodeatEnd(&(*root)->rLink, newnode);
    //    temp = findMinNodeRight(*root);
    temp = findMinNodeLeftOrRight(*root, 1);
    insertNodeatEnd(&(temp)->rLink, newnode);
  }
}
