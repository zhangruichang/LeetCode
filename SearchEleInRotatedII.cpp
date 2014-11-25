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
    bool search(int A[], int n, int target) {
        int left=0,right=n-1;
        while(left<right)
        {
            if(A[left] < A[right]) 
            {
                while(left<=right)
                {
                    int mid=left+(right-left)/2;
                    if(target>A[mid]) left=mid+1;
                    else if(target<A[mid]) right=mid-1;
                    else return 1;
                 }
                 return 0;
            }
            //return target<=A[right] & target >= A[left];
            if(left+1==right) return A[left]==target || A[right]==target;
            
            int mid=left+(right-left)/2;
            if(A[mid] == target) return 1;
            else if(A[mid] < target)
            {
                if(A[mid] > A[left]) // left part
                    left=mid+1;
                else
                {
                    if(target<A[right])
                        left++;
                    else if(target==A[right])
                        return 1;
                    else
                        left++;
                }                
            }
            else
            {
                if(A[mid] < A[right])
                    right=mid-1;
                else    
                {
                    if(target < A[left]) left=mid+1;
                    else if(target==A[left]) return 1;
                    else
                        right=mid-1;
                }
            }
        }
        return A[left]==target;
    }
};

int main()
{
    return 0;
}