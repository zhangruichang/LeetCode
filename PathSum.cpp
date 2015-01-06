class Solution {//Path sum problem, recursive solution
public:
    bool hasPathSum(TreeNode* root, int sum)
    {
        if(!root) return 0;//check root null before
        if(!root->left && !root->right)//leaf node
            return sum==root->val;
        return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
    }
};

class Solution {//frequently writing code, but not elegant, it's based on the PreOrder traversal
public:
    bool ok;
    int sum_, cursum;
    bool hasPathSum(TreeNode *root, int sum) {
        ok=0;sum_=sum; cursum=0;
        PreOrder(root);
        return ok;
    }
    void PreOrder(TreeNode* root)
    {
        if(root)
        {
            cursum+=root->val;
            if(!root->left && !root->right && cursum==sum_)
                ok=1;
            PreOrder(root->left);
            PreOrder(root->right);
            cursum-=root->val;
        }
    }
};