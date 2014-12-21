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
int a[10]={1,2,3,4,5,5};
int n;
int partition(int low, int high)
{
    int i=low-1,pivot=a[high];
    for(int j=low;j<high;j++)
    {
        if(a[j]>pivot)
            swap(a[++i], a[j]);
    }
    swap(a[i+1],a[high]);
    return i+1;
}

void Qsort(int low, int high)
{
    if(low<high)
    {
        int mid=partition(low, high);
        Qsort(low, mid-1);
        Qsort(mid+1, high);
    }
}

int main()
{
    n=sizeof(a)/sizeof(int);
    Qsort(0,n-1);
    return 0;
}