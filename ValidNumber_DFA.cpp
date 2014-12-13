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
    int CharIndex(char c)
    {
        if(c=='+' || c=='-' ) return 0;
        else if(isdigit(c)) return 1;
        else if(c=='.') return 2;
        else if(c=='e' ||c=='E') return 3;
        else
            return -1;
    }
    bool isNumber(const char *s) {
        
        int transfer[8][4]={//+,-  digit  dot  exp
            1,2,6,0,
            0,2,6,0,
            0,2,/*6*/7,3,
            4,5,0,0,
            0,5,0,0,
            0,5,0,0,
            0,7,0,/*3*/0,
            0,7,0,3
        };
        while( *s == ' ') s++;// delete preceding space
        if(!(*s)) return 0;// only with space
        int status=0;
        while(*s)
        {
            if(*s == ' ')
            {
                while(*s==' ') s++;//post space
                if(!(*s)) break;
                else
                    return 0;
            }
            int i=CharIndex(*s);
            if(i==-1) return 0;
            status=transfer[status][i];
            if(!status) return 0;
            s++;
        }
        return status==2 || status==5 || status==7;
    }
} F;
//3. --> 1
//.1 --> 1
//. --> 0
 

int main()
{
    char s[1024];
    while(gets(s))
        cout<<F.isNumber(s)<<endl;
    return 0;
}