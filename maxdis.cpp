int maxpath;

int maxdis(TreeNode* root)
{
	if(!root) return 0;
	maxpath=0;
	maxdis_recur(root);
	return maxpath;
}

void maxdis_recur(TreeNode* root)
{
	if(!root) return 0;
	int leftmax=maxdis_recur(root->left),rightmax=maxdis_recur(root->right);
	
	maxpath=MAX4(maxpath, leftmax+1,rightmax+1, 1,1+leftmax+rightmax);
	return MAX3(1+leftmax, 1+rightmax,1);
}