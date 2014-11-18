#include <string>
#include <cstdio>
#include <iostream>
using namespace std;

class Solution {
public:
    string str,newstr;
    int j,k,mx,maxp,id,maxi;
    int P[100000];
    bool dp[1000][1000];
    string longestPalindrome(string s) {
        str=s;
        Extend();
        LPS();
        string result;
        /*
        string withjing=newstr. substr(maxi-maxp+1,2*maxp-1);
        
        for(int i=0;i<withjing.size();i++)
        {
            if(withjing[i]!='#')
                result+=withjing[i];
        }*/
        return result;
    }
    
    string longestPalindrome_n2_enum(string s)
    {
        str=s;
        Extend();
        int maxextlen=0, centeri=0,extlen;
        int len=newstr.size();
        for(int i=0;i<len;i++)
        {
            extlen=0;
            while(i-extlen>=0 && i+extlen<=len-1 && newstr[i-extlen]==newstr[i+extlen])
                extlen++;
            extlen--;
            if(maxextlen<extlen)
                centeri=i,maxextlen=extlen;
        }
        string withjing=newstr.substr(centeri-maxextlen, 2*maxextlen+1);
        string result;
        for(int i=0;i<withjing.size();i++)
        {
            if(withjing[i]!='#')
                result+=withjing[i];
        }
        return result;
    }
    string longestPalindrome_n2_dp(string s)
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

void LPS()//2n+1
{
    P[0]=1;//len at least 1
    id=0, mx=id+P[id], maxp=0,maxi=0;
    int len=newstr.size();
    for(int i=1;i<=len-1;i++)
    {
        j=2*id-i;
		if(mx>i)
		{
			if(mx-i>=P[j])
				P[i]=P[j];
			else
			{
				P[i]=mx-i;
			}
		}
		else
			P[i]=1;
		while(i+P[i]<=len-1 && i+P[i]>=0 && i-P[i]<=len-1 && i-P[i]>=0 && newstr[i+P[i]]==newstr[i-P[i]])
			P[i]++;

        if(mx<i+P[i])
        {
            id=i;
            mx=id+P[id];
        } 
        if(maxp<P[i]-1)
            maxp=P[i]-1,maxi=i;
    }
	//for(int i=0;i<=len-1;i++)
	//	cout<<P[i]<<" ";
}

void Extend()
{
    string jing="#";
	newstr="#"; 
    for(int i=0;i<str.size();i++)
    {
		newstr+=str[i];
        newstr+=jing;
		//newstr+=str[i];
		//newstr+="#";
    }
    //cout<<newstr<<endl;
}
};



int main()
{
    freopen("LPS_in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    Solution S;
    string cppstr;
    while(getline(cin,cppstr))
    {
        cout<<S.longestPalindrome_n2_dp(cppstr)<<endl;
    }
    return 0;
}