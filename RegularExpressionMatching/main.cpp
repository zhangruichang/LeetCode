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
const int maxn = 1e5 + 10;
typedef long long LL;
typedef unsigned long long ULL;
//int, -2^31~2^31-1    -2.1*10^9~2.1*10^9 (-2147483648-2147483647)
//unsigned int, 0~2^32-1  0~4.2*10^9
//long long  -2^63~2^63-1 -9*10^18~9*10^18
//unsigned long long 0~2^64-1  0~1.8*10^19

/*
isMatch("aa","a")  ¡ú  false
isMatch("aa","aa")  ¡ú  true
isMatch("aaa","aa")  ¡ú  false
isMatch("aa",  "a*")  ¡ú  true
isMatch("aa",  ".*")  ¡ú  true
isMatch("ab",  ".*")  ¡ú  true
isMatch("aab",  "c*a*b")  ¡ú  true
"aa" "a**"
*/


class  SolutionAC  {
    public:
        bool  isMatch(const  char  *s,  const  char  *p)
        {
            if  (*p  ==  '\0')  return  *s  ==  '\0';
//  next  char  is  not  '*',  then  must  match  current  character
            if  (*(p  +  1)  !=  '*')
            {
                if  (*p  ==  *s  ||  (*p  ==  '.'  &&  *s  !=  '\0'))
                    return  isMatch(s  +  1,  p  +  1);
                else
                    return  false;
            }
            else        //  next  char  is  '*'
            {
                while  (*p  ==  *s  ||  (*p  ==  '.'  &&  *s  !=  '\0'))
                {
                    if  (isMatch(s,  p  +  2))
                        return  true;
                    s++;
                }
                return  isMatch(s,  p  +  2);
            }
        }
};

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        int slen=strlen(s), plen=strlen(p);
        int dp[plen+1][slen+1];
        memset(dp, 0, sizeof dp);
        dp[0][0]=1;
        for(int i=1;i<=plen;i++) if(p[i-1]=='*') dp[i][0]=dp[i-2][0];
        for(int j=1;j<=slen;j++) dp[0][j]=0;
        for(int i=1;i<=plen;i++) for(int j=1;j<=slen;j++)
        {
            if(p[i-1]=='.' || p[i-1]==s[j-1]) dp[i][j]=dp[i-1][j-1];
            else if(p[i-1]=='*')
            {
                if(p[i-2]==s[j-1] || p[i-2]=='.') dp[i][j]=dp[i-2][j] || dp[i][j-1];
                else dp[i][j]=dp[i-2][j];
            }
        }
        return dp[plen][slen];
    }
};


int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    freopen ("output.txt" , "w" , stdout);
#endif
*/
    SolutionAC S;
    char s[100], p[100];
    while(~scanf("%s%s",s, p))
        cout<<S.isMatch(s,p)<<endl;
	return 0;
}
