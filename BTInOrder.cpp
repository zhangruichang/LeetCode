#include <vector>
#include <stack>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution {
struct Info
{
	TreeNode *p;
	int type;
};
public:
    vector<int> inorderTraversal(TreeNode *root) {
        stack<TreeNode* > S;
		S.push({root,0});
		vector<int> vec;
		while(!S.empty())
		{
			Info& cur=S.top();
			if(!cur.p) S.pop();
			else if(cur.type==0)
				cur.type++,S.push({cur.p->left,0});
			else if(cur.type==1)
				cur.type++,vec.push_back(cur.p->val),S.push({cur.p->right,0});
			else
				S.pop();
		}
		return vec;
    }
};