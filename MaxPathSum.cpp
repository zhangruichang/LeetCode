#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
	int maxPath;
	/*
    int maxPathSum(TreeNode *root) {
		if(!root) return 0;
        maxpath=root->val;
		PreOrder(root);
		return maxpath;
    }*/
	/*
	void PreOrder(TreeNode *root)
	{
		if(root)
		{
			pair<int, bool> maxpathpair=maxPathNode(root);
			maxpath=max(maxpathpair.first,maxpath);
			PreOrder(root->left);
			PreOrder(root->right);
		}
	}*/
	/*
	void PreOrder(TreeNode* root)
	{
		stack<TreeNode* > S;
		S.push(root);
		while(!S.empty())
		{
			TreeNode* p=S.top();
			S.pop();
			pair<int,int> maxpathpair=maxPathNode(p);
			maxpath=max(max(maxpathpair.first,maxpathpair.second),maxpath);
			if(p->right)
				S.push(p->right);
			if(p->left)
				S.push(p->left);
		}
	}
	
	
	pair<int,int> maxPathNode(TreeNode* root)//pair<int, int>, with left and right path, with left or right path
	{
		if(root==NULL) return {0,0};
		pair<int, int> left=maxPathNode(root->left);
		pair<int, int> right=maxPathNode(root->right);
		int leftmaxpath=left.first,rightmaxpath=right.first;
		// leftmaxpath=maxPathNode(root->left);
		//int rightmaxpath=maxPathNode(root->right);
		int maxpath=root->val;
		//if(left.second>0 && right.second>0)
		//{
			maxpath+=(left.second + right.second);
			return {maxpath,root->val+max(left.second,right.second)};
		//}

		/*
		if(leftmaxpath>0 && rightmaxpath>0 && !(left.second || right.second))
		{
			maxpath+=(leftmaxpath+rightmaxpath);
			return {maxpath,true};
		}
		else
		{
			if(leftmaxpath>0)
				maxpath+=leftmaxpath;
			if(rightmaxpath>0)
				maxpath+=rightmaxpath;
			return {maxpath,false};
		}
	}*/
	
	int maxPathSum(TreeNode *root)
	{
		if(!root) return 0;
		maxPath=root->val;
		maxPathNode(root);
		return maxPath;
	}
	
	int maxPathNode(TreeNode *root)
	{
		if(root==NULL) return 0;
		int leftmax=maxPathNode(root->left), rightmax=maxPathNode(root->right);
		
		maxPath=max(maxPath,max(leftmax+root->val+rightmax, max(leftmax+root->val, rightmax+root->val)));
		//cout<<maxPath<<endl;
		return max(root->val, max(leftmax+root->val, rightmax+root->val));
	}
	
	void Create(TreeNode* &root)
	{
		int n;
		cin>>n;
		if(n!=0)
		{
			root=new TreeNode(n);
			Create(root->left);
			Create(root->right);
		}
		else
			root=NULL;
	}
};



int main()
{
	freopen("MaxPathSumIn.txt","r",stdin);
	TreeNode* root;
	Solution F;
	F.Create(root);
	cout<<F.maxPathSum(root)<<'\n';
	return 0;
}