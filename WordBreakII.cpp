#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>
#include <cstring>
using namespace std;
class Solution {
	bool dp[10000];
	vector<int> svec[10000];//split pos
	vector<string> solution;//all solution
	vector<string> cursolution;//one solution
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
		int slen=s.size();
		
			
		solution.clear();
		memset(dp,0,sizeof(bool)*(slen+1));
		for(int i=0;i<=slen;i++)
			svec[i].clear();
		cursolution.clear();
		dp[0]=1;
		if(slen==0)
			return solution;
		for(int i=1;i<=slen;i++)
		{
			for(int k=0;k<=i-1;k++)
			{
				if(dp[k]&& dict.find(s.substr(k,i-k))!=dict.end())
				{
					svec[i].push_back(k);
					dp[i]=1;
				}
			}
		}
		//cout<<"dp\n";
		/*
		for(int i=0;i<=slen;i++)
		{
			cout<<"dp: "<<dp[i]<<"\n";
			for(int j=0;j<svec[i].size();j++)
				cout<<svec[i][j]<<" ";
			cout<<"\n";
		}
		*/
		f(slen,s);
		return solution;
    }
	void f(int i,string s)
	{
		if(i>0)
		{
			if(dp[i])
			{
				for(int k=0;k<svec[i].size();k++)
				{
					cursolution.push_back(s.substr(svec[i][k],i-svec[i][k]));
					//cursolution.push_back(" ");
					f(svec[i][k],s);
					cursolution.pop_back();
					//cursolution+=s.substr(svec[i][k],i-svec[i][k])+" ";
				}
			}
		}
		else
		{
			string tmp;
			if(cursolution.size()==0)
				return;
			tmp+=cursolution.back();
			for(int i=(int)cursolution.size()-2;i>=0;i--)
				tmp+=" "+cursolution[i];
			solution.push_back(tmp);
		}
	}
};

int main()
{
	Solution S;
	string s="catsanddog";
	unordered_set<string> dict;
	
	dict.insert("ca");
	
	dict.insert("tsand");
	dict.insert("cat");
	dict.insert("and");
	dict.insert("sand");
	dict.insert("dog");
	
	vector<string> vec=S.wordBreak(s,dict);
	for(int i=0;i<vec.size();i++)
		cout<<vec[i]<<endl;
	
	
	return 0;
}