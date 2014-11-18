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
#include <ctime>
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

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

  struct UndirectedGraphNode {
      int label;
      vector<UndirectedGraphNode *> neighbors;
      UndirectedGraphNode(int x) : label(x) {};
  };
 
class Solution {
private:
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> T;
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        T.clear();
        return f(node);
    }
    UndirectedGraphNode *f(UndirectedGraphNode *node) {
        
        if(!node) return nullptr;
        auto it=T.find(node);
        if(it!=T.end()) return it->second;
        UndirectedGraphNode * newnode=new UndirectedGraphNode(node->label);
        newnode->neighbors.clear();
        T[node]=newnode;
        for(int i=0;i<node->neighbors.size();i++)
            newnode->neighbors.push_back(f(node->neighbors[i]));
        return newnode;
    }
};