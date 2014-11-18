	vector<vector<int> > levelOrder(TreeNode *root) {
			vector<int> onelevel;
			vector<vector<int> > alllevel;
			
			if(root==NULL) return alllevel;
			
			queue<TreeNode*> Q;
			Q.push(root);
			TreeNode* p;
			
			
			//onelevel.push_back(root->val);
			//alllevel.push_back(onelevel);
			
			while(!Q.empty())
			{
				int size=Q.size();
				onelevel.clear();
				for(int i=0;i<size;i++)
				{
					p=Q.front();
					onelevel.push_back(p->val);
					Q.pop();
					if(p->left!=NULL) 
						Q.push(p->left)//onelevel.push_back(p->left->val);
					if(p->right!=NULL)
						Q.push(p->right)//onelevel.push_back(p->right->val);
				}
				if(onelevel.size()!=0)
					alllevel.push_back(onelevel);
			}
			
			return alllevel;
		}