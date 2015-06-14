// Mark_R
//#define ARRAY_H     // exclusive in chartree.h and extern here
// extern int count;  //put in chartree.h for all modules
// extern int arr[20];

//#define EXTERN      //Method 2 for arr and count using EXTERN
//#define CHARTREE_H  //exclusive in all in chartree.h
#include "chartree.h"
#include <iostream>
#include <stdio.h>

using namespace std;
CharTree tree;

// struct NewNode{
//    int data;
//    NewNode *left;
//    NewNode *right;
//};
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

const char *str1 = "Is BST"; // deprecated conversion from string conts to char*
char const *str2 = "Not a BST";
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
  printf("delete char f...\n");
  TreeNode *root = deleteNode(tree.Root(), 'f');
  //  tree.Root() = root; //lvalue required as left operand of assignment
  inorderPrint(root);
  printf("\n");
  printNodes(tree.Root());
  printf("\n");
  printf("insertNode newroot...\n");
  TreeNode *curr, *newroot = NULL;
  for (int i = 0; i < 6; i++) {
    curr = new TreeNode('a' + i, NULL, NULL); // heap
    //    curr->data = 'a'; curr->lLink = curr->rLink = NULL // in stack go
    //    nowhere
    insertNodeatBegin(&newroot, curr);
  }
  printNodes(newroot);
  printf("\n");

  printf("insert char at begin char A\n"); // insert left A < a
  curr = new TreeNode('A', NULL, NULL);
  insertNodeatBegin(&newroot, curr);

  printf("insert char at end char w\n"); // insert left A < a
  curr = new TreeNode('w', NULL, NULL);
  insertNodeatEnd(&newroot, curr);

  printNodes(newroot);
  printf("\n");
  printf("newroot is %c\n", newroot->data);
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
//delete char f...
//CHORade
//CHORade
//insertNode newroot...
//abcdef
//insert char A
//Aabcdef
//newroot is a
//Dtor
