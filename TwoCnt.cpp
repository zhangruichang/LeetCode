#include <iostream>
#include <cstdio>
using namespace std;
typedef unsigned long long ULL;

ULL TwoCnt(ULL n)//[0,n) count 2 numbers
{
    if(n<=2) return 0;
    ULL pro=10,cnt=0;
    while(pro/10 <= n)
    {
        if(n%pro >= 3* (pro/10) )
            cnt+=(n/pro+1) * (pro/10);
        else if(n%pro <2* (pro/10))
            cnt+=(n/pro) * (pro/10);
        else
            cnt+=(n/pro)*(pro/10)+ (n%pro-2*(pro/10));
        pro*=10;
        //cout<<cnt<<" ";
    }
    //cout<<endl;
    return cnt;
}

ULL TwoCnt_bf(ULL n)
{
    ULL cnt=0;
    for(ULL i=0;i<n;i++)
    {
        ULL tmpi=i;
        while(tmpi>0)
        {
            if(tmpi%10==2) cnt++; 
            tmpi/=10;
        }
    }
    return cnt;
}

int main()
{
    ULL n;
    freopen("TwoCntIn.txt","r",stdin);
    while(cin>>n)
    {
        
        if(TwoCnt(n)==TwoCnt_bf(n)) cout<<endl;
        else
            cout<<TwoCnt(n)<<" "<<TwoCnt_bf(n)<<endl;
        
        //cout<<TwoCnt(n)<<endl;
    }
    return 0;
}