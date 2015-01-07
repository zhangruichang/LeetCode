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
struct TreeNode
{
    int val;
    TreeNode* left, *right;
    TreeNode(int val_): val(val_), left(NULL), right(NULL)
    {
    }
};

TreeNode* f(TreeNode* root)
{
    stack<TreeNode*> s;
    TreeNode* p=root, *last=NULL, *head;
    while(!s.empty() || p)
    {
        while(p)
        {
            s.push(p);
            p=p->left;
        }
        p=s.top();s.pop();
        if(last)
            last->right=p, p->left=last;
        else
            p->left=NULL, head=p;
        last=p;
        p=p->right;
    }
    last->right=NULL;
    return head;
}

void Convert(TreeNode* root, TreeNode*& head, TreeNode*& tail)
{
    if(!root)
    {
        head=tail=NULL;
        return ;
    }
    TreeNode* lefthead, *lefttail, *righthead, *righttail;
    Convert(root->left, lefthead, lefttail);
    if(lefttail)
        lefttail->right=root;
    root->left=lefttail;
    Convert(root->right, righthead, righttail);
    root->right=righthead;
    if(righthead)
        righthead->left=root;
    head=lefthead ? lefthead : root;
    tail=righttail ? righttail : root;
}

TreeNode* ConvertBSTToDoubleLinkList(TreeNode* root)
{
    TreeNode* head, *tail;
    Convert(root, head, tail);
    return head;
}

int data[]={2,1,-1,-1,6,4,3,-1,-1,5,-1,-1,-1};
int i;
void Create(TreeNode* & root)
{
    int x=data[i++];
    if(x==-1) { root=NULL; return ; }
    root=new TreeNode(x);
    Create(root->left);
    Create(root->right);
}
void PostOrder(TreeNode* root)
{
    if(!root) return ;
    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->val;
}
void Show(TreeNode* head)
{
    TreeNode* p;
    while(head) cout<<head->val<<" ", p=head, head=head->right;
    cout<<endl;
    while(p) cout<<p->val<<" ", p=p->left;
}

class Solution {
public:
    vector<int> findSubstring(string s, vector<string> &L) {
        unordered_map<string, int> t;
        vector<int> ans;
        if(L.size()<=0 || s.size()<=0) return ans;
        int slen=s.size(),lsize=L.size(),vssize=L[0].size();
        for(auto sl:L)
          t[sl]++;
        for(int i=0;i+lsize*vssize<=slen;i++)
        {
          auto tmpt=t;
          int k;
          for(k=0;k<lsize;k++)
          {
            auto it=tmpt.begin();
            if( (it=tmpt.find(s.substr(i+k*vssize, vssize) )) !=tmpt.end() && it->second>0)
              it->second--;
            else
              break;
          }
          if(k==lsize) ans.push_back(i);
        }
        return ans;
    }
};

int main()
{
    i=0;
    TreeNode* root;
    Create(root);
    PostOrder(root);cout<<endl;
    TreeNode* head=ConvertBSTToDoubleLinkList(root);
    Show(head);
    //cout << "Hello world!" << endl;
    return 0;
}
