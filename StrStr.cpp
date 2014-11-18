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
    int strStr(char *haystack, char *needle) {
        int m=strlen(haystack),n=strlen(needle);
        if(!n && !m) return 0;
        int i=0,j=0,si;
        while(i<m && j<n)
        {
            if(haystack[i]==needle[j])
            {
                si=i;
                while(si<m && j<n && haystack[si]==needle[j]) si++,j++;
                if(j==n) return si-j;
                if(si==m) return -1;
            }
            i++,j=0;
        }
        return -1;
    }
};