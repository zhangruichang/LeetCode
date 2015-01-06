/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        int minn, maxn;
        return f(root, maxn, minn);
    }
    bool f(TreeNode* root, int& maxn, int &minn)//此处敲得太快，导致参数写反了，一定要细心，特别是有两个很相近的参数的时候
    {
        if(!root)
        {
            minn=INT_MAX;
            maxn=INT_MIN;
            return 1;
        }
        int leftmaxn, leftminn,rightmaxn, rightminn;
        bool leftBST=f(root->left, leftmaxn, leftminn);
        bool rightBST=f(root->right, rightmaxn, rightminn);
        maxn=max(max(leftmaxn, rightmaxn), root->val);
        minn=min(min(leftminn, rightminn), root->val);
        return leftBST && rightBST && (!root->left || root->val>leftmaxn) && (!root->right || root->val<rightminn);
    }
};