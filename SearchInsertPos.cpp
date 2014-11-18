class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        auto it=lower_bound(A,A+n,target);
        return it-A;
    }
};