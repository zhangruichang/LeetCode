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
#include <iostream>
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
    bool isMatch(const char *s, const char *p) {//s "aabababa" p "a*babab*ab"
        int slen=strlen(s),plen=strlen(p);
        int i=0,j=0,k=0;
        while(i<slen && j<plen)
        {
            if(p[j]!='*')
            {
                if(s[i]==p[j]) i++,j++;
                else
                    return 0;
            }
            else
            {
                i++,j++;
            }
        }
        return i==slen && j==plen;
    }
} F;

int main()
{
    char s[1024],p[1024];
    while(scanf("%s%s",s,p)!=EOF)
        cout<<F.isMatch(s,p)<<endl;
    return 0;
}