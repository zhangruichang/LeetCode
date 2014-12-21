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

//question: 
//http://mp.weixin.qq.com/s?__biz=MjM5ODIzNDQ3Mw==&mid=200539538&idx=1&sn=cd4e36f759fb22091e6ce86e51670fb5#rd

int dp[maxn];
int a[maxn];
int n;
string str;
int MaxLen()
{
    dp[0]=0;
    int maxlen=0,maxi;
    for(int i=1;i<=n;i++)
    {
        int sum=0;
        for(int j=0;j<i;j++) sum+=a[j];//sum a[0...i-1]
        int lastnum=i;
        dp[i]=0;
        for(int j=0;j<i;j++)
        {
            if(sum==0)
                dp[i]=max(dp[i],dp[j]+lastnum);
            sum-=a[j];
            lastnum--;
        }
        if(maxlen< dp[i])
            maxlen=dp[i],maxi=i;
        //maxlen=max(maxlen, dp[i]);
    }
    cout<<str.substr(maxi-dp[maxi],dp[maxi]);
    return maxlen;
}

int MaxLen_Scan()
{
    dp[0]=a[0];;//dp[i]:sum [0,,i]
    for(int i=1;i<n;i++)
        dp[i]=dp[i-1]+a[i];
    unordered_map<int, vector<int> > table;
    for(int i=0;i<n;i++)
        table[dp[i]].push_back(i);
    int maxlen=0;;
    for(auto i:table)
    {
        if(!i.first)
            maxlen=max(maxlen, *max_element(i.second.begin(), i.second.end())+1);
        else
            maxlen=max(maxlen, *max_element(i.second.begin(), i.second.end())-*min_element(i.second.begin(), i.second.end()));
    }
    return maxlen;
}

int main()
{
    freopen("in.txt","r",stdin);

    while(cin>>str)
    {
        puts(str.c_str());
        n=str.size();
        for(int i=0;i<n;i++)
            a[i]= (str[i]=='0' ? -1 : 1);
        cout<<" "<<MaxLen()<<endl;
    }
    return 0;
}
