// Mark_R
//#define EXTERN
#include "chartree.h"
#include <iostream>
#include <stdio.h>
using namespace std;
CharTree tree;
extern int count;
extern int arr[];

void createTree() {
  tree.BuildRoot('r'); // not a binary search tree charTree
  AppendLeft(tree.Root(), 'h');
  AppendRight(tree.Root(), 'T');
  AppendLeft(LChild(tree.Root()), 'C');
  AppendRight(LChild(tree.Root()), 'a');
  AppendRight(RChild(tree.Root()), 'e');
  AppendLeft(RChild(RChild(tree.Root())), 'r');
  AppendRight(RChild(RChild(tree.Root())), 'e');

  /* ASSERT: tree contents appear as follows: */
  /*                                          */
  /*                  ‘r’                     */
  /*                 /   \                    */
  /*              ‘h’     ‘T’                 */
  /*              / \       \                 */
  /*            ‘C’ ‘a’     'e’               */
  /*                        / \               */
  /*                      ‘r’  'e’            */
}
void createBST() {
  tree.BuildRoot('R'); // a binary search tree CHARtree
  AppendLeft(tree.Root(), 'H');
  AppendRight(tree.Root(), 'a');
  AppendLeft(LChild(tree.Root()), 'C');
  AppendRight(LChild(tree.Root()), 'O');
  AppendRight(RChild(tree.Root()), 'e');
  AppendLeft(RChild(RChild(tree.Root())), 'd');
  AppendRight(RChild(RChild(tree.Root())), 'f'); // e is BST and E is not BST
}

void printTree() {
  cout << "Printing contensts of the binary tree\n";
  cout << "\"CharTree\" should be output: ";
  cout << Data(LChild(LChild(tree.Root())));
  cout << Data(LChild(tree.Root()));
  cout << Data(RChild(LChild(tree.Root())));
  cout << Data(tree.Root());
  cout << Data(RChild(tree.Root()));
  cout << Data(LChild(RChild(RChild(tree.Root()))));
  cout << Data(RChild(RChild(tree.Root())));
  cout << Data(RChild(RChild(RChild(tree.Root()))));
  cout << '\n';
  cout << '\n';
}

char *str1 = "Is BST";
char *str2 = "Not a BST";
string str = "Is BST\n"; // cannot convert const char* to string* in printf

int main() {

  createTree(); // method 1 root->left != NULL
  printf("Method1: %s\n", isBinarySearchTree(tree.Root()) ? str1 : str2);
  printTree();

  // Method 1: Loop for NULL
  createBST();
  printf("Method1: %s\n", isBinarySearchTree(tree.Root()) ? str1 : str2);
  printTree();

  // Method 2: recursive
  printf("Method2: %s\n", isBST(tree.Root()) ? str1 : str2);

  // Method 3: in-order traverse
  printf("Method3: %s\n", isBST1(tree.Root()) ? str1 : str2);

  printf("Array of tree in-order traversal: ");
  for (int i = 0; i < count; i++)
    printf("%c", arr[i]);
  printf("\n");
  printf("inorderPrint(): ");
  inorderPrint(tree.Root());
  printf("\n");
  //  if (isBST(root))
  //     printf("Is BST\n");
  //   else
  //     printf("Not a BST\n");
  printf("delete f\n");
  TreeNode *root =  deleteNode(tree.Root(), 'f');
//  tree.Root() = root; //lvalue required as left operand of assignment
  inorderPrint(root);
  printf("\n");
  return 0;
}
//left-right: root1->data = 97
//left: root->data = 67
//MAX h
//right: root->data = 84
//right: root->data = 101
//right-left: root1->data = 114
//right: root->data = 101
//MIN T
//h = max <--- r ---> min = T
//Method1: Not a BST
//Printing contensts of the binary tree
//"CharTree" should be output: CharTree

//left: root->data = 72
//left-right: root1->data = 79
//left: root->data = 67
//MAX O
//right: root->data = 97
//right: root->data = 101
//right-left: root1->data = 100
//right: root->data = 102
//MIN a
//O = max <--- R ---> min = a
//Method1: Is BST
//Printing contensts of the binary tree
//"CharTree" should be output: CHORadef

//Method2: Is BST
//Method3: Is BST
//Array of tree in-order traversal: CHORadef
//inorderPrint(): CHORadef
//delete f
//CHORade
//Dtor
