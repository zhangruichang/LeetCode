#include <cctype>
#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<cstdlib>
#include<vector>
#include<set>
#include<map>
#include<stack>
using namespace std;
const int maxn = 1e5 + 10;
typedef long long LL;
typedef unsigned long long ULL;
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define mp make_pair
#define pb push_back
#define CLR(a,x) memset(a,x,sizeof(a))

class Solution {
public:
    bool dp[1000];
    vector<string> cur,ans;
    int n;string str;
    bool valid(string s)
    {
      const char*s_cstr=s.c_str();
      int x=atoi(s_cstr);
      cout<<x<<endl;
      if(x<=255 && x>=1) return 1;
      else return 0;
    }
    vector<string> restoreIpAddresses_dp(string s) {
        n=s.size();
        memset(dp,0,sizeof(dp));
        dp[n]=1;
        str=s;
        for(int i=n-1;i>=0;i--)
        {
          for(int len=1;len<=3;len++)
          {
            if(i+len<=n)
              if(valid(s.substr(i,len)) && dp[i+len]) {dp[i]=1;break;}
          }
        }
        ans.clear(),cur.clear();
        for(int i=0;i<=n;i++) cout<<dp[i]<<" ";
        dfs(0);
        return ans;
    }
    void dfs(int i)
    {
      if(i>=n)
      {
        string tmpans;
        for(int j=0;j<cur.size();j++)
          tmpans+=cur[i]+'.';
        tmpans.pop_back();
        ans.push_back(tmpans);
      }
      else
      {
        for(int len=1;len<=3;len++)
        {
          if(i+len<=n)
            if( valid( str.substr(i,len)) && dp[i+len] )
              cur.push_back(str.substr(i,len)+'.'),dfs(i+len),cur.pop_back();
        }
      }
    }
    
    vector<string> restoreIpAddresses(string s)
    {
      dfs(0,0);
    }
    
    void dfs(int si, int depth)
    {
      if(depth>=4)
      {
        if(si==n)
        {
          string tmpans;
          for(int i=0;i<cur.size();i++)
            tmpans+=cur[i]+".";
          tmpans.pop_back();
          ans.push_back(tmpans);
        }
      }
      else
      {
        for(int len=1;len<=3;len++)
        {
          if(si+len<=n) if(valid(str.substr(si,len)))
            cur.push_back(str.substr(si,len)), dfs(si+len,depth+1), cur.pop_back();
        }
      }
    }
} F;


int main()
{
  auto ans=F.restoreIpAddresses("25525511135");
  for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";
  cout<<endl;
  return 0;
}