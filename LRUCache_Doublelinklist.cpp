#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<cstdlib>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include <unordered_set>
#include <unordered_map>
using namespace std;
const int maxn = 1e5 + 10;
typedef long long LL;
typedef unsigned long long ULL;
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define mp make_pair
#define pb push_back
#define CLR(a,x) memset(a,x,sizeof(a))

struct Node {
  int key, value;
  Node *prev, *next;

  Node* remove() {
    prev->next = next;
    next->prev = prev;
    return this;
  }

  Node* insertBefore(Node *b) {
    prev = (next = b)->prev;
    return prev->next = b->prev = this;
  }
};

class LRUCache {
public:
  LRUCache(int capacity) : cap_(capacity) {
    head.next = &tail;
    tail.prev = &head;
  }

  int get(int key) {
    auto it = table_.find(key);
    if (it != table_.end())
      return it->second->remove()->insertBefore(&tail)->value;
    return -1;
  }

  void set(int key, int value) {
    Node *x = head.next;
    auto it = table_.find(key);
    if (it != table_.end())
      x = it->second->remove();
    else if (table_.size() == cap_)
      table_.erase(x->remove()->key);
    else
      x = new Node;
    x->key = key;
    x->value = value;
    table_[key] = x->insertBefore(&tail);
  }

private:
  unordered_map<int, Node*> table_;
  int cap_;
  Node head, tail;
};


int main()
{
	return 0;
}