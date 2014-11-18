#include <cstring>
#include <vector>
#include <iostream>
#include <ctime>
using namespace std;
class Solution {
public:
    
    bool isP[1000][1000];
    string longestPalindrome_xiao(string str)
    {
       int length = str.size();
		memset(isP, false, sizeof(isP));
		for(int i=0; i<length; i++) isP[i][i] = true;
		for(int i=0; i<length-1; i++)
			if(str[i] == str[i+1])
				isP[i][i+1] = true;
		for(int len=3; len<=length; len++) 
			for(int i=0; i<length-len+1; i++)
			{
				int j = i+len-1;
				if (str[i] == str[j]) isP[i][j] = isP[i+1][j-1];
				
			}
		int maxLen = 0, sta = 0;
		for (int i=0; i<length; i++)
			for(int j=0; j<length; j++)
				if ( isP[i][j] && j-i+1 > maxLen ) maxLen = j-i+1 , sta = i ;
		return str.substr(sta, maxLen);
    }
	
	int MAXSIZE = 1000;
    string longestPalindrome_xiao2(string str)
	{
		int length = str.size();
		bool isP[MAXSIZE][MAXSIZE];
		int maxLen = 1, sta = 0;
		memset(isP, false, sizeof(isP));
		for(int i=0; i<length; i++) isP[i][i] = true;
		for(int i=0; i<length-1; i++)
			if(str[i] == str[i+1])
				isP[i][i+1] = true, maxLen=2, sta = i;
		
		for(int len=3; len<=length; len++) 
			for(int i=0; i<length-len+1; i++)
			{
				int j = i+len-1;
				if (str[i] == str[j]) isP[i][j] = isP[i+1][j-1];
				if (isP[i][j] && j-i+1 > maxLen ) maxLen = j-i+1 , sta = i ;
			}
		return str.substr(sta, maxLen);
	}
	
	
	bool dp[1000][1000];
    string longestPalindrome_zhang(string s)
    {
        int maxi=0, maxj=0,n=s.size();
        for(int i=0;i<=n-1;i++)
            memset(dp[i],0,sizeof(dp[i]));
        for(int i=0;i<=n-1;i++)
            dp[i][i]=1;//len=1
        for(int i=0;i<=n-2;i++)
        {
            if(s[i]==s[i+1])//len=2
                dp[i][i+1]=1,maxi=i,maxj=i+1;
        }
        for(int len=3;len<=n;len++)
        {
            for(int i=0;i<=n-1;i++)
            {
                int j=i+len-1;
                if(j>=n)
                    break;
                if(s[i]==s[j])
                    dp[i][j]=dp[i+1][j-1];
                if(dp[i][j])
                    maxi=i,maxj=j;
            }
        }
        return s.substr(maxi, maxj-maxi+1);
    }
} F;

int main()
{
	string str="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabcaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	
	time_t start=clock();
	F.longestPalindrome_xiao2(str);
	time_t end=clock();
	cout<<end-start<<endl;
	
	start=clock();
	F.longestPalindrome_xiao(str);
	end=clock();
	cout<<end-start<<endl;
	return 0;
}