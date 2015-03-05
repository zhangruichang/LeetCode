#ifndef SOLUTION_H
#define SOLUTION_H
/*
'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") ¡ú false
isMatch("aa","aa") ¡ú true
isMatch("aaa","aa") ¡ú false
isMatch("aa", "*") ¡ú true
isMatch("aa", "a*") ¡ú true
isMatch("ab", "?*") ¡ú true
isMatch("aab", "c*a*b") ¡ú false
*/
#include <cstring>
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
class Solution
{
    public:
        Solution();
        bool isMatch(const char* s, const char* p)//scrolling array dp
        {
            int slen=strlen(s), plen=strlen(p);
            bool *lastdp=new bool[slen+1], *curdp=new bool[slen+1];
            lastdp[0]=1;
            for(int j=1;j<=slen;j++) lastdp[j]=0;
            for(int i=1;i<=plen;i++)
            {
                if(p[i-1]=='*') curdp[0]=lastdp[0];
                else curdp[0]=0;
                for(int j=1;j<=slen;j++)
                {
                    if(p[i-1]==s[j-1] || p[i-1]=='?') curdp[j]=lastdp[j-1];
                    else if(p[i-1]=='*') curdp[j] = lastdp[j] || lastdp[j-1];
                }
                swap(lastdp, curdp);
            }
            return lastdp[slen];
        }
        virtual ~Solution();
    protected:
    private:
};

#endif // SOLUTION_H
