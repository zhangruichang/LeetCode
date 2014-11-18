/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 #include <cstdio>
 #include <vector>
 #include <string>
 using namespace std;
 #define PB push_back
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
    int count;
    vector<TreeNode* > BSTvec;
    vector<TreeNode *> generateTrees(int n) {
        BSTvec.clear();
        CreateUniqueBST(1,n,true);
        for(int i=0;i<BSTvec.size();i++)
            PreOrder(BSTvec[i]),puts("");
        return BSTvec;
    }
    void CreateUniqueBST(int s, int e, bool isroot)
    {
        if(s>e) return NULL;
        for(int i=s;i<=e;i++)
        {
            TreeNode* root=new TreeNode(i);
            if(isroot)
                BST.PB(root),isroot=false;
            root->left=CreateUniqueBST(s,i-1,isroot);
            root->right=CreateUniqueBST(i+1,e,isroot);
            //if(count==n)
                //BSTvec.PB(root);
        }
    }
    void PreOrder(Node * root)
    {
        stack<TreeNode* > S;
        //S.push(root);
        p=root;
        while(!S.empty()||p)
        {
            while(p)
            {
                cout<<p;
                S.push(p);
            }
            p=S.top();
            S.pop();
            p=p->right;
        }
    }
};

int main()
{
    Solution S;
    S.generateTrees(3);
    
    return 0;
}