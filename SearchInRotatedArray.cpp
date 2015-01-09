https://oj.leetcode.com/problems/search-in-rotated-sorted-array-i/
class Solution {
public:
    int search(int A[], int n, int x) {
        int low=0, high=n-1;
        while(low<=high)
        {
            if(low+1==high) return A[low] == x ? low : (A[high]==x ? high : -1);//两个元素单独判,一个元素后面可以处理
            int mid=(low+high)/2;
            if(A[mid]==x) return mid;
            if(A[mid] > A[low])
            {
                if(A[low]<=x&&x<A[mid]) high=mid-1;//进行优化，只有x在左边，才搜左边，注意等号
                else low=mid+1;//否则都右边
            }
            else
            {
                if(A[mid] < x && x<= A[high]) low=mid+1;
                else
                    high=mid-1;
            }
        }
        return -1;
    }
};

//recursive solution
class Solution {
public:
    bool find(int A[], int low, int high, int x)
    {
        if(low<=high)
        {
            if(low+1==high) return A[low] == x ? 1 : (A[high]==x ? 1 : 0);
            int mid=(low+high)/2;
            if(x==A[mid]) return 1;
            if(A[mid] > A[low])
            {
                if(A[low] <=x && x<A[mid]) return find(A, low, mid-1, x);//high=mid-1;
                else return find(A, mid+1, high, x);
            }
            else if(A[mid] < A[low])
            {
                if(A[mid] < x && x<=A[high]) return find(A, mid+1, high, x);
                else return find(A, low, mid-1, x);
            }
            else
                return find(A, low+1, high, x);
        }
        return 0;
    }
    bool search(int A[], int n, int x) {
        return find(A, 0, n-1, x);
    }
};

https://oj.leetcode.com/problems/search-in-rotated-sorted-array-ii/
class Solution {
public:
    bool search(int A[], int n, int x) {
        int low=0, high=n-1;
        while(low<=high)
        {
            if(low+1==high) return A[low] == x ? 1 : (A[high]==x ? 1 : 0);//和上面类似思想
            int mid=(low+high)/2;
            if(x==A[mid]) return 1;
            if(A[mid] > A[low])
            {
                if(A[low] <=x && x<A[mid]) high=mid-1;
                else low=mid+1;
            }
            else if(A[mid] < A[low])
            {
                if(A[mid] < x && x<=A[high]) low=mid+1;
                else high=mid-1;
            }
            else
                low++;//不能logn的原因
        }
        return 0;
    }
};
