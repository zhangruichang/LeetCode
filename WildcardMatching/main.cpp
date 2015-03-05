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
#include<iostream>
#include<algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;
//const int maxn = 1e3 + 10;
typedef long long LL;
typedef unsigned long long ULL;
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define mp make_pair
#define pb push_back
#define CLR(a,x) memset(a,x,sizeof(a))

//isMatch("aa","a")  ¡ú  false
//isMatch("aa","aa")  ¡ú  true
//isMatch("aaa","aa")  ¡ú  false
//isMatch("aa",  "*")  ¡ú  true
//isMatch("aa",  "a*")  ¡ú  true
//isMatch("ab",  "?*")  ¡ú  true
//isMatch("aab",  "c*a*b")  ¡ú  false


const int maxn = 1e3 + 10;
class Solution
{
private:
    bool dp_cache[maxn][maxn];
    bool isMatch_cache(const char*ss, const char*ps, const char*s, const char*p )
    {
        if(dp[s-ss][p-ps]) return 1;
        if(!*p) return dp[s-ss][p-ps]=!*s;
        if(*p!='*')
        {
            if(*p=='?' || *p==*s) return dp[s-ss][p-ps]=isMatch_cache(ss, ps, s+1, p+1);
            return dp[s-ss][p-ps]=0;
        }
        else
        {
            while(*s)
            {
                if(isMatch_cache(ss, ps, s, p+1)) return dp[s-ss][p-ps]=1;
                s++;
            }
            return dp[s-ss][p-ps]=isMatch_cache(ss, ps, s, p+1);
        }
    }
public:
    bool isMatch(const char *s, const char *p) {
        memset(dp, 0, sizeof(dp));
        return isMatch_cache(s, p, s, p);
    }
    bool  isMatch_recur(const  char*s,  const  char*p)  {
        if(!*p) return !*s;
        if(*p!='*')
        {
            if(*p=='?'&& *s || *p==*s) return isMatch_recur(s+1, p+1);
            return 0;
        }
        else
        {
            while(*s)
            {
                if(isMatch_recur(s, p+1)) return 1;
                s++;
            }
            return isMatch_recur(s, p+1);
        }
    }
    bool dp[maxn][maxn];
    bool isMatch_dp(const char*s, const char*p)
    {
        int slen=strlen(s), plen=strlen(p);
        memset(dp, 0, sizeof dp);
        dp[0][0]=1;int i;
        for(i=1;i<=plen;i++)
        {
            if(p[i-1]=='*') dp[i][0]=1;
            else break;
        }
        for(int j=i;j<=plen;j++) dp[j][0]=0;
        for(int j=1;j<=slen;j++) dp[0][j]=0;
        for(int i=1;i<=plen;i++)
        {
            if(p[i-1]!='*')
            {
                for(int j=1;j<=slen;j++)
                    dp[i][j]=dp[i-1][j-1] && (p[i-1]=='?' && s[j-1] || p[i-1]==s[j-1]);
            }
            else
            {
                int j;
                for(j=0;j<=slen;j++)
                {
                    if(dp[i-1][j]) break;
                    dp[i][j]=0;
                }
                for(int jj=j;jj<=slen;jj++) dp[i][jj]=1;
            }
        }
        return dp[plen][slen];
    }
    const int LEN=1e+7;
    int curdp[maxn], lastdp[maxn];
    bool isMatch_dp_reducespace(const char*s, const char*p)
    {
        int slen=strlen(s), plen=strlen(p);
        memset(lastdp, 0, sizeof lastdp);
        memset(curdp, 0, sizeof curdp);
        lastdp[0]=1;
        for(int j=1;j<=slen;j++) lastdp[j]=0;
        for(int i=1;i<=plen;i++)
        {
            if(p[i-1]!='*')
            {
                curdp[0]=0;
                for(int j=1;j<=slen;j++)
                    curdp[j]=lastdp[j-1] && (p[i-1]=='?' && s[j-1] || p[i-1]==s[j-1]);
            }
            else
            {
                int j;
                for(j=0;j<=slen;j++)
                {
                    if(lastdp[j]) break;
                    curdp[j]=0;
                }
                for(int jj=j;jj<=slen;jj++) curdp[jj]=1;
            }
            for(int j=0;j<=slen;j++) lastdp[j]=curdp[j];
        }
        return curdp[slen];
    }
    bool isMatch_g(const char* s, const char* p)
	{
		if (!s || !p) return false;
		int n = strlen(s);
		bool *pre = new bool[n + 1];
		bool *now = new bool[n + 1];
		pre[0] = true;
		for (; *p; p++) {
			if (*p == '*') {
				bool flag = false;
				for (int i = 0; i <= n; i++)
					now[i] = flag |= pre[i];
			} else {
				now[0] = false;
				for (int i = 1; i <= n; i++)
					now[i] = pre[i - 1] && (*p == '?' || *p == s[i - 1]);
			}
			swap(pre, now);
		}
		bool ans=pre[n];
		delete[] now;
		delete[] pre;
		return ans;
	}
} F;


void ZeroPartition(vector<int>& a)
{
    int n=a.size();
    int i=0, j=n-1, pivot=a[0];
    while(i<j)
    {
        while(i<j && !a[j]) j--;
        while(i<j && a[i]) i++;
        if(i<j) swap(a[i], a[j]);
    }
    swap(a[0], a[i]);
}

int main()
{
    vector<int> v={1,0,315,246,3460,0,0,235,235,125};
    ZeroPartition(v);
    for(auto i: v) cout<<i<<" ";
    cout<<endl;
    /*
    char s[100], p[100];
    while(~scanf("%s%s", s, p))
    {
        time_t start=clock();
        cout<<F.isMatch_dp_reducespace(s, p)<<endl;
        time_t end=clock();
        if(end-start>1000) cout<<"time: "<<end-start<<endl;
    }*/
	return 0;
}
