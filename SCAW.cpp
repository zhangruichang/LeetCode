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
#include <unordered_set>
#include <unordered_map>
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
    vector<int> findSubstring(string s, vector<string> &L) {
        unordered_map<string, int> t;
        vector<int> ans;
        if(L.size()<=0 || s.size()<=0) return ans;
        int slen=s.size(),lsize=L.size(),vssize=L[0].size();
        for(auto sl:L)
          t[sl]++;
        for(int i=0;i+lsize*vssize<=slen;i++)
        {
          //string sufstr=s.substr(i,lsize*vssize);
          //for(auto &it: t) it.second=0;//,cout<<it.first<<" "<<it.second<<" ";
          auto tmpt=t;
          //cout<<endl<<i<<endl;
          int k;
          //for(auto it:t) cout<<it.first<<" "<<it.second<<" ";
          for(k=0;k<lsize;k++)
          {
            auto it=tmpt.begin();
            //if(i==9) {cout<<s.substr(i+k*vssize, vssize)<<endl;for(auto it:t) cout<<it.first<<" "<<it.second<<" ";}
            if( (it=tmpt.find(s.substr(i+k*vssize, vssize) )) !=tmpt.end() && it->second>0)
              {it->second--;}//if(i==9) cout<<it->first<<endl;}
            else
              break;
          }
          if(k==lsize) ans.push_back(i);//cout<<k<<' '<<lsize<<endl;
        }
          /*
          dp[0]=1;
          for(int j=1;j<=sufstr.size();j++)
          {
            for(int k=1;k<j;k++)
            {
              if(dp[k] && (it=t.find(sufstr.substr(k,j-1-k+1))) != t.end() && it->second==0)
                it->second=1,dp[j]=1;
            }
          }*/

        return ans;
    }
} F;


int main()
{
  string s="lingmindraboofooowingdingbarrwingmonkeypoundcake";
  vector<string> vec({"fooo","barr","wing","ding","wing"});
  auto ans=F.findSubstring(s,vec);
  for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
  return 0;
}