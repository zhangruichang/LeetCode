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
    bool isScramble(string s1, string s2) {
        int cnt1[128],cnt2[128];
        memset(cnt1,0,sizeof(cnt1));memset(cnt2,0,sizeof(cnt2));
        for(int i=0;i<s1.size();i++) cnt1[s1[i]]++;
        for(int i=0;i<s2.size();i++) cnt2[s2[i]]++;
        for(int i=0;i<128;i++) if(cnt1[i]!=cnt2[i]) return 0;
        return 1;
    }
} F;

int main()
{
    cout<<F.isScramble("great","rgeat");
    return 0;
}