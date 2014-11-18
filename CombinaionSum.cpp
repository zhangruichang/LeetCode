#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cstring>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<cstdlib>
#include<ctime>
#include<set>
#include<math.h>
using namespace std;
typedef long long LL;
const int maxn = 1e8 + 10;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define pb push_back

class Solution {
public:
    vector<int> cur,can;
    vector<vector<int> > ans; 
    int n;
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        cur.clear();
        ans.clear();
        can=candidates;
        n=can.size();
        sort(can.begin(),can.end());
        dfs(0,target);
        return ans;
    }
    
    void dfs(int i, int target)
    {
      if(target==0) {ans.push_back(cur);return;}
      if(i>=n)
      {
        return ;
      }
      else
      {
        for(int k=0;k<=target/can[i];k++)
        {
          for(int l=0;l<k;l++)
            cur.push_back(can[i]);
          dfs(i+1,target-k*can[i]);
          for(int l=0;l<k;l++)
            cur.pop_back();
        }
      }
    }
} F;

int main()
{
  vector<int> can({2,3});
  int target=1;
  auto ans=F.combinationSum(can,target);
  for(int i=0;i<ans.size();i++)
  {
    for(int j=0;j<ans[i].size();j++)
      cout<<ans[i][j]<<" ";
    cout<<'\n';  
  }
  return 0;
}