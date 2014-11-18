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
    string minWindow(string S, string T) {
        if(T=="") return "";
        int maxn=0x7fffffff,maxs,maxe;
        int cnt[128],cntnum=T.size();bool hascnt[128];
        memset(cnt,0,sizeof(cnt));memset(hascnt,0,sizeof(hascnt));
        for(int i=0;i<T.size();i++) cnt[T[i]]++,hascnt[T[i]]=1;;
        
        int slen=S.size(),s;
        
        for(int i=0;i<slen;)
        {
            if(!cnt[S[i]]) i++;
            else
            {
                if(cntnum==T.size()) s=i;
                cnt[S[i]]--;
                cntnum--;
                if(!cntnum)
                {
                    if(maxn>i-s+1)
                        maxn=i-s+1,maxs=s,maxe=i;
                    cnt[S[s]]++;cntnum++;
                    s++;
                    while(!hascnt[s]) s++;
                }
                i++;
            }
            cout<<s<<" "<<cnt['A']<<endl;;
        }
        if(maxn==0x7fffffff) return "";
        return S.substr(maxs,maxe-maxs+1);
    }
} F;


int main()
{
    cout<<F.minWindow("ADOBECODEBANC","ABC");
	return 0;
}