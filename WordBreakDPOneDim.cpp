#include <cstdio>
#include <unordered_set>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
using namespace std;
class Solution {
public:
	bool dp[100000];
    bool wordBreak(string s, unordered_set<string> &dict) {
		int slen=s.size();
		if(slen==0)
			return 0;
		memset(dp,0,sizeof(bool)*(slen+1));
		dp[0]=1;
		for(int i=1;i<=slen;i++)
		{
			for(int k=0;k<=i-1;k++)
			{
				if(dp[k] && dict.find(s.substr(k,i-k))!=dict.end())
				{
					dp[i]=1;
					break;
				}
			}
		}
		//for(int i=0;i<=slen;i++)
		//	printf("%d ",&dp[i]);
		return dp[slen];
    }
};

int main()
{
	Solution S;
	string s="";
	unordered_set<string> dict;
	//dict.insert("leet");
	//dict.insert("cod");
	//dict.insert("l");
	//for(auto i=dict.begin();i!=dict.end();i++)
	//	printf("%s ",(*i).c_str());
	printf("%d\n",S.wordBreak(s,dict));
	return 0;
}