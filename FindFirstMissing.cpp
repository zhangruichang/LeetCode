#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    int firstMissingPositive(int a[], int n) {
        for(int i=0;i<n;i++)
        {
          int cur=a[i];
          if(cur-1>=n || cur-1<0) continue;
          swap(a[i],a[cur-1]);
          if(a[i]!=a[cur-1])i--;
        }
        for(int i=0;i<n;i++)
        {
          if(a[i]!=i+1)
            return i+1;
        }
        return n+1;
    }
};