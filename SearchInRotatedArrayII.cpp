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
    bool search(int a[], int n, int x) {
        int low=0,high=n-1;
        if(n==1) return a[0]==x;
        if(a[low]<a[high])
        {
            
            while(low<=high)
            {
                if(low==high) return a[low]==x;
                if(low+1==high) return a[low]==x || a[high]==x;
                int mid=(low+high)/2;
                if(a[mid] < x) low=mid+1;
                else if(a[mid] > x) high=mid-1;
                else
                    return 1;
            }
            return 0;
        }
        
        while(low<=high)
        {
            if(low==high) return a[low]==x;
            if(low+1==high) return a[low]==x || a[high]==x;
            int mid=(low+high)/2;
            if(x==a[mid]) return 1;
            else if(x< a[mid])
            {
                if(a[mid] < a[high]) high=mid-1;
                else if( a[mid] > a[high]) 
                {
                    if(x>a[low]) high=mid-1;
                    else if(x<a[low]) low=mid+1;
                    else
                        return 1;
                }
                else
                    high--;
            }
            else
            {
                if(a[mid] > a[high]) low=mid+1;
                else if(a[mid] < a[high])
                {
                    if(x< a[high]) low=mid+1;
                    else if(x> a[high]) high=mid-1;
                    else
                        return 1;
                }
                else
                    high--;
            }
        }
        return 0;
    }
} F;

int main()
{
    int a[]={3,1,1};int x=0;int n=sizeof(a)/sizeof(int);
    cout<<F.search(a,n,x)<<endl;
    return 0;
}