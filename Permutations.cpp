#include <vector>
#include <cstring>
using namespace std;
class Solution {
public:
	vector<vector<int> >ans;
	vector<int> cur;
	bool used[1000];
	int n;
    vector<vector<int> > permute(vector<int> &num) {
		ans.clear();
		cur.clear();
		memset(used,0,sizeof(used));
		n=num.size();
		if(n==0) return ans;
		dfs(0,num);
		return ans;
    }
	void dfs(int depth,vector<int> num)
	{
		if(depth>=n)
			ans.push_back(cur);
		else
		{
			for(int i=0;i<n;i++)
			{
				if(!used[i])
				{
					used[i]=1;
					cur.push_back(num[i]);
					dfs(depth+1,num);
					cur.pop_back();
					used[i]=0;
				}
			}
		}
	}
};