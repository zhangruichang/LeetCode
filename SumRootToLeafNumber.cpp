#include <iostream>
#include <cmath>
#include <vector>
using namespace std; 
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution {
public:
    int sumNumbers(TreeNode *root) {
        pathsum=0;
        pathvec.clear();
        PreOrder(root);
        return pathsum;
    }
    vector<int> pathvec;
    int pathsum;
    void PreOrder(TreeNode* root)
    {
        if(root)
        {
            pathvec.push_back(root->val);
            if(!(root->left) && !(root->right))
            {
                int n=(int)pathvec.size();
                for(int i=0;i<n;i++)
                {
                    pathsum+=pathvec[i]*pow(10.0, n-i-1);
                }
            }
            PreOrder(root->left);
            PreOrder(root->right);
            pathvec.pop_back();
        }
    }
};