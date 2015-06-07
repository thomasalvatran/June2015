#ifndef CHARTREE_H
#define CHARTREE_H

struct TreeNode;
typedef TreeNode *NodePtr;

class CharTree
{
    NodePtr rootPtr;
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
#endif // CHARTREE_H
