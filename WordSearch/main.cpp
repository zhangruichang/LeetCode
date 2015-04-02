/*
Author: richard
Contact: zhangruichang112@gmail.com
*/
#include<set>
#include<map>
#include<list>
#include<cmath>
#include<queue>
#include<stack>
#include<ctime>
#include<cstdio>
#include<string>
#include<vector>
#include<climits>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<iostream>
#include<algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;
const int maxn = 1e6 + 10;
typedef long long LL;
typedef unsigned long long ULL;
//int, -2^31~2^31-1    -2.1*10^9~2.1*10^9 (-2147483648-2147483647)
//unsigned int, 0~2^32-1  0~4.2*10^9
//long long  -2^63~2^63-1 -9*10^18~9*10^18
//unsigned long long 0~2^64-1  0~1.8*10^19
typedef pair<int, int> pii;
typedef vector<int> vi;
#define fi first
#define se second
int getint(){
	int t = 0, flag = 1; char c = getchar();
	while (c<'0' || c>'9' || c == '-')
	{
		if (c == '-')
			flag = -1;
		c = getchar();
	}
	while (c >= '0'&&c <= '9')
		t = t * 10 + c - '0', c = getchar();
	return t*flag;
}
int GCD(int m, int n)
{
    return !m ? n : GCD(n%m, m);
}
int a[maxn], n, t, m;


class Solution {
public:
    bool v[400][400];int n, m;string word_;
    const int dx[4]={-1, 1, 0, 0}, dy[4]={0,0,-1,1};
    vector<vector<char> > b;
    bool out(int i, int j)
    {
        return i<0 || i>=n || j<0 || j>=m;
    }
    bool dfs(int curi, int curj, int wi)
    {
        if(wi==word_.size()) return 1;
        if(out(curi, curj) || v[curi][curj] || b[curi][curj]!=word_[wi]) return 0;
        v[curi][curj]=1;
        for(int k=0;k<4;k++)
        {
            int nx=curi+dx[k], ny=curj+dy[k];
            if(dfs(nx, ny, wi+1)) return 1;
        }
        v[curi][curj]=0;
        return 0;
    }
    bool exist(vector<vector<char> > &board, string word) {
        word_=word;n=board.size(),m=board[0].size();b=board;
        memset(v, 0, sizeof(v));
        for(int i=0;i<n;i++) for(int j=0;j<m;j++)
        {
            if(dfs(i, j, 0)) return 1;
        }
        return 0;
    }
} S;

int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    //Solution S;
    vector<vector<char>> b={{'A','B','C','E'},
  {'S','F','C','S'},
  {'A','D','E','E'}};string word="ABCB";
    cout<<S.exist(b, word)<<endl;
	return 0;
}
