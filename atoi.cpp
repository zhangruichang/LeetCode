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
#include <cctype>
#include<map>
#include<stack>
#include <climits>
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
    int atoi(const char *str) {
        while(*str==' ') str++;
        if(!*str) return 0;
        bool flag=1;
        if(*str=='+') str++;
        else if(*str=='-') str++, flag=0;
        int sum=0;
        for(;isdigit(*str);str++)
        {
            if(flag && (sum==INT_MAX/10 && *str>'7' || sum>INT_MAX/10)) return INT_MAX;
            else if(!flag && (sum==INT_MAX/10 && *str>'8' || sum>INT_MAX/10) ) return INT_MIN;
            sum=sum*10+*str-'0';
        }
        return flag ? sum : -sum;
    }
} F;

int main()
{
    cout<<F.atoi(" -2147483648 ")<<endl;
	return 0;
}
