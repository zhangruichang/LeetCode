//https://www.hackerrank.com/challenges/string-reduction/submissions/code/10729515
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
#include<list>
#include<ctime>
#include<climits>
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


int stringReduction(char a[]) {
   int cnta=0, cntb=0, cntc=0;
   int alen=strlen(a);
   for(int i=0;i<alen;i++)
   {
       if(a[i]=='a') cnta++;
       else if(a[i]=='b') cntb++;
       else cntc++;
   }
   if(cnta && !cntb &&!cntc || cntb && !cntc &&!cnta ||cntc && !cnta &&!cntb) return alen;
   if((cnta &1) && (cntb &1) && (cntc &1) || !(cnta &1) && !(cntb &1) && !(cntc &1)) return 2;
   return 1;
}
//重要结论题，1 2 或者字符串长度，1 2 取决于ab c的奇偶性，张神说的，通过简单枚举发现均为奇数或偶数个为2，其他情况为1，
//ON 算法，陈立人博客也有，DP题，但是DP是二维的复杂度不如这个数学结论~~
int main() {
    //freopen("input01.txt","r",stdin);
    //freopen("output01_my.txt","w",stdout);

    int res, t, i;
    scanf("%d",&t);
    char a[100001];
    for (i=0;i<t;i++) {
        scanf("%s",a);
        res=stringReduction(a);
        printf("%d\n",res);
    }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
