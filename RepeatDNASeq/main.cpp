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
#include<sstream>
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

#define fi first
#define se second
class Solution {
public:
    int GetIndex(char s)
    {
        if(s=='A') return 0;
        if(s=='T') return 1;
        if(s=='G') return 2;
        if(s=='C') return 3;
    }
    vector<string> findRepeatedDnaSequences(string s) {
        int n=s.size();
        unordered_map<int, pair<int, int>> myhash;
        string dna=s.substr(0, 10);
        int val=0;
        for(auto e: dna)
            val=val*4+GetIndex(e);
        myhash[val].fi++;myhash[val].se=i;
        int m=0x000fffff;
        for(int i=1;i+9<n;i++)
        {
            val<<=2;
            val&=m;
            val+=GetIndex(s[i+9]);
            myhash[val].fi++;myhash[val].se=i;
        }
        vector<string> ans;
        for(auto e: myhash)
        {
            if(e.se.fi>1) ans.push_back(s.substr(e.se.se, 10));
        }
        return ans;
    }
};
/*
class Solution {
public:
    int GetIndex(char s)
    {
        if(s=='A') return 0;
        if(s=='T') return 1;
        if(s=='G') return 2;
        if(s=='C') return 3;
    }
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() <= 10)
            return {};

        unordered_map<int, int> um;
        int m = 0x000FFFFF;
        size_t len = s.size();
        vector<string> result;
        int val = 0;
        for (int i = 0; i < 9; i++)
        {
            val = val << 2;
            val += GetIndex(s[i]);
        }
        for (int i = 9; i < len; i++)
        {
            val = val << 2;
            val += GetIndex(s[i]);
            val = val & m;
            um[val]++;
            if (um[val] == 2) result.push_back(s.substr(i - 10 + 1, 10));
        }
        return result;

    }
};
*/

int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    cin>>t;
    for(int ti=1;ti<=t;ti++)
    {
        //cin
        printf("Case #%d:\n", ti);
        //cout
    }
	return 0;
}
