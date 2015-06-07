/*
Author: richard
Contact: zhangruichang112@gmail.com
*/
#include <bits/stdc++.h>
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
#define iOS  ios_base::sync_with_stdio(false)
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
template <typename T>
string to_string(T value)
{
  //create an output string stream
  ostringstream os ;

  //throw the value into the string stream
  os << value ;

  //convert the string stream into a string and return
  return os.str() ;
}
LL MultMod(LL a,LL b,LL MOD)
{
    a %= MOD;
    b %= MOD;
    LL ret = 0;
    while(b){
        if (b & 1){
            ret += a;
            if(ret >= MOD) ret -= MOD;
        }
        a = a << 1;
        if (a >= MOD) a -= MOD;
        b = b >> 1;
    }
    return ret;
}
int a[maxn], n, t, m;

class Solution {
public:
    int maximalSquare(vector<string>& M) {
        int m=M.size();
        if(m<=0) return 0;
        int n=M[0].size(),ans=0;
        for(int i=0;i<m;i++) for(int j=0;j<n;j++)
        {
            for(int k=0;k+i<m && k+j<n;k++)
            {
                bool rowok=1;
                for(int row=i;row<m && j+k<n && row<=i+k;row++)
                    if(M[row][j+k]=='0') {rowok=0;break;}
                bool colok=1;
                for(int col=j;i+k<m && col<n && col<=j+k;col++)
                    if(M[i+k][col]=='0') {colok=0;break;}
                if(rowok && colok) ans=max(ans, k+1);
                else break;
            }
        }
        return ans*ans;
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
    //vector<string> M={"10100","10111","11111","10010"};
    vector<string> M={"11","11"};
    cout<<S.maximalSquare(M);
	return 0;
}
