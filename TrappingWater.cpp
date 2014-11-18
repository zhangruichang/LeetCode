#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int trap(int a[], int n) {
      vector<int> l(n,0), r(n,0);
      
      l[0]=a[0];
      for(int i=1;i<n;i++)
        l[i]=max(l[i-1],a[i]);
      r[n-1]=a[n-1];
      for(int i=n-2;i>=0;i--)
        r[i]=max(r[i+1],a[i]);
      int ans=0;
      for(int i=0;i<n;i++)
        ans+=min(r[i],l[i])-a[i];
      return ans;
    }
} F;

int main()
{
  int a[]={1,0,0,1};
  int n=sizeof(a)/sizeof(int);
  cout<<F.trap(a,n)<<endl;
  
  return 0;
}