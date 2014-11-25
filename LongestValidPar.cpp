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
    int dp[100000];
    int longestValidParentheses(string s) {
        int n=s.size();
        int maxlen=0;
        memset(dp,0,sizeof(dp));
        for(int i=n-2;i>=0;i--)
        {
            //dp[i]=0;
            if(s[i]=='(') 
            {
                    int nexti=i+dp[i+1]+1;
                    if( nexti<=n-1 && s[nexti]==')')
                    {
                        
                        dp[i]=dp[i+1]+2;
                        if(nexti+1 <= n-1)
                            dp[i]+=dp[nexti+1];
                    }
            }
            maxlen=max(maxlen,dp[i]);
        }
        return maxlen;
    }
} F;
int main()
{
    cout<<F.longestValidParentheses("()(())")<<endl;
    return 0;
}