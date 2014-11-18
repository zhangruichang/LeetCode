class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if(head==NULL)
            return NULL;
        if(head->next==NULL)
        {
            TreeNode* LN=new TreeNode(head->val);
            return LN;
        }
        int len=0,cnt;
        ListNode* p=head;
        while(p)
            p=p->next,len++;
        p=head,cnt=0;
        ListNode* pre;
        while(cnt<len/2)
            pre=p,p=p->next, cnt++;
        pre->next=NULL;
        TreeNode* root=new TreeNode(p->val);
        
        root->left=sortedListToBST(head), root->right=sortedListToBST(p->next);
        
        return root;
    }
    
};