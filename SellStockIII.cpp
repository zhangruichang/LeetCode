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

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n=prices.size();
        vector<int> L(n,0), R(n,0);
        int curmax=0,s=0;
        for(int i=1;i<n;i++)
        {
            if(prices[i]>prices[i-1])
                L[i]=max(L[i-1],prices[i]-prices[s]);
            else if(prices[i]<prices[s])
                L[i]=L[i-1],s=i;
            else
                L[i]=L[i-1];
        }
        s=n-1;curmax=0;
        for(int i=n-2;i>=0;i--)
        {
            if(prices[i]<prices[i+1])
                R[i]=max(R[i+1],prices[s]-prices[i]);
            else if(prices[i]>prices[s])
                R[i]=R[i+1],s=i;
            else
                R[i]=R[i+1];
        }
        int maxn=0;
        for(int i=0;i<n;i++)
            maxn=max(maxn,L[i]+R[i]);
        return maxn;
    }
    
        int maxProfit_yifu(vector<int> &prices) {
        int n=prices.size();if(n<=0) return 0;
        vector<int> L(n,0), R(n,0);
        int minn=prices[0];
        for(int i=1;i<n;i++)
        {
            L[i]=max(L[i-1],prices[i]-minn);
            minn=min(minn,prices[i]);
        }
        int maxn=prices[n-1];
        for(int i=n-2;i>=0;i--)
        {
            R[i]=max(R[i+1],maxn-prices[i]);
            maxn=max(maxn,prices[i]);
        }
        
        maxn=0;
        for(int i=0;i<n;i++)
            maxn=max(maxn,L[i]+R[i]);
        return maxn;
    }
} F;


int main()
{
    vector<int> prices;
    cout<<F.maxProfit(prices)<<endl;
	return 0;
}