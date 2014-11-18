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
    bool dp[1000][1000];
    bool isInterleave(string s1, string s2, string s3) {
        int n1=s1.size(),n2=s2.size(),n3=s3.size(); if(n1+n2!=n3) return 0;
        for(int i=0;i<=n1;i++) dp[i][0] = (s1.substr(0,i)==s3.substr(0,i) );
        for(int j=0;j<=n2;j++) dp[0][j] = (s2.substr(0,j)==s3.substr(0,j) );
        
        for(int i=1;i<=n1;i++) for(int j=1;j<=n2;j++)
        {
            dp[i][j]=(dp[i-1][j]&&s1[i-1]==s3[i+j-1]) +(dp[i][j-1] && s2[j-1] ==s3[i+j-1]);
        }
        return dp[n1][n2];
    }
} F;

int main()
{
    cout<<F.isInterleave("aabcc","dbbca","aadbbbaccc");
	return 0;
}