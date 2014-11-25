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
    int search(int A[], int n, int target) {
        int left=0,right=n-1;
        if(A[left] < A[right]) 
        {
            while(left<=right)
            {
                int mid=(left+right)/2;
                if(A[mid] < target) left=mid+1;
                else if(A[mid] > target) right =mid-1;
                else
                    return mid;
            }
            return -1;
        }
        while(left<=right)
        {
            //assume >=3 elems
            if(left==right) return target==A[left]?left:-1;
            if(left+1==right)
            {
                if(A[left] == target) return left;
                else if(A[right]==target) return right;
                else 
                    return -1;
            }
            int mid=left+(right-left)/2;
            if(target== A[mid]) return mid;
            else if(target > A[mid] )
            {
                if(A[mid] <= A[left] && target> A[right])
                    right=mid-1;
                //else if(target==A[right]) 
                //    return right;
                else
                    left=mid+1;                
            }
            else
            {
                if(A[mid] >= A[left] && target <A[left])
                    left=mid+1;
                else
                    right=mid-1;
            }
        }
        return -1;
    }
};