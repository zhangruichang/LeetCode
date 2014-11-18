/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 #include <vector>
 #include <iostream>
 using namespace std;
    struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  };
class Solution {
public:
	int n;
    TreeNode *sortedArrayToBST(vector<int> &num) {
        n=num.size();
		return f(num,0,n-1);
    }
	TreeNode * f(vector<int> &num, int low, int high)
	{
		if(low>high) return nullptr;
		int mid=low+((high-low)>>1);
		TreeNode * root=new TreeNode(num[mid]);
		root->left=f(num,low,mid-1);
		root->right=f(num,mid+1,high);
		return root;
	}
	void PreOrder(TreeNode* root)
	{
		if(root)
		{
			cout<<root->val<<" ";
			PreOrder(root->left);
			PreOrder(root->right);
		}
	}
} F;

int main()
{
	vector<int> num{1,3};
	TreeNode* root=F.sortedArrayToBST(num);
	F.PreOrder(root);
	return 0;
}