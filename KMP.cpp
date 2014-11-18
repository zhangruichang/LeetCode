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

int patlen,Strlen;
string pat, str;
int nextn[maxn];
void GetNext()
{
    nextn[0]=-1;
    for(int i=0;i<=patlen-2;i++)
    {
        int k=nextn[i];
        while(k!=-1 && pat[k]!=pat[i])
            k=nextn[k];
        nextn[i+1]=k+1;
    }
}
int Match()
{
   int i=0,j=0;
   while(i<Strlen)
   {
        if(j==-1 || str[i]==pat[j])
            i++,j++;
        else
            j=nextn[j];
        if(j==patlen)
            return i-j;//match start in str
   }
   return -1;
}


int main()
{
    str="cbababababab", pat="abababac";
    Strlen=str.size();patlen=pat.size();
    GetNext();cout<<Match()<<endl;
	return 0;
}