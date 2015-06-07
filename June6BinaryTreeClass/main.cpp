//Mark_R
#include "chartree.h"
#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    CharTree tree;
    tree.BuildRoot('r');
    AppendLeft(tree.Root(), 'h');
    AppendRight(tree.Root(), 'T');
    AppendLeft(LChild(tree.Root()), 'C');
    AppendRight(LChild(tree.Root()), 'a');
    AppendRight(RChild(tree.Root()), 'e');
    AppendLeft(RChild(RChild(tree.Root())), 'r');
    AppendRight(RChild(RChild(tree.Root())), 'e');

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
    return 0;
}
