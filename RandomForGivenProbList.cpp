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
#include <climits>
using namespace std;
const int maxn = 1e5 + 10;
typedef long long LL;
typedef unsigned long long ULL;
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define mp make_pair
#define pb push_back
#define CLR(a,x) memset(a,x,sizeof(a))

double Prob[2]={0.9,0.1};

int Random()
{
    double r=double(rand())/RAND_MAX;
    double s=0;
    for(int i=0;i<2;i++)
    {
        s+=Prob[i];
        if(s>=r)
            return i;
    }
}

int cnt[2];
int main()
{
    //cout<<INT_MAX<<endl<<RAND_MAX<<endl;
    memset(cnt,0,sizeof(cnt));
    int test_times=10000000;
    for(int i=0;i<test_times;i++)
        cnt[Random()]++;
    cout<<cnt[0]<<" "<<cnt[1]<<endl;
    cout<<"0: "<<double(cnt[0])/test_times<<endl;
    cout<<"1: "<<double(cnt[1])/test_times<<endl;

    return 0;
}
