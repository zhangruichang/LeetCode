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
    int curdp[100000];//,lastdp[100000];
    int numDistinct(string S, string T) {
        int m=S.size(),n=T.size();
        for(int j=0;j<=n;j++) curdp[j]=0; curdp[0]=1;
        for(int i=1;i<=m;i++) for(int j=n;j>=1;j--)
            if(S[i-1]==T[j-1]) curdp[j]+=curdp[j-1];
        return curdp[n];
    }
} F;

int main()
{
    cout<<F.numDistinct("rabbbit","rabbit");
    return 0;
}