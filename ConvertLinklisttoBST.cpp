  struct ListNode {
     int val;
     ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
  };
   struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  };
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
		if(head==nullptr) return nullptr;
		if(head->next==nullptr) return new TreeNode(head->val);
		ListNode* p=head;
		int len=0;
		while(p)
			len++,p=p->next;
		int cnt=0;p=head;
		ListNode* pre;
		while(cnt<len/2)
			pre=p,p=p->next,cnt++;
		pre->next=nullptr;
		
		TreeNode* root=new TreeNode(p->val);
		root->left=sortedListToBST(head);
		root->right=sortedListToBST(p->next);
		return root;
	}
};
int main()
{
	return 0;
}