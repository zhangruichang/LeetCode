#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

char p[40000],s[40000];
/*
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
		if(!p || !s) return 0;
		
		if(!p[0] && !s[0]) return 1;
		
        if(p[0] == '?') return isMatch(s + 1, p + 1);
		if(p[0] == '*')
		{
			for(int i = 0; s[i]; i++)
				if(isMatch(s + i, p + 1)) return 1;
			return isMatch("", p + 1);
		}
		else
		{
			if(s[0] == p[0]) return isMatch(s+1,p+1);
			else return 0;		
		}
    }
} F;*/

class Solution {
public:
    bool isMatch_fawkes(const char *s, const char *p) {
		if(!p || !s) return 0;
		
		if (!p[0]) return !s[0];
		
		if(p[0] == '*')
		{
			for(int i = 0; s[i]; i++)
				if(isMatch_fawkes(s + i, p + 1)) return 1;
			return isMatch_fawkes("", p + 1);
		}
        if (!s[0]) return false;
        if(s[0] == p[0] || p[0] == '?') return isMatch_fawkes(s + 1, p + 1);
		return 0;		
    }

	bool isMatch_my(const char *s, const char* p)
	{
		if(!p||!s) return 0;
		if(!p[0] && !s[0]) return 1;
		if(!p[0] && s[0] || p[0] && !s[0] && p[0]!='*') return 0;
		if(p[0] == '*')
		{
			for(int i = 0; s[i]; i++)
				if(isMatch_my(s + i, p + 1)) return 1;
			return isMatch_my("", p + 1);
		}
		else if(p[0] == '?' || p[0]==s[0])
			return isMatch_my(s+1,p+1);
		else
			return 0;
	}
	
	bool isMatch_dp(const char* str, const char* pat)
	{
		int m=strlen(str),n=strlen(pat);
		bool **dp=new bool*[m+1];
		for(int i=0;i<=m;i++)
			dp[i]=new bool[n+1];
		dp[0][0]=1;
		
		for(int i=1;i<=m;i++) dp[i][0]=0;
		bool firstnonstar=0;
		for(int j=1;j<=n;j++)
		{
			if(!firstnonstar)
			{
				if(pat[j-1]!='*')
					dp[0][j]=0,firstnonstar=1;
				else
					dp[0][j]=1;
			}
			else
			{
				dp[0][j]=0;
			}
		}
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(str[i-1]==pat[j-1] || pat[j-1]=='?')
					dp[i][j]=dp[i-1][j-1];
				else if(pat[j-1]!='?' && pat[j-1]!='*' && str[i-1]!=pat[j-1] )
					dp[i][j]=0;
				else if(pat[j-1]=='*')
				{
					dp[i][j]=0;
					for(int k=0;k<=i;k++)
					{
						if(dp[k][j-1]) {dp[i][j]=1;break;}
						//dp[i][j]+=dp[k][j-1];
					}
				}
			}
		}
		int max=dp[m][n];
		for(int i=0;i<=m;i++)
			delete[] dp[i];
		delete[] dp;
		/*
		for(int i=0;i<=m;i++)
		{
			for(int j=0;j<=n;j++)
				cout<<dp[i][j]<<" ";
			cout<<endl;
		}*/	
		return max;
	}
} F;

int main()
{
	while(scanf("%s%s",s,p)!=EOF)
	{
		//cout<<s<<" "<<p<<'\n';
		cout<<strlen(s)<<" "<<strlen(p)<<endl;
		cout<<F.isMatch_dp(s,p)<<'\n';
	}
	return 0;
}
/*
bool isWildCard(const char* pattern, char* str)
{
	//pattern J* Smi??
	//str John Smith
	int m=strlen(str),n=strlen(pattern),start,j;
	for(int i=0;i<m;)
	{
		start=i;
		for(j=0;j<n;)
		{
			if(pattern[j]=='*')
			{
				j++;
			}
			else if(pattern[j]=='?')
				i++,j++;
			else if(str[i]==pattern[j])
				i++,j++;
			else
			{
				i=start+1;break;
			}
		}
		if(j==n) return 1;
	}
	for(j=0;j<n;)
	{
		for(i=0;i<m;i++)
		{
			
		}
	}
	
	while(i<m && j<n)
	{
		if(pat[j]=='*')
			i++,j++;
		else if(pat[j]=='?')
			i++,j++;
		else if(str[i]==pat[j])
			i++,j++;
		else
			break;
		//if(str[i]==pat[j])
	}
	
	
	return 0;
}
*/
