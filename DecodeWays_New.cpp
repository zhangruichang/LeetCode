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
#include <ctime>
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
    int cnt;
    int n;
    string s_;
    int dp[100000];
    int numDecodings_dfs(string s) {
        cnt=0;n=s.size();s_=s;
        dfs(0);
        return cnt;
    }
    void dfs(int i)
    {
        if(i>=n) cnt++;
        else
        {
            dfs(i+1);
            if(i<=n-2 && ( s_[i]=='1' || ( s_[i]=='2' && s_[i+1]<='6') ) )
                dfs(i+2);
        }
    }
    int numDecodings_dp(string s)
    {
        n=s.size();
        dp[0]=1;//dp[1]=1;
        for(int i=1;i<=n;i++)
        {
            if(s[i-1]!='0')
                dp[i]=dp[i-1];
            if( i-2>=0 && (s[i-2]=='1' || (s[i-2]=='2' && s[i-1]<='6')) )
               dp[i]+=dp[i-2];
        }
        return dp[n];
    }
    
} F;

int main()
{
   cout<<F.numDecodings_dp("10")<<endl; 
   return 0;
}