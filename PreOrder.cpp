class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> prevec;
        TreeNode* p=root;
        stack<TreeNode* > S;
        while(!S.empty() || p)
        {
            while(p)
            {
                S.push(p);
                prevec.push_back(p->val);
                p=p->left;
            }
            p=S.top();S.pop();
            p=p->right;
        }
        return prevec;
    }
};