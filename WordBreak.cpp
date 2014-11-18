#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <string>
#include <cstdlib>
#include <unordered_set>
using namespace std;
class Solution {
public:
	bool dp[10000][10000];
    bool wordBreak(string s, unordered_set<string> &dict) {
		int slen=s.size();
		for(int i=0;i<slen;i++)
			memset(dp[i],0,sizeof(bool)*slen);
		for(int i=0;i<s.size();i++)
		{
			for(auto j=dict.begin();j!=dict.end();++j)
			{
				//string tmp=*j;
				if((string)s[i] == (*j)) 
				{
					dp[i][i]=1;
					break;
				}
			}
		}
		for(int len=2;len<=s.size();len++)
		{
			for(int i=0;i<s.size();i++)
			{
				int j=i+len-1;
				if(j>=s.size())
					continue;
				for(int k=i;k<j;k++)
				{
					if(dp[i][k]&&dp[k+1][j])
					{
						dp[i][j]=1;
						break;
					}
				}
			}
		}
		return dp[0][slen-1];
    }
};

/*
int main()
{
	Solution S;
	string s="leetcode";
	unordered_set<string> dict;
	dict.insert("leet");
	dict.insert("code");
	cout<<S.wordBreak(s,dict)<<endl;
	return 0;
}
*/