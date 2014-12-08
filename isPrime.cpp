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
#include <sstream>
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



int main()
{
    int N=1000;
    bool IsPrime[N+1];
    //memset(IsNotPrime,0,sizeof(IsNotPrime));
    for(int i=1;i<=N;i++) IsPrime[i]=1;
    IsPrime[1]=0;//IsNotPrime[2]=1;
    int cnt=0;
    for(int i=2;i*i<=N;i++)
    {
        if(!IsPrime[i])
            continue;
        //cout<<i<<" ";
        for(int j=i*i;j<=N;j+=i)
            IsPrime[j]=0,cnt++;
    }
    cout<<cnt<<endl;
    for(int i=1;i<=N;i++) if(IsPrime[i]) cout<<i<<" ";
    //return 0;
    
    return 0;
}