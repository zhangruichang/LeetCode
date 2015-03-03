class Solution {
public:
    int searchInsert(int A[], int n, int x) {//range, 
        int low=0, high=n-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(A[mid] == x) return mid;//found
            else if(A[mid] < x) low=mid+1;
            else high=mid-1;
        }
        return low;//not found, high+1==low, low must be the inorder pos to be inserted
    }
};