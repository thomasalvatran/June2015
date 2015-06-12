#include <iostream>
#include <utility>
#include <algorithm>
#include <list>

namespace tree {

template<typename T>
struct node
{
  T data;
  node* l;
  node* r;
  node(T&& data_ = T()) : data(std::move(data_)), l(0), r(0) {}
};

template<typename T>
int max_depth(node<T>* n)
{
  if (!n) return 0;
  return 1 + std::max(max_depth(n->l), max_depth(n->r));
}

template<typename T>
void prt(node<T>* n)
{
  struct node_depth
  {
    node<T>* n;
    int lvl;
    node_depth(node<T>* n_, int lvl_) : n(n_), lvl(lvl_) {}
  };

  int depth = max_depth(n);

  char buf[1024];
  int last_lvl = 0;
  int offset = (1 << depth) - 1;

  // using a queue means we perform a breadth first iteration through the tree
  std::list<node_depth> q;

  q.push_back(node_depth(n, last_lvl));
  while (q.size())
  {
    const node_depth& nd = *q.begin();

    // moving to a new level in the tree, output a new line and calculate new offset
    if (last_lvl != nd.lvl)
    {
      std::cout << "\n";

      last_lvl = nd.lvl;
      offset = (1 << (depth - nd.lvl)) - 1;
    }

    // output <offset><data><offset>
    if (nd.n)
      sprintf(buf, " %*s%d%*s", offset, " ", nd.n->data, offset, " ");
    else
      sprintf(buf, " %*s", offset << 1, " ");
    std::cout << buf;

    if (nd.n)
    {
      q.push_back(node_depth(nd.n->l, last_lvl + 1));
      q.push_back(node_depth(nd.n->r, last_lvl + 1));
    }

    q.pop_front();
  }
  std::cout << "\n";
}

}

int main()
{
  typedef tree::node<int> node;
  node* head = new node();
  head->l    = new node(1);
  head->r    = new node(2);
  head->l->l = new node(3);
  head->l->r = new node(4);
  head->r->l = new node(5);
  head->r->r = new node(6);

  tree::prt(head);

  return 0;
}
