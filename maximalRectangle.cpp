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

struct
{
  int rown,coln;
}info;

public:
    info dp[1000][1000];
    int maximalRectangle(vector<vector<char> > &matrix) {
      for(int i=1;i<=m;i++)
      {
        for(int j=1;j<=n;j++)
        {
          int maxn=0;
          if(matrix[i][j]=='0') dp[i][j]=0;
          else
          {
            for(k=j-1,col=2  ;col<=dp[i-1][j].coln && board[i][k]=='1'; col++,k--);
            
            maxn=max(maxn,(j-k) * (dp[i-1][j].rown+1) );
            
            for(k=i-1,row=2 ; row<=dp[i][j-1].row && board[k][j]=='1'; row++, k--);
            
            maxn=max(maxn, (i-k) * (dp[i][j-1].coln+1) );
            
            dp[i][j]=maxn;
          }
        }
      }
        
    }
};