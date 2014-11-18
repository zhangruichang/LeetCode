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
    int n;
    vector<string> cur,ans;
    string str;
    
    bool valid(string s)//1<=len<=3
    {
      if(s[0]=='0' && s.size()>=2) return 0;
      const char*s_cstr=s.c_str();
      int x=atoi(s_cstr);
      //cout<<x<<endl;
      if(x<=255 && x>=0) return 1;
      else return 0;
    }
    
    vector<string> restoreIpAddresses(string s)
    {
      str=s;
      n=str.size();
      cur.clear(),ans.clear();
      
      dfs(0,0);
      return ans;
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
  //cout<<atoi("010")<<' '<<atoi("000")<<' '<<atoi("011")<<endl;
  vector<string> ans=F.restoreIpAddresses("010010");
  for(int i=0;i<ans.size();i++)
  {
    cout<<ans[i]<<'\n';
  }
  return 0;
}