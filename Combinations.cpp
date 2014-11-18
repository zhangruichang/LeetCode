#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;

class Solution {

public:
	struct info
	{
		int selectk ,k, selectn, n;
		int type;
	};
	bool select[10000];
	vector<vector<int> > ans;
	vector<int> curvec;
    vector<vector<int> > combine_select(int n, int k) {
		ans.clear();
        memset(select,0,sizeof(select));
		dfs(0,k,0,n);
		return ans;
    }
	void dfs(int selectk, int k, int selectn, int n)
	{
		if(selectn==n)
		{
			if(selectk==k)
			{
				vector<int> oneans;
				for(int i=0;i<n;i++)
					if(select[i])
						oneans.push_back(i+1);
				ans.push_back(oneans);
			}
		}
		else
		{
			select[selectn]=0;
			dfs(selectk,k,selectn+1,n);
			select[selectn]=1;
			dfs(selectk+1,k,selectn+1,n);
		}
	}
	vector<vector<int> > combine_vector(int n, int k) {
		ans.clear();
		curvec.clear();
        //memset(select,0,sizeof(select));
		dfs_vector(0,k,0,n);
		return ans;
    }
	
	vector<vector<int> > combination_iterative(int n, int k)
	{
		ans.clear();
		curvec.clear();
		stack<info> S;
		S.push({0,k,0,n,0});
		while(!S.empty())
		{
			info& cur=S.top();
			if(cur.selectk>cur.k)
			{
				S.pop();
			}
			else if(cur.selectn==cur.n)
			{
				if(cur.selectk==cur.k)
					ans.push_back(curvec);
				S.pop();
			}
			else
			{
				if(cur.type==0)
					cur.type++,S.push({cur.selectk,cur.k,cur.selectn+1,cur.n,0});
				else if(cur.type==1)
					cur.type++,curvec.push_back(cur.selectn+1),S.push({cur.selectk+1,cur.k,cur.selectn+1,cur.n,0});
				else
					curvec.pop_back(),S.pop();
			}
		}
		return ans;
	}
	
	
	void dfs_vector(int selectk, int k, int selectn, int n)
	{
		if(selectk>k) return;
		if(selectn==n)
		{
			if(selectk==k)
			{
				ans.push_back(curvec);
				/*
				vector<int> oneans;
				for(int i=0;i<n;i++)
					if(select[i])
						oneans.push_back(i+1);
				ans.push_back(oneans);*/
			}
		}
		else
		{
			//select[selectn]=0;
			dfs_vector(selectk,k,selectn+1,n);
			curvec.push_back(selectn+1);
			//select[selectn]=1;
			dfs_vector(selectk+1,k,selectn+1,n);
			curvec.pop_back();
		}
	}
	
	
} F;

int main()
{
	int n=4,k=2;
	vector<vector<int> > ans=F.combination_iterative(n,k);
	for(int i=0;i<F.ans.size();i++)
	{
		for(int j=0;j<F.ans[i].size();j++)
			cout<<F.ans[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}