class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> vec;
        if(root==NULL) return vec;
        TreeNode* p=root,*pre=NULL;
        Stack<TreeNode*> S;
        S.push(root);
        while(!S.empty())
        {
            p=S.top();
            if((p->left==NULL && p->right==NULL) ||  (pre!=NULL && (pre==p->left || pre=p->right) ))
            {
                vec.push_back(p->val);
                pre=p;
                S.pop();
            }
            else
            {
                if(p->right!=NULL)
                    vec.push_back(p->right);
                if(p->left!=NULL)
                    vec.push_back(p->left);
            }
        }
        return vec;
    }
};