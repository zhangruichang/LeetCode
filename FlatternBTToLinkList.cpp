class Solution {
public:
    void flatten(TreeNode *root) {
        stack<TreeNode*> s;
        TreeNode* p=root, *last=NULL;
        while(!s.empty() || p)
        {
            while(p) 
            {
                if(last)
                    last->left=p;
                last=p;
                s.push(p);
                p=p->left;
            }
            p=s.top();
            s.pop();
            p=p->right;
        }
        p=root;
        while(p) p->right=p->left,p->left=NULL, p=p->right;//忘记把left处理了，因为二叉树不处理的，未必不改，一定要确保两个孩子都修改过了
    }
};