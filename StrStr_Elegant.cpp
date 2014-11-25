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
        int haylen=strlen(haystack),neelen=strlen(needle);
        int i=0,j=0,k=0;
        while((i+k) <haylen && j<neelen)
        {
            if(haystack[i+k]==needle[j]) k++,j++;
            else
                i++,j=k=0;
        }
        if(j==neelen) return i;
        else
            return -1;
    }
};