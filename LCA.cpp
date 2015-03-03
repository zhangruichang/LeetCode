#include<set>
#include<map>
#include<list>
#include<cmath>
#include<queue>
#include<stack>
#include<ctime>
#include<cstdio>
#include<string>
#include<vector>
#include<climits>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
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

struct TreeNode
{
    int val;
    TreeNode* left, *right;
    TreeNode(int val_) : val(val_){}
};

bool StringContain(string a, string b)
{//O(m+n), O(1), 256 chars at most
    unordered_set<char> hash;
    for(auto i: b) hash.insert(i);
    bool ocur[256]; memset(ocur, 0, sizeof(ocur));
    for(auto i: a) ocur[i]=1;
    for(auto i: hash) if(!ocur[i]) return 0;
    return 1;
}
string Brother(string a, vector<string> dict)
{
    for(auto i: dict)
    {
        string tmp=i, a1=a;
        sort(tmp.begin(), tmp.end());
        sort(a1.begin(), a1.end());
        if(tmp==a1) return i;
    }
    return "";
}
void PreOrder(TreeNode* root);

TreeNode* p1_, *p2_;
vector<TreeNode*> curpath, path1, path2;
TreeNode* LCA_Traversal(TreeNode* root, TreeNode* p1, TreeNode* p2)//p1, p2 must be in root,root not null, if root NULL,
{//ON algorithm, or p1 p2 NULL, return NULL
    p1_=p1, p2_=p2;
    path1.clear(), path2.clear();
    curpath.clear();
    PreOrder(root);
    TreeNode* LCANode=nullptr;
    for(int i=0;i<min(path1.size(), path2.size());i++)
    {
        if(path1[i]==path2[i]) LCANode=path1[i];
    }
    return LCANode;
}

TreeNode* LCA_Recursive(TreeNode* root, TreeNode* p1, TreeNode* p2)
{
    if(!root) return NULL;
    if(root == p1 || root==p2) return root;
    TreeNode* leftLCA=LCA_Recursive(root->left, p1, p2);
    TreeNode* rightLCA=LCA_Recursive(root->right, p1, p2);
    if(leftLCA && rightLCA) return root;
    else if(leftLCA) return leftLCA;
    else if(rightLCA) return rightLCA;
    else return NULL;
}

void PreOrder(TreeNode* root)
{
    if(root)
    {
        curpath.push_back(root);
        if(root==p1_) path1=curpath;
        else if(root==p2_) path2=curpath;
        PreOrder(root->left);
        PreOrder(root->right);
        curpath.pop_back();
    }
}
TreeNode* Find(TreeNode* root, int x)
{
    stack<TreeNode*> s;
    TreeNode* p=root;
    while(!s.empty() || p)
    {
        while(p)
        {
            if(p->val==x) return p;
            s.push(p);
            p=p->left;
        }
        p=s.top();
        s.pop();
        p=p->right;
    }
    return NULL;
}
int data[]={3,20,40,-1,-1,-1,7,10,1,-1,-1,5,2,-1,-1,-1,8,6,4,-1,-1,-1,-1};
int i;

void Create(TreeNode*& root)
{
    int x=data[i++];
    if(x==-1) { root=NULL; return ;}
    root=new TreeNode(x);
    Create(root->left);
    Create(root->right);
}

int f(int &x)
{
    int*p=&x;
    cout<<p<<endl;
}

int main()
{
    TreeNode* root;
    i=0;
    Create(root);
    int x1=20, x2=6;
    TreeNode* p1=Find(root, x1), *p2=Find(root, x2);
    TreeNode* LCANode=LCA_Recursive(root, p1, p2);
    cout<<LCANode->val<<endl;
    string a="abcbabsbcbab", b="ababababad";
    cout<<StringContain(a, b)<<endl;
	return 0;
}
